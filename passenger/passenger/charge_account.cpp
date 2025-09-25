#include "charge_account.h"
#include "ui_charge_account.h"

charge_account::charge_account(passenger_client* pc , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charge_account)
{
    P_C = pc;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/passenger/passenger/7.jpg")));
    this->setPalette(pallet);
    ui->setupUi(this);
}

charge_account::~charge_account()
{
    delete ui;
}

inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

void charge_account::on_buttonBox_accepted()
{
    std::string money = Tools::qstos(ui->money->text());
    if(isInteger(money))
        P_C->run("charge_account " + money);
    else
    {
        QMessageBox code;
        code.setText("Please Insert Number");
        code.exec();
    }

}
