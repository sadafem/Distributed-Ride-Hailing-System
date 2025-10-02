#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "passenger_client.h"
#include "run.h"
#include "passenger_register.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(passenger_client* pc , QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_clicked();

    void on_register_2_clicked();

private:
    passenger_client* P_C;
    Ui::Login *ui;
};

#endif // LOGIN_H
