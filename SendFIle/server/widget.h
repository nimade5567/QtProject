#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
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
    void on_buttonStartServer_clicked();

    void on_buttonSend_clicked();

private:
    Ui::Widget *ui;
    QTcpServer* server=new QTcpServer(this);
    QTcpSocket* socket=new QTcpSocket(this);
};
#endif // WIDGET_H
