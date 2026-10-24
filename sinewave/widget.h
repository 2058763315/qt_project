#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainterPath>
#include <QPainter>
#include <QPixMap>
#include <Qvector>
#include <cmath>
#include <QTimerEvent>

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

    void timerEvent(QTimerEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::Widget *ui;

    QVector<double> data;
    double val = 0;
};
#endif // WIDGET_H
