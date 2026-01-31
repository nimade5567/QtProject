#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(clinet,&QMqttClient::connected,[=]{
        qDebug() << "✅ MQTT connected";
        QMqttSubscription* sub=clinet->subscribe(QMqttTopicFilter(Topic));
        if(!sub){
            qDebug()<<"connected failed";
        }
        connect(sub,&QMqttSubscription::messageReceived,[=](const QMqttMessage& msg){
            ui->plainTextEdit->appendPlainText(msg.payload());
            qDebug()<<msg.payload();
        });
    });
    connect(clinet,&QMqttClient::disconnected,[=]{
        qDebug()<<"disconnected";
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLink_clicked()
{
    Ip=ui->lineEditIp->text();
    Port=ui->lineEditIPort->text().toInt();
    Topic=ui->lineEditTopic->text();
    ClientId=ui->lineEditTopic_2->text();
    clinet->setHostname(Ip);
    clinet->setPort(Port);
    clinet->setClientId(ClientId);
    qDebug()<<Ip;
    qDebug()<<Port;
    qDebug()<<Topic;
    qDebug()<<ClientId;
    clinet->connectToHost();
}


void Widget::on_pushButton_clicked()
{
    clinet->disconnectFromHost();
}

