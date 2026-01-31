#include <QCoreApplication>
#include <QDebug>
#include "include/tcpServer.h"
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    tcpServer server;
    return QCoreApplication::exec();
}