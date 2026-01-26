#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(server,&QTcpServer::newConnection,[&]{
        ui->plainTextEditMessage->appendPlainText("有新连接");
        socket=server->nextPendingConnection();
        qDebug()<<socket->peerAddress();
        connect(socket,&QTcpSocket::readyRead,[&]{
            QString socketWord=socket->readAll();
            ui->plainTextEditMessage->appendPlainText("他说:"+socketWord);
        });
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStartServer_clicked()
{
    int Port=ui->lineEditPort->text().toInt();
    qDebug()<<Port;
    if(!server->listen(QHostAddress::Any,Port)){
        qDebug()<<"启动服务器失败";
    }
    else{
        ui->plainTextEditMessage->appendPlainText("启动服务器成功");
    }
}


void Widget::on_buttonSend_clicked()
{
    QString meWord=ui->lineEditMessage->text();
    qDebug()<<meWord;
    ui->plainTextEditMessage->appendPlainText("我说:"+meWord);
    socket->write(meWord.toUtf8());
}

