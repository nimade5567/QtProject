#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QFile>
class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
private:
    QTcpServer* tcpServer=new QTcpServer(this);
    QTcpSocket* tcpSocket=new QTcpSocket(this);

signals:
};

#endif // SERVER_H
