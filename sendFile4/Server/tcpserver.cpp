#include "tcpserver.h"

tcpServer::tcpServer(QObject *parent)
    : QObject{parent}
{
    //创建tcpserver对象
    tcpserver = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);
    serverInit();
}

void tcpServer::serverInit()
{
    //监听本地8888端口
    if (!tcpserver->listen(QHostAddress::Any, 8888))
    {
        //监听失败
        qDebug() << QString("Server could not start!");
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    }
    else{
        //监听成功
        qDebug() << QString("Server started!");
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        //有新的客户端连接请求信号
        connect(tcpserver, &QTcpServer::newConnection, [=](){
            tcpSocket = tcpserver->nextPendingConnection();
            qDebug() << QString("New client connected!");
            qDebug()<<tcpSocket->peerAddress().toString() + ":" + QString::number(tcpSocket->peerPort());
            //tcpSocket有数据可读的信号
            connect(tcpSocket, &QTcpSocket::readyRead, [=](){
                QByteArray buffer = tcpSocket->readAll();
                qDebug() << QString("Received data from client: ") + QString(buffer);
            });
            //tcpSocket断开连接的信号
            connect(tcpSocket, &QTcpSocket::disconnected, [=](){
                qDebug() << QString("Client disconnected!");
                qDebug()<<tcpSocket->peerAddress().toString() + ":" + QString::number(tcpSocket->peerPort());
                tcpSocket->deleteLater();
            });
        });
    }
    
}
