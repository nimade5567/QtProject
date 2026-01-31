//
// Created by jyh17353790598@163.com on 2026/1/29.
//

#include "../include/tcpServer.h"

tcpServer::tcpServer(QObject *parent):QObject(parent) {

    //开启端口监听
    if (!Server->listen(QHostAddress::Any,8888)) {
        qDebug()<<"tcpServer listening failed";
    }else {
        qDebug()<<"tcpServer listening successfully";
        connect(Server,&QTcpServer::newConnection,[=] {
            qDebug()<<"tcpServer new connection established";\
            QTcpSocket* socket=new QTcpSocket(this);
            socket=Server->nextPendingConnection();
            qDebug()<<"IP地址:"<<socket->peerAddress().toString()<<"|端口号:"<<socket->peerPort();
            sockets.append(socket);
            connect(socket,&QTcpSocket::readyRead,[=] {
                QString msg=socket->readAll();
                qDebug()<<"收到IP地址为:"<<socket->peerAddress().toString()<<"|端口号:"<<socket->peerPort()<<"信息为:"<<msg;

            });
        });
    }
}
