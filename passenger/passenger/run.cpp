#include "run.h"
#include "ui_run.h"

run::run(passenger_client* pc , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::run)
{
    P_C = pc;
    _hide = false;
    QPalette pallet;
    pallet.setBrush(this->backgroundRole() , QBrush(QImage("/home/navid/Codes/assignment/A7/phase3/other.png")));
    this->setPalette(pallet);
    ui->setupUi(this);
    std::string responce = P_C->run( "get_credit ");
    QLabel* lbcredit = new QLabel(this);
    lbcredit->setText("Current Credit: " + Tools::stoqs(responce));
    lbcredit->setGeometry(QRect(420, -20, 100, 100));
    ui->scrollArea->hide();
}

run::~run()
{
    delete ui;
}

void run::on_discout_code_clicked()
{
    QMessageBox code;
    std::string temp;
    std::vector <std::string> info;
    stringstream s (P_C->run("get_discount_code"));
    while(s>> temp)
        info.push_back(temp);
    code.setText("Discout Code: " + Tools::stoqs(info[0])+"    \n"+"Remain Time: " + Tools::stoqs(info[1]));
    code.exec();
}

void run::on_charge_account_clicked()
{
    charge_account* ca = new charge_account(P_C);
    ca->show();
}

void run::on_log_out_clicked()
{
    this->hide();
    P_C->run("logout");
    MainWindow * mw = new MainWindow(P_C);
    mw->show();
}

void run::on_menu_clicked()
{
    if(!_hide)
    {
        ui->scrollArea->show();
        _hide = true;
    }
    else
    {
        ui->scrollArea->hide();
        _hide = false;
    }
}

void run::on_estimate_clicked()
{

}

void run::on_request_clicked()
{

}
