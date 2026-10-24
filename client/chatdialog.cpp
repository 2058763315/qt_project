#include "chatdialog.h"
#include "ui_chatdialog.h"

chatDialog::chatDialog(QTcpSocket* sock, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatDialog)
    , socket(sock)
{
    ui->setupUi(this);

    setWindowTitle(socket->peerAddress().toString());

    connect(socket, &QTcpSocket::readyRead, this, &chatDialog::readyReadSlot);
    connect(socket, &QTcpSocket::disconnected, this, &chatDialog::disconnectSlot);
    connect(ui->textEdit, &chatTextEdit::sendSig, this, &chatDialog::on_pushButtonSend_clicked);
}

chatDialog::~chatDialog()
{
    delete ui;
}

void chatDialog::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event);
    closeFlag = true;
    socket->close();
}

void chatDialog::readyReadSlot()
{
    ui->listWidget->addItem("服务器：");
    ui->listWidget->addItem(socket->readAll());
    ui->listWidget->scrollToBottom();
}

void chatDialog::disconnectSlot()
{
    if(closeFlag)
    {
        return;
    }

    auto ret = QMessageBox::question(this, "询问", "对方已断开连接，是否关闭窗口？");
    if(ret == QMessageBox::Yes)
    {
        close();
        return;
    }

    closeFlag = true;
}

void chatDialog::on_pushButtonClear_clicked()
{
    ui->textEdit->clear();
}


void chatDialog::on_pushButtonSend_clicked()
{
    if(closeFlag)
    {
        QMessageBox::warning(this, "警告", "连接已断开，无法发送数据！");
        return;
    }

    QString data = ui->textEdit->toPlainText();
    socket->write(data.toUtf8());
    ui->listWidget->addItem("客户端：");
    ui->listWidget->addItem(data);
    ui->listWidget->scrollToBottom();
    ui->textEdit->clear();
}