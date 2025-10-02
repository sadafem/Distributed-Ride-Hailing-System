#ifndef SET_STATUS_H
#define SET_STATUS_H

#include <QWidget>
#include "driver_client.h"
#include "run.h"

namespace Ui {
class set_status;
}

class set_status : public QWidget
{
    Q_OBJECT

public:
    explicit set_status(driver_client* dc , QWidget *parent = 0);
    ~set_status();

private slots:
    void on_available_clicked();

    void on_unavailabe_clicked();

private:
    driver_client* D_C;
    Ui::set_status *ui;
};

#endif // SET_STATUS_H
