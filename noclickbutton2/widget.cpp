#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &foxButton::moveSig, this, &Widget::moveSigSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "哎呀", "居然被点到了！");
}

void Widget::moveSigSlot(foxButton* pbutton)
{
    int widht = size().height();
    int butht = pbutton->size().height();

    int widwd = size().height();
    int butwd = pbutton->size().height();

    int x = pbutton->pos().x();
    int y = pbutton->pos().y();

    int randx, randy;
    int i;
    for(i = 0;i < 10;i++)
    {
        randx = rand() % (widwd - butwd);
        randy = rand() % (widht - butht);
        if(!(abs(randx - x) < butwd && abs(randy - y) < butht))
        {
            break;
        }
    }
    pbutton->move(randx, randy);
}