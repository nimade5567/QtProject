#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socketInit();
}
//内联函数
inline void Widget::socketInit()
{
    tcpSocket->connectToHost("127.0.0.1",8080);
    connect(connectTimer,&QTimer::timeout,[&]{
        if(tcpSocket->state()!=QAbstractSocket::UnconnectedState)
            tcpSocket->abort();
            QMessageBox::warning(this,"连接提示","连接失败");
            qDebug()<<"连接失败";
            this->close();
    });
    connectTimer->start(10000);
    connect(tcpSocket,&QTcpSocket::connected,[=]{
        if(connectTimer->isActive())
            connectTimer->stop();
        QMessageBox::information(this,"连接提示","连接成功");
        qDebug()<<"连接成功";
    });
}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonSelect_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"选择文件","./");
    ui->lineEdit->setText(filePath);
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"文件打开失败";
        return;
    }
    QFileInfo fileInfo(file);
    fileName=fileInfo.fileName();
    fileSize=fileInfo.size();
    fileType="file";
    fileData=file.readAll();
    qDebug()<<fileName.toUtf8();
    qDebug()<<fileSize;
    qDebug()<<fileType.toUtf8();
    qDebug()<<fileData;
    //计算文件的checkSum
    checkSum=QCryptographicHash::hash(fileData,QCryptographicHash::Sha256);
    qDebug()<<checkSum.toHex();
    sendFullData.append(fileName.toUtf8());
    sendFullData.append(QByteArray::number(fileSize));
    sendFullData.append(fileType.toUtf8());
    sendFullData.append(checkSum.toHex());
    sendFullData.append("file content:");
    sendFullData.append(fileData);
    qDebug()<<sendFullData;
    file.close();
}


void Widget::on_pushButtonSend_clicked()
{
    tcpSocket->write(sendFullData);
    tcpSocket->flush();
    QMessageBox::information(this,"发送提示","文件发送完毕");
    qDebug()<<"文件发送完毕";
}

