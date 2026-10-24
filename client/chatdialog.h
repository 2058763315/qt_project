#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QMEssageBox>

namespace Ui {
class chatDialog;
}

class chatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chatDialog(QTcpSocket* socket, QWidget *parent = nullptr);
    ~chatDialog();

    void closeEvent(QCloseEvent* event);

private slots:
    void on_pushButtonClear_clicked();
    void on_pushButtonSend_clicked();

private:
    void readyReadSlot();
    void disconnectSlot();

private:
    Ui::chatDialog *ui;

    QTcpSocket* socket;

    bool closeFlag = false;
};

#endif // CHATDIALOG_H
