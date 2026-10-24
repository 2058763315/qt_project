#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_serial(new QSerialPort(this))
    , m_statusTimer(new QTimer(this))
{
    ui->setupUi(this);

    m_serial->setPortName("COM3");   // 根据实际串口设备修改
    m_serial->setBaudRate(9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    connect(m_serial, &QSerialPort::readyRead,
            this, &Widget::onSerialReadyRead);

    m_statusTimer->setSingleShot(true);   // 只触发一次
    connect(m_statusTimer, &QTimer::timeout, this, [this]() {
        setStatusText("未连接", "");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setStatusText(const QString &text, const QString &color)
{
    ui->label_5->setText(text);
    if (color.isEmpty())
        ui->label_5->setStyleSheet("");                       // 恢复默认
    else
        ui->label_5->setStyleSheet(QString("color: %1;").arg(color));
}

void Widget::on_pushButton_clicked()
{
    m_statusTimer->stop();     // 取消上一次的"回退"定时器

    /* ---- 当前已连接 → 执行断开 ---- */
    if (m_serial->isOpen()) {
        m_serial->close();
        ui->pushButton->setText("连接");
        setStatusText("未连接", "");
        return;
    }

    /* ---- 当前未连接 → 尝试打开 ---- */
    if (m_serial->open(QIODevice::ReadWrite)) {
        ui->pushButton->setText("断开");
        setStatusText("连接成功", "green");       // 成功：绿色
    } else {
        setStatusText("连接失败", "red");         // 失败：红色
        m_statusTimer->start(3000);               // 3 秒后恢复"未连接"
    }
}

void Widget::onSerialReadyRead()
{
    m_rxBuffer.append(m_serial->readAll());

    if (m_rxBuffer.size() > 8192) {     // 防异常数据撑爆
        m_rxBuffer.clear();
        return;
    }

    /* 按 '\n' 拆行，解决粘包/半包 */
    int idx;
    while ((idx = m_rxBuffer.indexOf('\n')) >= 0) {
        QByteArray line = m_rxBuffer.left(idx).trimmed();
        m_rxBuffer.remove(0, idx + 1);
        if (!line.isEmpty())
            handleLine(line);
    }
}

void Widget::sendCommand(const QString &cmd)
{
    if (!m_serial->isOpen()) {
        QMessageBox::warning(this, "错误", "串口未打开");
        return;
    }
    QByteArray data = cmd.toUtf8();
    qint64 written = m_serial->write(data);
    qDebug() << "发送:" << data << " 写入字节:" << written;
}

void Widget::handleLine(const QByteArray &line)
{
    static const QRegularExpression re(
        QStringLiteral("X=(-?\\d+)\\s+Y=(-?\\d+)"));

    const QString s = QString::fromLatin1(line);
    const QRegularExpressionMatch m = re.match(s);
    if (!m.hasMatch()) {
        qDebug() << "无法解析:" << s;
        return;
    }

    const int x = m.captured(1).toInt();
    const int y = m.captured(2).toInt();

    /* 更新两个文本框 */
    ui->label->setText(QString::number(x));
    ui->label_2->setText(QString::number(y));
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        sendCommand("GPIO24=1\n");
    }
    else
    {
        sendCommand("GPIO24=0\n");
    }
}

void Widget::on_checkBox_2_toggled(bool checked)
{
    //屏幕背光
    if (checked)
    {
        sendCommand("BACKLIGHT=ON\n");
    }
    else
    {
        sendCommand("BACKLIGHT=OFF\n");
    }
}

// 亮度调节
void Widget::on_horizontalSlider_valueChanged(int value)
{
    sendCommand(QString("BRIGHTNESS=%1\n").arg(value));
}


