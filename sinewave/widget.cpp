#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    startTimer(50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    double newValue = 200 + 100 * std::sin(val);
    data.append(newValue);
    val += 0.2;

    if(data.size() >= 50)
    {
        data.removeFirst();
    }

    update();
}

void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    if(data.isEmpty())
    {
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //绘制辅助虚线
    painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));
    int i;
    for(i = 1; i <= height() / 100; i++)
    {
        painter.drawLine(0, i * 100, width(), i * 100);
    }

    QPainterPath path;

    //绘制正弦曲线
    int stepx = width() / 50;
    int x = 0, y = height() - (int)data[0];
    path.moveTo(x, y);
    for(i = 1;i < data.size();i++)
    {
        x = i * stepx;
        y = height() - (int)data[i];
        path.lineTo(x, y);
    }
    QPen pen(QColor(0, 255, 0));
    pen.setWidth(5);
    pen.setCapStyle(Qt::RoundCap);   //在线段两端加上一个半圆使其圆润
    pen.setJoinStyle(Qt::RoundJoin); //在拐角处磨掉棱角使其圆润
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawPath(path);

    //绘制末端的小圆点来表示当前数值
    int lastx = (data.size() - 1) * stepx;
    int lasty = height() - (int)data.last();
    painter.setBrush(QColor(255, 0, 0));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QPointF(lastx, lasty), 5, 5);
}