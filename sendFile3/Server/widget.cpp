#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    serverInit();
}
//内联函数
inline void Widget::serverInit()
{
    if(!tcpServer->listen(QHostAddress::Any,8080))
    {
        qDebug()<<"服务器启动失败";
        return;
    }else{
        qDebug()<<"服务器启动成功";
        connect(tcpServer,&QTcpServer::newConnection,
                [=]()
        {
            tcpSocket=tcpServer->nextPendingConnection();
            qDebug()<<tcpSocket->peerAddress().toString()<<tcpSocket->peerPort()<<"连接成功";
            connect(tcpSocket,&QTcpSocket::readyRead,[&]{
                receiveData.append(tcpSocket->readAll());
                QMessageBox::information(this,"接收提示","文件接收完毕");
                qDebug()<<receiveData;
                qDebug()<<"文件接收完毕";
                dataProcessing(receiveData);
            });
        });
    }
}
void Widget::dataProcessing(QByteArray &fileData)
{
    fileName=fileData.mid(0,fileData.indexOf("txt")+3);
    qDebug()<<fileName;
    fileDataContent=fileData.mid(fileData.indexOf("file content:")+14);
    qDebug()<<fileDataContent;
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSelect_clicked()
{
    storeFilePath=QFileDialog::getExistingDirectory(this,"选择文件存储路径","./");
    ui->lineEdit->setText(storeFilePath);
    qDebug()<<storeFilePath;   
}


void Widget::on_pushButtonStore_clicked()
{
    storeFullFilePath=storeFilePath+"/"+fileName;
    qDebug()<<storeFullFilePath;
    QFile file(storeFullFilePath);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"文件创建失败";
        return;
    }else{
        file.write(fileDataContent);
        file.close();
        QMessageBox::information(this,"存储提示","文件存储成功");
        qDebug()<<"文件存储成功";
    }
}

