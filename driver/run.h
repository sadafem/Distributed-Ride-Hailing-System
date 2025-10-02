#ifndef RUN_H
#define RUN_H

#include <QWidget>
#include "driver_client.h"
#include "set_status.h"
#include "qmessagebox.h"

namespace Ui {
class run;
}

class run : public QWidget
{
    Q_OBJECT

public:
    explicit run(driver_client* dc , QWidget *parent = 0);
    ~run();

private slots:
    void on_set_status_clicked();

    void on_show_trip_clicked();

    void on_accept_trip_clicked();

private:
    driver_client* D_C;
    Ui::run *ui;
};

#endif // RUN_H
