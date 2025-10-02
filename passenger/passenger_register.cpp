#include "passenger_register.h"
#include "ui_passenger_register.h"

passenger_register::passenger_register(passenger_client* pc , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passenger_register)
{
    P_C = pc;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/Users/sadaf/Downloads/Advance programming/Assignment/A7/phase 3/other.png")));
    this->setPalette(pallet);
    ui->setupUi(this);
    ui->invalid_username->hide();
    ui->invalid_phone_number->hide();
    ui->invalid_discount_code->hide();
    ui->unfill_password->hide();
    ui->unfill_phone_number->hide();
    ui->unfill_username->hide();
}

passenger_register::~passenger_register()
{
    delete ui;
}

void passenger_register::on_register_2_clicked()
{
    std::string username = Tools::qstos(ui->lnusername->text());
    std::string password = Tools::qstos(ui->lnpassword->text());
    std::string phone_number = Tools::qstos(ui->lnphone_number->text());
    std::string discount_code = Tools::qstos(ui->lndiscount_code->text());
    if(username=="" || password=="" || phone_number=="")
    {
        if(username=="")
            ui->unfill_username->show();
        if(password=="")
            ui->unfill_password->show();
        if(phone_number=="")
            ui->unfill_phone_number->show();
        return;
    }
    std::string responce;
    if(discount_code == "")
        responce = P_C->run( "register " + username +" "+ password + " " + phone_number);
    else
        responce = P_C->run( "register " + username +" "+ password + " " + phone_number + " " + discount_code);

    if(responce == "Username Is Taken\n")
        ui->invalid_username->show();
    else if (responce == "Phone Number Taken\n")
        ui->invalid_phone_number->show();
    else if(responce == "Unavailable Discount Code\n")
        ui->invalid_discount_code->show();
    else
    {
        this->hide();
        MainWindow* mw = new MainWindow(P_C);
        mw->show();
    }
}

void passenger_register::on_back_clicked()
{
    this->hide();
    MainWindow* mw = new MainWindow(P_C);
    mw->show();
}
