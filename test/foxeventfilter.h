#ifndef FOXEVENTFILTER_H
#define FOXEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QPushButton>

class foxEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit foxEventFilter(QObject *parent = nullptr);

    bool eventFilter(QObject* obj, QEvent* event);
signals:
    void moveSig(QPushButton* pbutton);
};

#endif // FOXEVENTFILTER_H
