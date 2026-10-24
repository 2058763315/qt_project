#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , playList({"D:/Qt_project/tmp/img/1.png",
                "D:/Qt_project/tmp/img/2.png",
                "D:/Qt_project/tmp/img/3.png",
                "D:/Qt_project/tmp/img/4.png",
                "D:/Qt_project/tmp/img/5.png"
      })
    , pos(0)
{
    ui->setupUi(this);
    this->setFixedSize(890, 590);
    QPixmap pmap;
    pmap.load(playList[pos]);
    ui->label->setPixmap(pmap);

    ui->pushButton_stop->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent* event)
{
    if (event->timerId() == timerID)
    {
        on_pushButton_next_clicked();
    }
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat() || playFlag)
    {
        return;
    }

    if(event->modifiers() == Qt::NoModifier)
    {
        if(event->key() == Qt::Key_Left)
        {
            on_pushButton_prev_clicked();
        }
        else if(event->key() == Qt::Key_Right)
        {
            on_pushButton_next_clicked();
        }
    }
}

void Widget::closeEvent(QCloseEvent* event)
{
    if(playFlag)
    {
        auto ret = QMessageBox::question(this, "大胆", "谁给你的胆子关闭的");
        if(ret == QMessageBox::No)
        {
            event->ignore();
        }
    }
}

void Widget::on_pushButton_prev_clicked()
{
    pos = (pos - 1 + playList.size()) % playList.size();

    QPixmap pmap;
    pmap.load(playList[pos]);
    ui->label->setPixmap(pmap);
}

void Widget::on_pushButton_next_clicked()
{
    pos = (pos + 1) % playList.size();

    QPixmap pmap;
    pmap.load(playList[pos]);
    ui->label->setPixmap(pmap);
}

void Widget::on_pushButton_auto_clicked()
{
    timerID = startTimer(2000);

    playFlag = true;

    ui->pushButton_auto->setVisible(false);
    ui->pushButton_stop->setVisible(true);

    ui->pushButton_next->setEnabled(false);
    ui->pushButton_prev->setEnabled(false);
}

void Widget::on_pushButton_stop_clicked()
{
    killTimer(timerID);

    playFlag = false;

    ui->pushButton_stop->setVisible(false);
    ui->pushButton_auto->setVisible(true);

    ui->pushButton_next->setEnabled(true);
    ui->pushButton_prev->setEnabled(true);
}

