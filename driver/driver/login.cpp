#include "login.h"
#include "ui_login.h"

login::login(driver_client *dv, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    D_C = dv;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/other.png")));
    this->setPalette(pallet);
    ui->setupUi(this);
    ui->invalid_password->hide();
    ui->invalid_username->hide();
    ui->unfill_password->hide();
    ui->unfill_username->hide();
    ui->not_accepted->hide();
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
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
    std::string responce = D_C->run( "login " + username +" "+ password );
    if(responce == "Incorrect Username\n")
        ui->invalid_username->show();
    else if (responce == "Incorrect Password\n")
        ui->invalid_password->show();
    else if (responce == "Pending registration\n")
        ui->not_accepted->show();
    else
    {
        this->hide();
        run* r = new run(D_C);
        r->show();
    }
}

void login::on_register_2_clicked()
{
    this->hide();
    driver_register* dr = new driver_register(D_C);
    dr->show();
}
