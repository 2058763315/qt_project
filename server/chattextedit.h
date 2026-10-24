#ifndef CHATTEXTEDIT_H
#define CHATTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>

class chatTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit chatTextEdit(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent* event);
signals:
    void sendSig();
};

#endif // CHATTEXTEDIT_H
