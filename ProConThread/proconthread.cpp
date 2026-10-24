#include "proconthread.h"

ProductorThread::ProductorThread(QMutex& m, int& s, int n, QObject *parent)
    : QThread{parent}
    , mutex(m)
    , src(s)
    , num(n)
{}

void ProductorThread::run()
{
    mutex.lock();
    src += num;
    mutex.unlock();
}

ConsumerThread::ConsumerThread(QMutex& m, int& s, QObject *parent)
    : QThread{parent}
    , mutex(m)
    , src(s)
{}

void ConsumerThread::run()
{
    count = 0;
    while(src > 0)
    {
        mutex.lock();
        if(src > 0)
        {
            src--;
            count++;
        }
        mutex.unlock();
    }
}

int ConsumerThread::getCount()
{
    return count;
}