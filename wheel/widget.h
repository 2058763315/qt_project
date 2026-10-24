#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPathItem>
#include <QGraphicsEllipseItem>
#include <QPainterPath>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void on_dial_valueChanged(int value);

private:
    Ui::Widget *ui;

    QGraphicsScene* scene;
    QGraphicsItemGroup* group;

    int lastDialValue;          // 上一次的 dial 值（-180~180）
    double totalAngle;          // 累计净旋转角度（单位：度）
    bool blocked;

};
#endif // WIDGET_H
