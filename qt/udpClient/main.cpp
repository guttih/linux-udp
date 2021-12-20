#include "mainwindow.h"

#include <QApplication>
#include "udpcomunication.h"

int main(int argc, char *argv[])
{
    UdpComunication udp("192.168.1.153", 1234);
    udp.connect();
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
