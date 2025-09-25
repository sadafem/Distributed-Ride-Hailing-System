#include "run.h"
#include "ui_run.h"

run::run(driver_client* dc , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::run)
{
    D_C = dc;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/passenger/passenger/7.jpg")));
    this->setPalette(pallet);
    ui->setupUi(this);
}

run::~run()
{
    delete ui;
}

void run::on_set_status_clicked()
{
    this->hide();
    set_status* ss = new set_status(D_C);
    ss->show();
}

void run::on_show_trip_clicked()
{
    QMessageBox code;
    std::string temp;
    std::string responce = D_C->run("show_trip_request");
    code.setText(Tools::stoqs(responce));
    code.exec();
}

void run::on_accept_trip_clicked()
{

}
