#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
class tcpServer : public QObject
{
    Q_OBJECT
public:
    explicit tcpServer(QObject *parent = nullptr);
private:
    QTcpServer* tcpserver;
    QTcpSocket* tcpSocket;
    void serverInit();

signals:
};

#endif // TCPSERVER_H
