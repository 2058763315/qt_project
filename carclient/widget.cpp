#include "widget.h"
#include "ui_widget.h"
#include "carwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , socket(new QTcpSocket)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    socket->connectToHost(ui->lineEdit_IP->text(), ui->lineEdit_PORT->text().toUShort());
    bool ret = socket->waitForConnected(5000);
    if (!ret)
    {
        QMessageBox::critical(this, "错误", "连接失败！");
        return;
    }
    carWindow* car = new carWindow(socket);
    car->show();
    hide();
}