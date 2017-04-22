#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);


signals:

public slots:
protected:
    void run();

};

#endif // THREAD_H
