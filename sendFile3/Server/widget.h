#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QMessageBox>
#include <QFileDialog>
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
    void on_pushButtonSelect_clicked();

    void on_pushButtonStore_clicked();

private:
    QTcpServer *tcpServer=new QTcpServer(this);
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    QByteArray fileDataContent;
    QString fileName;
    QString storeFilePath;
    QString storeFullFilePath;
    //内联函数
    inline void serverInit();
    void dataProcessing(QByteArray &fileData);
    QByteArray receiveData;
    Ui::Widget *ui;
};
#endif // WIDGET_H
