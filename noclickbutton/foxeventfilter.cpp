#include "foxeventfilter.h"

foxEventFilter::foxEventFilter(QObject *parent)
    : QObject{parent}
{}

bool foxEventFilter::eventFilter(QObject* obj, QEvent* event){
    //判断事件类型
    if (event->type() == QEvent::MouseMove)
    {
        //判断控件类型，可以用dynamic_cast，也可以用Qt提供的qobject_cast
        QPushButton* pbutton = dynamic_cast<QPushButton*>(obj);
        if (pbutton) //判断成功
        {
            emit moveSig(pbutton); //执行功能
            return true; //返回true表示过滤掉了
        }
    }
    return QObject::eventFilter(obj, event); //其余情况调用父类函数处理
}