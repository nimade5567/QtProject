#include "maininterface.h"
#include "ui_Form.h"
#include "widget.h"

mainInterface::mainInterface(QWidget *parent)
    : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    // Do not call mqttClient->connectToHost() here: set host/port first
    // and connect only when the user requests it (e.g. a Connect button).
}

mainInterface::~mainInterface()
{
    delete ui;
}

void mainInterface::on_pushButtonLink_clicked()
{
    ip = ui->lineEditIp->text();
    port = ui->lineEditPort->text();
    clientId = ui->lineEditClientId->text();
    topic = ui->lineEditTopic->text();
    Username = ui->lineEditUsername->text();
    Password = ui->lineEditPassword->text();
    qDebug()<<ip;
    qDebug()<<port;
    qDebug()<<clientId;
    qDebug()<<topic;
    qDebug()<<Username;
    qDebug()<<Password.toInt();
    mqttClient->setHostname(ip);
    mqttClient->setPort(port.toInt());
    mqttClient->setClientId(clientId);
    mqttClient->setUsername(Username);
    mqttClient->setPassword(Password);
    mqttClient->connectToHost();
    connect(mqttClient, &QMqttClient::connected,[=]{
        QMessageBox::information(this, "提示", "连接成功");
        Widget *w = new Widget(mqttClient, topic);
        w->setAttribute(Qt::WA_DeleteOnClose);  // delete when user closes the window
        w->show();
        this->close();
    });
    connect(mqttClient, &QMqttClient::disconnected,[=]{
        QMessageBox::information(this, "提示", "连接断开");
    });
}


void mainInterface::on_pushButtonExit_clicked()
{
    switch(QMessageBox::question(this, "提示", "确定退出吗？", QMessageBox::Yes | QMessageBox::No))
    {
        case QMessageBox::Yes:
            this->close();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
    }
}


void mainInterface::on_pushButtonQuitLink_clicked()
{
    if(mqttClient->state() == QMqttClient::Connected)
    {
        switch(QMessageBox::question(this, "提示", "确定断开连接吗？", QMessageBox::Yes | QMessageBox::No)){
            case QMessageBox::Yes:
                mqttClient->disconnectFromHost();
                break;
            case QMessageBox::No:
                break;
            default:
                break;
        }
    }
    else
    {
        QMessageBox::information(this, "提示", "未连接");
    }
}

