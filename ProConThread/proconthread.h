#ifndef PROCONTHREAD_H
#define PROCONTHREAD_H

#include <QThread>
#include <QMutex>

class ProductorThread : public QThread
{
    Q_OBJECT
public:
    explicit ProductorThread(QMutex& m, int& s, int n, QObject *parent = nullptr);
    void run();
signals:

private:
    QMutex& mutex;
    int& src;
    int num;
};

class ConsumerThread : public QThread
{
    Q_OBJECT
public:
    explicit ConsumerThread(QMutex& m, int& s, QObject *parent = nullptr);
    void run();
    int getCount();
signals:

private:
    QMutex& mutex;
    int& src;
    int count = 0;
};
#endif // PROCONTHREAD_H
