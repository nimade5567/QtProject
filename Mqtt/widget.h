#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMqttClient>
#include<QString>
#include<QDebug>
#include<QMessageBox>
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
    ~Widget();

private slots:
    void on_pushButtonLink_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QMqttClient* clinet=new QMqttClient(this);
    QString Ip;
    quint16 Port;
    QString Topic;
    QString ClientId;
};
#endif // WIDGET_H
