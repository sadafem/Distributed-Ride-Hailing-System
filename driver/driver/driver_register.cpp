#include "driver_register.h"
#include "ui_driver_register.h"

driver_register::driver_register(driver_client* dr , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::driver_register)
{
    D_C = dr;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/other.png")));
    this->setPalette(pallet);
    ui->setupUi(this);
    ui->unfill_password->hide();
    ui->unfill_production_year->hide();
    ui->unfill_username->hide();
    ui->unfill_spaceship_color->hide();
    ui->unfill_spaceship_model->hide();
    ui->unfill_spaceship_number->hide();
    ui->invalid_model->hide();
    ui->invalid_number->hide();
    ui->invalid_username->hide();
}

driver_register::~driver_register()
{
    delete ui;
}

void driver_register::on_register_2_clicked()
{
    std::string username = Tools::qstos(ui->lnusername->text());
    std::string password = Tools::qstos(ui->lnpassword->text());
    std::string spaceship_number = Tools::qstos(ui->lnspaceship_num->text());
    std::string spaceship_model = Tools::qstos(ui->lnspaceship_model->text());
    std::string production_year = Tools::qstos(ui->lnproduction_year->text());
    std::string spaceship_color = Tools::qstos(ui->lnspaceship_color->text());
    if(username=="" || password=="" || spaceship_number=="" || spaceship_model=="" || production_year=="" || spaceship_color=="")
    {
        if(username=="")
            ui->unfill_username->show();
        if(password=="")
            ui->unfill_password->show();
        if(spaceship_number=="")
            ui->unfill_spaceship_number->show();
        if(spaceship_model=="")
            ui->unfill_spaceship_model->show();
        if(production_year=="")
            ui->unfill_production_year->show();
        if(spaceship_color=="")
            ui->unfill_spaceship_color->show();
        return;
    }
    std::string responce = D_C->run( "register " + username +" "+ password + " " + spaceship_number + " "
                                     + spaceship_model + " " + production_year + " " + spaceship_color);
    if(responce == "Username Is Taken\n")
        ui->invalid_username->show();
    else if(responce =="Spaceship Number Taken\n")
        ui->invalid_number->show();
    else if(responce=="Spaceship Model Not Found\n")
        ui->invalid_model->show();
    else
    {
        this->hide();
        MainWindow* mw = new MainWindow(D_C);
        mw->show();
    }

}

void driver_register::on_back_clicked()
{
    this->hide();
    MainWindow* mw = new MainWindow(D_C);
    mw->show();
}
