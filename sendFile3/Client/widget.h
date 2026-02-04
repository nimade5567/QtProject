#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QFileInfo>
#include <QFileDialog>
#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <QMessageBox>
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

    void on_pushButtonSend_clicked();

private:
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    QTimer *connectTimer =new QTimer(this);

    //定义数据
    QString fileName;
    qint64 fileSize;
    QString fileType;
    QByteArray checkSum;
    QByteArray fileData;
    QByteArray sendFullData;
    //内联函数
    inline void socketInit();
    Ui::Widget *ui;
};
#endif // WIDGET_H
