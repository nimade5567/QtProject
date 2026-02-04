#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化客户端
    initClient();
}

Widget::~Widget()
{
    delete ui;
}
//内联函数
    //初始化客户端
inline void Widget::initClient(){
    tcpSocket->connectToHost("127.0.0.1",8888);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        qDebug()<<"与服务器连接成功";
    });
}
    //发送数据
inline void Widget::sendData(){
    sendFile->setFileName(this->fileName);
    if(!sendFile->open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败";
        return;
    }else{
        qDebug()<<"文件打开成功";
    }
    QByteArray sendFileName=this->fileName.toUtf8();
    QByteArray fileData=sendFile->readAll();
    QByteArray sendData="send File:"+sendFileName+"send File conte:"+fileData;
    tcpSocket->write(sendData);
    tcpSocket->flush();
    sendFile->close();
}
//槽函数


void Widget::on_pushButtonSend_clicked()
{
    sendData();
}


void Widget::on_pushButtonSelect_clicked()
{
    QString str=QFileDialog::getOpenFileName(this,"选择文件",".","all files(*.*)");
    fileName=str;
    qDebug()<<fileName;
    ui->lineEdit->setText(fileName);
}

