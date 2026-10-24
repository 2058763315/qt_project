#include "widget.h"
#include "ui_widget.h"
#include "proconthread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMutex mutex;
    int src = 0;
    ProductorThread pth(mutex, src, ui->spinBox_Source->value());
    pth.start();
    int threadnum = ui->spinBox_Count->value();
    QVector<ConsumerThread*> cth(threadnum);
    pth.wait();
    for (auto& e : cth)
    {
        e = new ConsumerThread(mutex, src);
        e->start();
    }
    for (int i = 0; i < cth.size(); i++)
    {
        cth[i]->wait();
        ui->listWidget->addItem(QString("%1 : %2").arg(i, 2).arg(cth[i]->getCount()));
    }
    ui->listWidget->addItem("");
    ui->listWidget->scrollToBottom();
}

