//
// Created by jyh17353790598@163.com on 2026/1/29.
//

#ifndef SERVER_TCPSERVER_H
#define SERVER_TCPSERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QList>
#include <QString>
class tcpServer :public QObject{
    Q_OBJECT
    public:
        explicit tcpServer(QObject *parent = nullptr);
    private:
        QTcpServer* Server=new QTcpServer(this);
        QList<QTcpSocket*> sockets;
};


#endif //SERVER_TCPSERVER_H