#include "mainwindow.h"
#include "passenger_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    passenger_client* P_C = new passenger_client("127.0.0.1" ,8080);
    QApplication a(argc, argv);
    MainWindow w(P_C);
    w.show();

    return a.exec();
}
