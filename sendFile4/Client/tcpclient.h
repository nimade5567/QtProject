#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include <QCoreApplication>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QFileInfo>
const qint32 MAGIC_BUMBER = 0x76; //数据包起始标志
const qint16 PROTOCOl_VERSION = 1; //协议版本号
const qint16 HEADER_SIZE = 14; //数据包头部大小 
const qint16 FILE_TYPE=0; //文件类型
class tcpClient : public QObject
{
    Q_OBJECT
public:
    explicit tcpClient(QObject *parent = nullptr);
private:
    QTcpSocket* tcpSocket;
    QByteArray buffer;//接收缓冲区数据
    void clientInit();
    QByteArray createHeader(const qint16 &fileType,const qint32 &dataSize,const qint16 &checkSum); //创建数据包头部
signals:
};

#endif // TCPCLIENT_H
