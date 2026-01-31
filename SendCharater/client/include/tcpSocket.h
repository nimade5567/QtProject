//
// Created by jyh17353790598@163.com on 2026/1/29.
//

#ifndef CLIENT_TCPSOCKET_H
#define CLIENT_TCPSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
class tcpSocket :public QObject{
    Q_OBJECT
    public:
        explicit tcpSocket(QObject *parent = nullptr);
    private:
        QTcpSocket* socket=new QTcpSocket(this);
};


#endif //CLIENT_TCPSOCKET_H