#include "tcpclient.h"

tcpClient::tcpClient(QObject *parent)
    : QObject{parent}
{
    tcpSocket = new QTcpSocket(this);
    clientInit();
}
//客户端初始化
void tcpClient::clientInit()
{
    //连接服务器
    tcpSocket->connectToHost("127.0.0.1", 8888);
    //等待连接成功 10000毫秒
    if(tcpSocket->waitForConnected(10000))
    {
        qDebug() << QString("Client connected to server!");
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        //tcpSocket有数据可读的信号
        QByteArray buffer1=createHeader(FILE_TYPE,0,0);
        qint32 result=(static_cast<qint8>(buffer1[0]))    |
                      (static_cast<qint8>(buffer1[1])<<8) |
                      (static_cast<qint8>(buffer1[2])<<16)|
                      (static_cast<qint8>(buffer1[3])<<24);
        qDebug()<<QString::number(result,16);
        connect(tcpSocket, &QTcpSocket::readyRead, [=]()
        {
            //读取服务器发送的数据储存到缓冲区
            buffer.append(tcpSocket->readAll());
            qDebug() << QString("Received data from server: ") + QString(buffer);
            qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        });
        //tcpSocket断开连接的信号
        connect(tcpSocket, &QTcpSocket::disconnected, [=]()
        {
            qDebug() << QString("Disconnected from server!");
            qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            tcpSocket->deleteLater();
            QCoreApplication::quit();
        });
    }
    else
    {
        //连接失败
        qDebug() << QString("Client connection to server failed!");
        qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        qDebug() << tcpSocket->errorString();
    }
}
//创建数据包头部
QByteArray tcpClient::createHeader(const qint16 & fileType, const qint32 & dataSize, const qint16 & checkSum)
{
    QByteArray header;
    header.resize(HEADER_SIZE+4); //预留4字节用于填充
    *((qint32*)header.data()) = MAGIC_BUMBER; //数据包起始标志
    *((qint16*)(header.data() + 4)) = PROTOCOl_VERSION; //协议版本号
    *((qint16*)(header.data() + 6)) = fileType; //文件类型
    *((qint32*)(header.data() + 8)) = dataSize; //数据大小
    *((qint16*)(header.data() + 12)) = checkSum; //校验和
    memset(header.data() + HEADER_SIZE, 0, 2); //头部填充0
    return header;
}
