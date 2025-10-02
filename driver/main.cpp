#include "mainwindow.h"
#include "driver_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    driver_client* D_C = new driver_client("127.0.0.1" , 8080);
    QApplication a(argc, argv);
    MainWindow w(D_C);
    w.show();

    return a.exec();
}
