#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QTableWidget>
#include <QByteArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class dataDialog;
}

struct CarData {
    double speed;
    int acc;
    int brake;
    int clutch;
    int gear;
    int angle;
    bool leftT;
    bool rightT;
    bool brakeL;
    bool lowB;
    bool highB;

    bool foglight;
    bool poslightF;
    bool poslightE;

    bool SeatbeltFL;
    bool SeatbeltFR;
    bool SeatbeltEL;
    bool SeatbeltER;

    bool doorFL;
    bool doorFR;
    bool doorEL;
    bool doorER;
};

class dataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dataDialog(QTcpSocket* sock, QWidget *parent = nullptr);
    ~dataDialog();

private slots:
    void onReadyRead();   // 接收数据槽

private:
    void initDatabase();

    void addDataToTable(const CarData &data);
    void addDataToSql(const CarData &data);

private:
    Ui::dataDialog *ui;

    QTcpSocket *socket;
    QByteArray buffer;    // 粘包处理缓冲区（可选，推荐）

    QString m_peerIp;            // 存储客户端IP
    QSqlDatabase db;
    QString m_tableName;
    QString dbConnectionName;
};

#endif // DATADIALOG_H
