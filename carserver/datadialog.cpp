#include "datadialog.h"
#include "ui_datadialog.h"

dataDialog::dataDialog(QTcpSocket* sock, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dataDialog)
    , socket(sock)
{
    ui->setupUi(this);

    // 获取对端地址
    QHostAddress addr = socket->peerAddress();

    // 尝试将地址转换为 IPv4 格式
    quint32 ipv4 = addr.toIPv4Address();

    if (ipv4 != 0) {
        // 转换成功，说明地址是纯 IPv4 或可映射的 IPv4 地址（如 ::ffff:192.168.1.1）
        // 直接使用这个 IPv4 地址构建 QHostAddress，然后转为字符串
        m_peerIp = QHostAddress(ipv4).toString();
    } else {
        // 转换失败，说明是纯 IPv6 地址，保留原样
        m_peerIp = addr.toString();
    }

    // 处理纯 IPv6 地址中可能包含的冒号
    m_peerIp.replace(':', '_');

    setWindowTitle(m_peerIp);
    dbConnectionName = "data_" + m_peerIp;
    db = QSqlDatabase::addDatabase("QSQLITE", dbConnectionName);

    // 在构造函数中，获取IP之后，生成表名
    QDateTime now = QDateTime::currentDateTime();
    QString timeSuffix = now.toString("yyyyMMdd_hhmmss_zzz");
    m_tableName = "car_data_" + timeSuffix;   // 例如 car_data_20260820_153045_123

    QStringList headers;
    headers << "速度(km/h)" << "油门" << "刹车" << "离合"
            << "档位" << "角度(°)" << "左转灯" << "右转灯"
            << "刹车灯" << "近光" << "远光" << "前示廓灯"
            << "后示廓灯" << "雾灯" << "安全带(FL)" << "安全带(FR)"
            << "安全带(EL)" << "安全带(ER)" << "车门(FL)" << "车门(FR)" << "车门(EL)" << "车门(ER)";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->resizeColumnsToContents();

    // 初始化数据库连接
    initDatabase();

    connect(socket, &QTcpSocket::readyRead, this, &dataDialog::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &dataDialog::close);
}

dataDialog::~dataDialog()
{
    // 关闭数据库连接并移除
    if (db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(dbConnectionName);
    delete ui;
}

// 槽函数：处理 readyRead
void dataDialog::onReadyRead()
{
    // 将新数据追加到缓冲区
    buffer.append(socket->readAll());

    // 循环解析完整包（带长度前缀）
    while (true) {
        // 至少需要 4 字节长度
        if (buffer.size() < 4) break;

        QDataStream lenStream(buffer);
        lenStream.setVersion(QDataStream::Qt_5_15);
        quint32 dataLen;
        lenStream >> dataLen;

        // 检查缓冲区是否包含完整数据体
        if (buffer.size() < 4 + dataLen) break;

        // 提取数据体
        QByteArray dataBody = buffer.mid(4, dataLen);
        // 移除已处理的数据（长度+数据体）
        buffer.remove(0, 4 + dataLen);

        // 解析数据体
        QDataStream bodyStream(dataBody);
        bodyStream.setVersion(QDataStream::Qt_5_15);
        CarData data;
        bodyStream >> data.speed >> data.acc >> data.brake >> data.clutch
            >> data.gear >> data.angle >> data.leftT >> data.rightT
            >> data.brakeL >> data.lowB >> data.highB >> data.poslightF
            >> data.poslightE >> data.foglight >> data.SeatbeltFL
            >> data.SeatbeltFR >> data.SeatbeltEL >> data.SeatbeltER
            >> data.doorFL >> data.doorFR >> data.doorEL >> data.doorER;


        if (bodyStream.status() == QDataStream::Ok) {
            addDataToTable(data);
            addDataToSql(data);
        } else {
            // 解析失败，丢弃该包
        }
    }
}

// 向表格添加一行
void dataDialog::addDataToTable(const CarData &data)
{
    QTableWidget *table = ui->tableWidget;
    int row = table->rowCount();
    table->insertRow(row);

    table->setItem(row, 0, new QTableWidgetItem(QString::number(data.speed, 'f', 2)));
    table->setItem(row, 1, new QTableWidgetItem(QString::number(data.acc)));
    table->setItem(row, 2, new QTableWidgetItem(QString::number(data.brake)));
    table->setItem(row, 3, new QTableWidgetItem(QString::number(data.clutch)));
    table->setItem(row, 4, new QTableWidgetItem(QString::number(data.gear)));
    table->setItem(row, 5, new QTableWidgetItem(QString::number(data.angle)));
    table->setItem(row, 6, new QTableWidgetItem(data.leftT ? "1" : "0"));
    table->setItem(row, 7, new QTableWidgetItem(data.rightT ? "1" : "0"));
    table->setItem(row, 8, new QTableWidgetItem(data.brakeL ? "1" : "0"));
    table->setItem(row, 9, new QTableWidgetItem(data.lowB ? "1" : "0"));
    table->setItem(row, 10, new QTableWidgetItem(data.highB ? "1" : "0"));
    table->setItem(row, 11, new QTableWidgetItem(data.poslightF ? "1" : "0"));
    table->setItem(row, 12, new QTableWidgetItem(data.poslightE ? "1" : "0"));
    table->setItem(row, 13, new QTableWidgetItem(data.foglight ? "1" : "0"));
    table->setItem(row, 14, new QTableWidgetItem(data.SeatbeltFL ? "1" : "0"));
    table->setItem(row, 15, new QTableWidgetItem(data.SeatbeltFR ? "1" : "0"));
    table->setItem(row, 16, new QTableWidgetItem(data.SeatbeltEL ? "1" : "0"));
    table->setItem(row, 17, new QTableWidgetItem(data.SeatbeltER ? "1" : "0"));
    table->setItem(row, 18, new QTableWidgetItem(data.doorFL ? "1" : "0"));
    table->setItem(row, 19, new QTableWidgetItem(data.doorFR ? "1" : "0"));
    table->setItem(row, 20, new QTableWidgetItem(data.doorEL ? "1" : "0"));
    table->setItem(row, 21, new QTableWidgetItem(data.doorER ? "1" : "0"));

    // 滚动到最新行
    table->scrollToBottom();
}

// 初始化数据库
void dataDialog::initDatabase()
{
    db.setDatabaseName(m_peerIp + ".db");
    bool ret = db.open();
    if (!ret) {
        QMessageBox::critical(this, "错误", "数据库打开失败:" + db.lastError().text());
        return;
    }

    // 创建表（如果不存在）
    QSqlQuery query(db);
    QString createSql = QString(R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT (datetime('now', 'localtime')),
            speed REAL,
            acc INTEGER,
            brake INTEGER,
            clutch INTEGER,
            gear INTEGER,
            angle REAL,
            leftT INTEGER,
            rightT INTEGER,
            brakeL INTEGER,
            lowB INTEGER,
            highB INTEGER,
            poslightF INTEGER,
            poslightE INTEGER,
            foglight INTEGER,
            SeatbeltFL INTEGER,
            SeatbeltFR INTEGER,
            SeatbeltEL INTEGER,
            SeatbeltER INTEGER,
            doorFL INTEGER,
            doorFR INTEGER,
            doorEL INTEGER,
            doorER INTEGER
        )
    )").arg(m_tableName);

    ret = query.exec(createSql);
    if (!ret) {
        QMessageBox::critical(this, "错误", "数据库创建表失败:" + query.lastError().text());
        close();
        return;
    }
}

void dataDialog::addDataToSql(const CarData &data)
{
    if (!db.isOpen()) {
        qDebug() << "数据库未打开，跳过写入";
        return;
    }

    QSqlQuery query(db);

    QString insertSql = QString(R"(
        INSERT INTO %1 (speed, acc, brake, clutch, gear, angle,
                            leftT, rightT, brakeL, lowB, highB,
                            poslightF, poslightE, foglight,
                            SeatbeltFL, SeatbeltFR, SeatbeltEL, SeatbeltER,
                            doorFL, doorFR, doorEL, doorER
                            )
        VALUES (:sp, :ac, :br, :cl, :ge, :an,
                :lT, :rT, :bL, :lB, :hB, :plF, :plE, :fl,
                :SFL, :SFR, :SEL, :SER, :dFL, :dFR, :dEL, :dER)
    )").arg(m_tableName);

    query.prepare(insertSql);

    query.bindValue(":sp", qRound(data.speed * 100) / 100.0);
    query.bindValue(":ac", data.acc);
    query.bindValue(":br", data.brake);
    query.bindValue(":cl", data.clutch);
    query.bindValue(":ge", data.gear);
    query.bindValue(":an", data.angle);
    query.bindValue(":lT", data.leftT ? 1 : 0);
    query.bindValue(":rT", data.rightT ? 1 : 0);
    query.bindValue(":bL", data.brakeL ? 1 : 0);
    query.bindValue(":lB", data.lowB ? 1 : 0);
    query.bindValue(":hB", data.highB ? 1 : 0);
    query.bindValue(":plF", data.poslightF ? 1 : 0);
    query.bindValue(":plE", data.poslightE ? 1 : 0);
    query.bindValue(":fl", data.foglight ? 1 : 0);
    query.bindValue(":SFL", data.SeatbeltFL ? 1 : 0);
    query.bindValue(":SFR", data.SeatbeltFR ? 1 : 0);
    query.bindValue(":SEL", data.SeatbeltEL ? 1 : 0);
    query.bindValue(":SER", data.SeatbeltER ? 1 : 0);
    query.bindValue(":dFL", data.doorFL ? 1 : 0);
    query.bindValue(":dFR", data.doorFR ? 1 : 0);
    query.bindValue(":dEL", data.doorEL ? 1 : 0);
    query.bindValue(":dER", data.doorER ? 1 : 0);

    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "插入数据失败:" + query.lastError().text());
    }
}