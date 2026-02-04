#include "server.h"

server::server(QObject *parent)
    : QObject{parent}
{
    //打开服务器监听端口
    if(!tcpServer->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started!";
    }
    connect(tcpServer, &QTcpServer::newConnection, [=]() {
        //获取客户端连接
        tcpSocket = tcpServer->nextPendingConnection();
        connect(tcpSocket, &QTcpSocket::readyRead, [=]() {
            QByteArray buffer = tcpSocket->readAll();
            qDebug() << "Received data from client:" << buffer;
            QByteArray name=buffer.mid(buffer.indexOf("send filename:")+14,buffer.indexOf("send filecontent:")-14);
            QByteArray content=buffer.mid(buffer.indexOf("send filecontent:")+17);
            qDebug() << "Filename:" << name;
            qDebug() << "File content:" << content;
            QFile file("/Users/jyh/Desktop/QtProject/sendFile/Server/test.txt");
            if(file.open(QIODevice::WriteOnly)) {
                file.write(content);
                file.close();
                qDebug() << "File saved successfully!";
            } else {
                qDebug() << "Failed to save file!";
            }

        });
        qDebug() << tcpSocket->peerAddress().toString() << " connected.";
        qDebug() << "Client connected!";
    });
}
