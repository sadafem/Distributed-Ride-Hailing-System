#ifndef RUN_H
#define RUN_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <sstream>
#include "passenger_client.h"
#include "qmessagebox.h"
#include "charge_account.h"
#include "mainwindow.h"


namespace Ui {
class run;
}

class run : public QWidget
{
    Q_OBJECT

public:
    explicit run(passenger_client* pc , QWidget *parent = 0);
    ~run();

private slots:
    void on_discout_code_clicked();

    void on_charge_account_clicked();

    void on_log_out_clicked();

    void on_menu_clicked();

    void on_estimate_clicked();

    void on_request_clicked();

private:
    passenger_client* P_C;
    Ui::run *ui;
    bool _hide;
};

#endif // RUN_H
