#include "client.h"

client::client(QObject *parent)
    : QObject{parent}
{
    tcpSocket->connectToHost("127.0.0.1",8080);
    connect(tcpSocket,&QTcpSocket::connected,[=]{
        qDebug() << "Connected to server!";
        sendFile();
    });
}

inline void client::sendFile()
{
    QFile sendFile(filePath);
    if(sendFile.open(QIODevice::ReadOnly)) {
        QByteArray fileData;
        fileData="send filename:"+sendFile.fileName().toUtf8()+"send filecontent:"+sendFile.readAll();
        tcpSocket->write(fileData);
        tcpSocket->flush();
        sendFile.close();
        qDebug() << "File sent!";
    } else {
        qDebug() << "Failed to open file!";
    }
}
