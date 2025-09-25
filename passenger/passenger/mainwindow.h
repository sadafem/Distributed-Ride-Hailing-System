#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "passenger_register.h"
#include "passenger_client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(passenger_client* pc ,QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Register_clicked();
    void on_Login_clicked();

private:
    Ui::MainWindow *ui;
    passenger_client* P_C;
};

#endif // MAINWINDOW_H
