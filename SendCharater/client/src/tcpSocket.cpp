//
// Created by jyh17353790598@163.com on 2026/1/29.
//

#include "../include/tcpSocket.h"

tcpSocket::tcpSocket(QObject *parent):QObject(parent) {
    socket->connectToHost("127.0.0.1", 8888);
    connect(socket,&QTcpSocket::connected,[&] {
        qDebug()<<"connected";
        qDebug()<<socket->peerAddress().toString();
        socket->write("你好");
    });
}
