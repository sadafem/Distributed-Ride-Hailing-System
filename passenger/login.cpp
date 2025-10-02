#include "login.h"
#include "ui_login.h"

Login::Login(passenger_client* pc,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    P_C = pc;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/other.png")));
    this->setPalette(pallet);
    ui->setupUi(this);
    ui->invalid_password->hide();
    ui->invalid_username->hide();
    ui->unfill_password->hide();
    ui->unfill_username->hide();
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    std::string username = Tools::qstos(ui->lnusername->text());
    std::string password = Tools::qstos(ui->lnpassword->text());
    if(username=="" || password=="")
    {
        if(username=="")
            ui->unfill_username->show();
        if(password=="")
            ui->unfill_password->show();
        return;
    }
    std::string responce = P_C->run( "login " + username +" "+ password );
    if(responce == "Incorrect Username\n")
        ui->invalid_username->show();
    else if (responce == "Incorrect Password\n")
        ui->invalid_password->show();
    else
    {
        this->hide();
        run* r = new run(P_C);
        r->show();
    }
}

void Login::on_register_2_clicked()
{
    this->hide();
    passenger_register* pr = new passenger_register(P_C);
    pr->show();
}
