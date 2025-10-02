#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "driver_client.h"
#include "driver_register.h"
#include "run.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(driver_client* dv , QWidget *parent = 0);
    ~login();

private slots:
    void on_login_2_clicked();

    void on_register_2_clicked();

private:
    driver_client* D_C;
    Ui::login *ui;
};

#endif // LOGIN_H
