#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(driver_client *dv, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    D_C = dv;
    this->setStyleSheet("QWidget {background-image: url(/Users/sadaf/Downloads/Advance programming/Assignment/A7/phase 3/main.jpg)}");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    this->hide();
    login* ln = new login(D_C);
    ln->show();
}

void MainWindow::on_register_2_clicked()
{
    this->hide();
    driver_register* dr = new driver_register(D_C);
    dr->show();
}
