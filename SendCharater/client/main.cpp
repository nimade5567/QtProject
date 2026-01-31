#include <QCoreApplication>
#include <QDebug>
#include "include/tcpSocket.h"
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    tcpSocket socket;
    return QCoreApplication::exec();
}