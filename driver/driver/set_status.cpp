#include "set_status.h"
#include "ui_set_status.h"

set_status::set_status(driver_client *dc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_status)
{
    D_C = dc;
    ui->setupUi(this);
    ui->unfill_address->hide();
    ui->invalid_addres->hide();
}

set_status::~set_status()
{
    delete ui;
}

void set_status::on_available_clicked()
{
    std::string address = Tools::qstos(ui->address->text());
    if(address=="")
    {
        ui->unfill_address->show();
        return;
    }
    std::string responce = D_C->run("set_status available " + address);
    cout << responce << endl;
    if(responce == "Wrong Address\n")
        ui->invalid_addres->show();
    else
    {
        this->hide();
        run* r = new run(D_C);
        r->show();
    }
}

void set_status::on_unavailabe_clicked()
{
    std::string responce = D_C->run("set_status unavailable");
    this->hide();
    run* r = new run(D_C);
    r->show();
}
