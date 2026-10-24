#include "chattextedit.h"

chatTextEdit::chatTextEdit(QWidget *parent)
    : QTextEdit{parent}
{}

void chatTextEdit::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat())
    {
        return;
    }

    if(event->modifiers() == Qt::NoModifier)
    {
        if(event->key() == Qt::Key_Return)
        {
            emit sendSig();
            return;
        }
    }
    else if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_Return)
        {
            append("");
            return;
        }
    }
    QTextEdit::keyPressEvent(event);
}