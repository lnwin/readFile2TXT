#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <qthread.h>
#include <QFileDialog>
#include <QDebug>
class readThread :public QThread
{
    Q_OBJECT
 public:
    readThread();
QStringList Tfile_list;
    void run() override;
 public slots:
    void receiveFileNames(QStringList);
signals:
    void sendChangeFile2M(QString);
};

#endif // READTHREAD_H
