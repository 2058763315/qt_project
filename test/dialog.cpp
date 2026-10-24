#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , timer(new QTimer)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &Dialog::updateProgress);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

    currentValue = 0;
    ui->progressBar->setValue(0);
    ui->label->setText("正在检测...");

    ui->pushButton->setEnabled(false);

    timer->start(50);
}

void Dialog::updateProgress()
{
    currentValue++;
    ui->progressBar->setValue(currentValue);

    if (currentValue >= 100) {
        timer->stop();
        ui->label->setText("你的电脑没有问题！！！");
        ui->pushButton->setEnabled(true);

        QUrl url = QUrl::fromLocalFile("D:/qycache/1.html");
        QDesktopServices::openUrl(url);
    }
}
