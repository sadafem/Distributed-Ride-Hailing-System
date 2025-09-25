#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "passenger_client.h"

MainWindow::MainWindow(passenger_client* pc ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    P_C = pc;
    this->setStyleSheet("QWidget {background-image: url(/home/navid/Codes/assignment/A7/phase3/main.jpg) }");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Register_clicked()
{
    this->hide();
    passenger_register* pr = new passenger_register(P_C);
    pr->show();
}

void MainWindow::on_Login_clicked()
{
    this->hide();
    Login* ln = new Login(P_C);
    ln->show();
}
