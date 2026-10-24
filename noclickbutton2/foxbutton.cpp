#include "foxbutton.h"

foxButton::foxButton(QWidget *parent)
    : QPushButton{parent}
{
    setMouseTracking(true); //直接用代码设置mouseTracking
}

void foxButton::mouseMoveEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    emit moveSig(this); //触发事件直接发射信号
}