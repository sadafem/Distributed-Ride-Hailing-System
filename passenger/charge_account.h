#ifndef CHARGE_ACCOUNT_H
#define CHARGE_ACCOUNT_H

#include <QDialog>
#include "passenger_client.h"
#include "qmessagebox.h"
namespace Ui {
class charge_account;
}

class charge_account : public QDialog
{
    Q_OBJECT

public:
    explicit charge_account(passenger_client* pc , QWidget *parent = 0);
    ~charge_account();

private slots:
    void on_buttonBox_accepted();

private:
    passenger_client* P_C;
    Ui::charge_account *ui;
};

#endif // CHARGE_ACCOUNT_H
