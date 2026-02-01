#include "widget.h"
#include "maininterface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainInterface m;
    m.show();
    return a.exec();
}
