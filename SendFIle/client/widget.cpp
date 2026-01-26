#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(socket,&QTcpSocket::readyRead,[&]{
        QString serverSocket=socket->readAll();
        ui->plainTextEditMessage->appendPlainText("他说:"+serverSocket);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSend_clicked()
{
    QString meWord=ui->lineEditMessage->text();
    qDebug()<<meWord;
    ui->plainTextEditMessage->appendPlainText("我说:"+meWord.toUtf8());
    socket->write(meWord.toUtf8());
}


void Widget::on_pushButtonLinkStart_clicked()
{
    QString IP=ui->lineEditIp->text();
    qDebug()<<(QHostAddress)IP;
    int Port=ui->lineEditPort->text().toInt();
    socket->connectToHost(IP,Port);
    ui->plainTextEditMessage->appendPlainText("连接成功");
}

