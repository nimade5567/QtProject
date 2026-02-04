#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化服务器
    initServer();
}

Widget::~Widget()
{
    delete ui;
}
//内联函数
    //初始化服务器
inline void Widget::initServer(){
    //启动客户端
    if(!tcpServer->listen(QHostAddress::Any,8888)){
        qDebug()<<"服务器启动失败";
        return;
    }else{
        qDebug()<<"服务器启动成功";
    }
    //监听客户端连接
    connect(tcpServer,&QTcpServer::newConnection,[=](){
        tcpSocket=tcpServer->nextPendingConnection();
        QString ip=tcpSocket->peerAddress().toString();
        qint16 port=tcpSocket->peerPort();
        qDebug()<<QString("客户端[%1:%2]连接成功").arg(ip).arg(port);
        connect(tcpSocket,&QTcpSocket::readyRead,[=](){
            QMessageBox::information(this,"提示","有数据到达");
            QByteArray array=tcpSocket->readAll();
            dataProcessing(array);
        });
    });
}
inline void Widget::dataProcessing(QByteArray data){
    QByteArray filename=data.mid(data.indexOf("send File:")+10,data.indexOf("send File conte:")-10);
    QByteArray filedata=data.mid(data.indexOf("send File conte:")+17);
    qDebug()<<filename;
    QFileInfo info(filename);
    QString filename1=info.fileName();
    QString fullFileName=saveFilePath+"/"+filename1;
    qDebug()<<fullFileName;
    QFile file(fullFileName);
    if(!file.open(QIODevice::WriteOnly)){
        qDebug()<<"文件创建失败";
        return;
    }else{
        qDebug()<<"文件创建成功";
        file.write(filedata);
        file.close();
    }
}
//槽函数
void Widget::on_pushButtonSelect_clicked()
{
    QString str=QFileDialog::getExistingDirectory(this,"选择文件夹",".");
    qDebug()<<str;
    ui->lineEdit->setText(str);
    saveFilePath=str;
}

