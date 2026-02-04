#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMqttClient>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>
#include <QLineseries>
#include <QChart>
#include <QFont>
#include <QValueAxis>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    explicit Widget(QMqttClient *mqttClient, const QString Topic, QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_checkBoxHit_checkStateChanged(const Qt::CheckState &arg1);

private:
    QMqttClient *widget_mqttClient = nullptr;  // not owned, already connected by mainInterface
    QSqlDatabase widget_sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");//创建
    QString widget_Topic;
    QLineSeries *widget_lineSeries = new QLineSeries();
    //表格绘制函数
    // inline void tableDraw();
    inline void sqlInit();
    static bool tableExists(QSqlDatabase &db, const QString &tableName);
//发送消息函数
    void sendMessage(const QString Message);
//订阅主题函数
    inline void subscribeTopic(const QString Topic);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
