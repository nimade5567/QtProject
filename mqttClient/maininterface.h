#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>
#include <QMqttClient>
#include <QString>
#include <QMessageBox>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE
class mainInterface : public QWidget
{
    Q_OBJECT
public:
    mainInterface(QWidget *parent = nullptr);
    ~mainInterface();
    QMqttClient *mqttClient=new QMqttClient(this);
private:
    Ui::Form *ui;
    QString ip;
    QString port;
    QString clientId;
    QString topic;
    QString Username;
    QString Password;
signals:
private slots:
    void on_pushButtonLink_clicked();
    void on_pushButtonExit_clicked();
    void on_pushButtonQuitLink_clicked();
};

#endif // MAININTERFACE_H
