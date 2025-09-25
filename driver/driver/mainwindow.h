#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "driver_client.h"
#include "driver_register.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(driver_client* dv , QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_register_2_clicked();

private:
    driver_client* D_C;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
