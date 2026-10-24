#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QmessageBox>
#include "foxeventfilter.h"
#include <cstdlib>
#include <ctime>
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
    void on_pushButton_clicked();

    void moveSigSlot(QPushButton* pbutton);

private:
    Ui::Widget *ui;

    foxEventFilter* fFilter;
};
#endif // WIDGET_H
