#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <cmath>

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
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;

    int angle;
};
#endif // WIDGET_H
