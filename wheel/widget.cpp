#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , scene(new QGraphicsScene)
    , group(new QGraphicsItemGroup)

{
    ui->setupUi(this);

    ui->graphicsView->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 200, 200);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing |
                                    QPainter::TextAntialiasing |
                                    QPainter::SmoothPixmapTransform);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setBackgroundBrush(QColor(240, 240, 240));

    QPixmap pm(":/wheel.png");
    QPixmap scaled = pm.scaled(200, 200, Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(scaled);
    pixItem->setPos(-100, -100);
    pixItem->setFlags(QGraphicsItem::ItemIsMovable |
                      QGraphicsItem::ItemIsSelectable);

    group->addToGroup(pixItem);
    group->setPos(100, 100);
    scene->addItem(group);

    lastDialValue = ui->dial->value();
    totalAngle = 0.0;
    blocked = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_dial_valueChanged(int value)
{
    int delta = value - lastDialValue;
    const int minVal = -180;
    const int maxVal = 180;
    const int range = maxVal - minVal;

    if (delta > 180) {
        delta -= range;
    } else if (delta < -180) {
        delta += range;
    }

    double newTotal = totalAngle + delta;

    if ((newTotal > 540.0 && delta > 0) || (newTotal < -540.0 && delta < 0)) {
        ui->dial->blockSignals(true);
        ui->dial->setValue(lastDialValue);
        ui->dial->blockSignals(false);
        return;
    }

    totalAngle = newTotal;
    lastDialValue = value;

    group->setRotation(value);

    blocked = (totalAngle >= 540.0 || totalAngle <= -540.0);
}