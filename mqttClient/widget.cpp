#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::Widget(QMqttClient *mqttClient, const QString Topic, QWidget *parent)
    : Widget(parent)
{
    widget_mqttClient=mqttClient;
    widget_Topic=Topic;
    subscribeTopic(widget_Topic);
    sqlInit();
    connect(widget_mqttClient,&QMqttClient::messageReceived,[=](const QByteArray &message){
        QString messageString = QString::fromUtf8(message);
        qDebug()<<messageString;
    });
}

//数据库初始化函数
inline void Widget::sqlInit(){
    widget_sqlDatabase.setDatabaseName("mqtt.db");
    if(!widget_sqlDatabase.open())
    {
        QMessageBox::critical(this, "错误", "数据库打开失败");
        return;
    }
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS mqtt (id INTEGER PRIMARY KEY AUTOINCREMENT, sensorname varchar(255), datanum varchar(255))")){
        QMessageBox::critical(this, "错误", "数据库创建失败");
        return;
    }
    
}
//订阅主题函数
inline void Widget::subscribeTopic(const QString Topic){
    widget_mqttClient->subscribe(Topic);
}
//消息发送函数
void Widget::sendMessage(const QString Message){
    QByteArray payload = Message.toUtf8();
    widget_mqttClient->publish(widget_Topic, payload);
}
Widget::~Widget()
{
    delete ui;
}
