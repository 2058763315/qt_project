#include "widget.h"
#include "ui_widget.h"
#include "datadialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , server(new QTcpServer)
{
    ui->setupUi(this);

    server->listen(QHostAddress::Any, 10086);

    connect(server, &QTcpServer::newConnection, this, &Widget::newConnectionSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnectionSlot()
{
    QTcpSocket* socket = server->nextPendingConnection();
    if(socket == nullptr)
    {
        QMessageBox::critical(this, "错误", "连接超时");
        return;
    }

    dataDialog* data = new dataDialog(socket);
    data->show();
}
