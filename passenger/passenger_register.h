#ifndef PASSENGER_REGISTER_H
#define PASSENGER_REGISTER_H

#include <QWidget>
#include <QPushButton>
#include <QRegion>
#include "passenger_client.h"
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class passenger_register;
}

class passenger_register : public QWidget
{
    Q_OBJECT

public:
    explicit passenger_register(passenger_client* pc , QWidget *parent = 0);
    ~passenger_register();

private slots:
    void on_register_2_clicked();

    void on_back_clicked();

private:
    passenger_client* P_C;
    Ui::passenger_register *ui;
};

#endif // PASSENGER_REGISTER_H
