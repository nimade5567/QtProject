#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QByteArray>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);
private:
//定义QTcpSocket对象
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    QString filePath="/Users/jyh/Desktop/QtProject/sendFile/Client/test.txt";
    inline void sendFile();
signals:
};

#endif // CLIENT_H
