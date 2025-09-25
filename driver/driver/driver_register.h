#ifndef DRIVER_REGISTER_H
#define DRIVER_REGISTER_H

#include <QWidget>
#include"driver_client.h"
#include "mainwindow.h"

namespace Ui {
class driver_register;
}

class driver_register : public QWidget
{
    Q_OBJECT

public:
    explicit driver_register(driver_client* dr , QWidget *parent = 0);
    ~driver_register();

private slots:
    void on_register_2_clicked();

    void on_back_clicked();

private:
    driver_client* D_C;
    Ui::driver_register *ui;
};

#endif // DRIVER_REGISTER_H
