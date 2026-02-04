#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
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

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer=new QTcpServer(this);
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    
    //文件保存路径
    QString saveFilePath;
    //内联函数
    inline void initServer();
    inline void dataProcessing(QByteArray data);
};
#endif // WIDGET_H
