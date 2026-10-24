#ifndef FOXBUTTON_H
#define FOXBUTTON_H

#include <QPushButton>

class foxButton : public QPushButton
{
    Q_OBJECT
public:
    explicit foxButton(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent* event);
signals:
    void moveSig(foxButton* pbutton);
};

#endif // FOXBUTTON_H
