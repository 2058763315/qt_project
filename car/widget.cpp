#include "widget.h"
#include "ui_widget.h"

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

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::TextAntialiasing |
                           QPainter::SmoothPixmapTransform);

    QPixmap pm(":/1.png");  //设置背景图片
                    //前四个参数给定了一个矩形，图片会在这个矩形范围内缩放
    painter.drawPixmap(0, 0, width(), height(), pm);

    QPen textPenrect;
    textPenrect.setColor(QColor(214, 173, 214));
    painter.setPen(textPenrect);

    QFont font("经典繁方篆", 100);
    painter.setFont(font);
    QRect textRect(0, 0, width(), height() / 3); //设置文字矩形框
    painter.drawText(textRect, Qt::AlignCenter, "国之印信在此，还不速速跪下");

    //调整默认位置
    painter.translate(width() / 2, height() / 2);
    //调整坐标系角度
    painter.rotate(angle);

    //设置正三角形的各种属性
    double side = qMin(height(), width()) * 0.8;
    double half = side / 2.0;
    double height = half * sqrt(3);
    double radius = height / 3;

    QPainterPath trianglePath; //绘制正三角形
    trianglePath.moveTo(0, -radius * 2);
    trianglePath.lineTo(-half, radius);
    trianglePath.lineTo(half, radius);
    trianglePath.closeSubpath();

    QPen pentri(QColor(214, 173, 214));
    pentri.setWidth(5);

    QBrush brushtri(QColor(199, 235, 250));

    painter.setPen(pentri);
    painter.setBrush(brushtri);

    painter.drawPath(trianglePath); //画三角

    QPen pencir(QColor(0, 255, 0));
    pencir.setWidth(5);

    QBrush brushcir(QColor(255, 128, 255));
    painter.setPen(pencir);
    painter.setBrush(brushcir);

    painter.drawEllipse(QPointF(0, 0), radius, radius); //画圆

    QPen penrect(QColor(0, 255, 0));
    penrect.setWidth(5);

    painter.setPen(penrect);
    painter.drawRect(0, -radius * 2, 0, height); //用一个宽度为0的矩形来表示直线
}

void Widget::on_dial_valueChanged(int value)
{
    angle = value;
    update(); //用一个Dial让图片跟着Dial转
}