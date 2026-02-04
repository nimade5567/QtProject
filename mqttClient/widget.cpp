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
        QString name1;
        QString data1;
        qDebug()<<messageString;
        int i=0;
        for(QChar c : messageString)
        {

            if(i>=1&&i<2)
                name1.append(c);
            if(i>=3&&i<4)
                data1.append(c);
            if(c=='"')
                i++;
        }
        name1.chop(1);
        data1.chop(1);
        qDebug()<<name1;
        qDebug()<<data1;
        //数据插入操作
        QSqlQuery query;
        query.prepare("INSERT INTO mqtt (sensorname, datanum) VALUES (:sensorname, :datanum)");
        query.bindValue(":sensorname", name1);
        query.bindValue(":datanum", data1);
        if(!query.exec())
        {
            QMessageBox::critical(this, "错误", "数据插入失败");
            return;
        }
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
//表格绘制函数
// inline void Widget::tableDraw(){
//     QSqlQuery query;
//     query.exec("SELECT * FROM mqtt");
//     while(query.next())
//     {
//         widget_lineSeries->append(query.value(0).toInt(), query.value(2).toInt());
//         widget_lineSeries->setName(query.value(1).toString());
//     }
//     series->setName("测试数据"); // 系列名称（图例显示）
//     series->setPen(QPen(Qt::blue, 2)); // 折线颜色+宽度
//     series->setPointsVisible(true); // 显示数据点
//     series->setPointLabelsVisible(true); // 显示数据点数值标签
//     QChart *chart = new QChart();
//     chart->addSeries(widget_lineSeries);
//     chart->setTitle("MQTT数据");
//     chart->setTitleFont(QFont("Arial", 16));
//     chart->setAnimationOptions(QChart::SeriesAnimations);
//     chart->legend()->setVisible(true);

//     QValueAxis *axisX = new QValueAxis(); // X轴（数值轴）
//     axisX->setRange(0, 9); // X轴范围
//     axisX->setTitleText("时间（s）"); // X轴标题
//     axisX->setTickCount(10); // 刻度数

//     QValueAxis *axisY = new QValueAxis(); // Y轴（数值轴）
//     axisY->setRange(0, 100); // Y轴范围
//     axisY->setTitleText("数值"); // Y轴标题
//     axisY->setTickCount(11); // 刻度数

// }
Widget::~Widget()
{
    delete ui;
}

