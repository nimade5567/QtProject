#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

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

    void on_pushButtonSend_clicked();


    void on_pushButtonSelect_clicked();

private:
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    QFile* sendFile=new QFile(this);
    QString fileName;
    //内联函数
    inline void initClient();
    inline void sendData();
    Ui::Widget *ui;
};
#endif // WIDGET_H
