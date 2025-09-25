/********************************************************************************
** Form generated from reading UI file 'driver_register.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVER_REGISTER_H
#define UI_DRIVER_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_driver_register
{
public:
    QLineEdit *lnusername;
    QLineEdit *lnpassword;
    QLineEdit *lnspaceship_num;
    QLineEdit *lnspaceship_model;
    QLineEdit *lnproduction_year;
    QLineEdit *lnspaceship_color;
    QLabel *username;
    QLabel *password;
    QLabel *model;
    QLabel *number;
    QLabel *production;
    QLabel *color;
    QLabel *unfill_username;
    QLabel *unfill_spaceship_model;
    QLabel *unfill_spaceship_number;
    QLabel *unfill_spaceship_color;
    QLabel *unfill_production_year;
    QLabel *unfill_password;
    QPushButton *register_2;
    QLabel *invalid_username;
    QLabel *invalid_number;
    QLabel *invalid_model;
    QPushButton *back;

    void setupUi(QWidget *driver_register)
    {
        if (driver_register->objectName().isEmpty())
            driver_register->setObjectName(QStringLiteral("driver_register"));
        driver_register->resize(950, 500);
        lnusername = new QLineEdit(driver_register);
        lnusername->setObjectName(QStringLiteral("lnusername"));
        lnusername->setGeometry(QRect(360, 50, 120, 30));
        lnpassword = new QLineEdit(driver_register);
        lnpassword->setObjectName(QStringLiteral("lnpassword"));
        lnpassword->setGeometry(QRect(360, 100, 120, 30));
        lnspaceship_num = new QLineEdit(driver_register);
        lnspaceship_num->setObjectName(QStringLiteral("lnspaceship_num"));
        lnspaceship_num->setGeometry(QRect(360, 150, 120, 30));
        lnspaceship_model = new QLineEdit(driver_register);
        lnspaceship_model->setObjectName(QStringLiteral("lnspaceship_model"));
        lnspaceship_model->setGeometry(QRect(360, 200, 120, 30));
        lnproduction_year = new QLineEdit(driver_register);
        lnproduction_year->setObjectName(QStringLiteral("lnproduction_year"));
        lnproduction_year->setGeometry(QRect(360, 250, 120, 30));
        lnspaceship_color = new QLineEdit(driver_register);
        lnspaceship_color->setObjectName(QStringLiteral("lnspaceship_color"));
        lnspaceship_color->setGeometry(QRect(360, 300, 120, 30));
        username = new QLabel(driver_register);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(240, 50, 121, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        username->setFont(font);
        password = new QLabel(driver_register);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(240, 100, 121, 31));
        password->setFont(font);
        model = new QLabel(driver_register);
        model->setObjectName(QStringLiteral("model"));
        model->setGeometry(QRect(160, 200, 201, 31));
        model->setFont(font);
        number = new QLabel(driver_register);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(140, 150, 211, 31));
        number->setFont(font);
        production = new QLabel(driver_register);
        production->setObjectName(QStringLiteral("production"));
        production->setGeometry(QRect(170, 250, 201, 31));
        production->setFont(font);
        color = new QLabel(driver_register);
        color->setObjectName(QStringLiteral("color"));
        color->setGeometry(QRect(177, 300, 181, 31));
        color->setFont(font);
        unfill_username = new QLabel(driver_register);
        unfill_username->setObjectName(QStringLiteral("unfill_username"));
        unfill_username->setGeometry(QRect(485, 60, 21, 21));
        QFont font1;
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setWeight(75);
        unfill_username->setFont(font1);
        unfill_spaceship_model = new QLabel(driver_register);
        unfill_spaceship_model->setObjectName(QStringLiteral("unfill_spaceship_model"));
        unfill_spaceship_model->setGeometry(QRect(485, 200, 21, 21));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        unfill_spaceship_model->setFont(font2);
        unfill_spaceship_number = new QLabel(driver_register);
        unfill_spaceship_number->setObjectName(QStringLiteral("unfill_spaceship_number"));
        unfill_spaceship_number->setGeometry(QRect(485, 150, 21, 21));
        unfill_spaceship_number->setFont(font2);
        unfill_spaceship_color = new QLabel(driver_register);
        unfill_spaceship_color->setObjectName(QStringLiteral("unfill_spaceship_color"));
        unfill_spaceship_color->setGeometry(QRect(485, 290, 21, 21));
        unfill_spaceship_color->setFont(font2);
        unfill_production_year = new QLabel(driver_register);
        unfill_production_year->setObjectName(QStringLiteral("unfill_production_year"));
        unfill_production_year->setGeometry(QRect(485, 260, 21, 21));
        unfill_production_year->setFont(font2);
        unfill_password = new QLabel(driver_register);
        unfill_password->setObjectName(QStringLiteral("unfill_password"));
        unfill_password->setGeometry(QRect(485, 110, 21, 21));
        unfill_password->setFont(font2);
        register_2 = new QPushButton(driver_register);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(360, 360, 110, 40));
        invalid_username = new QLabel(driver_register);
        invalid_username->setObjectName(QStringLiteral("invalid_username"));
        invalid_username->setGeometry(QRect(360, 80, 121, 16));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        invalid_username->setFont(font3);
        invalid_number = new QLabel(driver_register);
        invalid_number->setObjectName(QStringLiteral("invalid_number"));
        invalid_number->setGeometry(QRect(360, 180, 181, 16));
        invalid_number->setFont(font3);
        invalid_model = new QLabel(driver_register);
        invalid_model->setObjectName(QStringLiteral("invalid_model"));
        invalid_model->setGeometry(QRect(360, 230, 171, 16));
        invalid_model->setFont(font3);
        back = new QPushButton(driver_register);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(70, 20, 80, 22));

        retranslateUi(driver_register);

        QMetaObject::connectSlotsByName(driver_register);
    } // setupUi

    void retranslateUi(QWidget *driver_register)
    {
        driver_register->setWindowTitle(QApplication::translate("driver_register", "Form", 0));
        username->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">username</span></p></body></html>", 0));
        password->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">password</span></p></body></html>", 0));
        model->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">spaceship model</span></p></body></html>", 0));
        number->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">spaceship number</span></p></body></html>", 0));
        production->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">production year</span></p></body></html>", 0));
        color->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#00ffff;\">spaceship color</span></p></body></html>", 0));
        unfill_username->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" font-size:20pt; color:#d50606;\">*</span></p></body></html>", 0));
        unfill_spaceship_model->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">*</span></p></body></html>", 0));
        unfill_spaceship_number->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">*</span></p></body></html>", 0));
        unfill_spaceship_color->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">*</span></p></body></html>", 0));
        unfill_production_year->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">*</span></p></body></html>", 0));
        unfill_password->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">*</span></p></body></html>", 0));
        register_2->setText(QApplication::translate("driver_register", "Register", 0));
        invalid_username->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">Invalid Username</span></p></body></html>", 0));
        invalid_number->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">Invalid Spaceship Number</span></p></body></html>", 0));
        invalid_model->setText(QApplication::translate("driver_register", "<html><head/><body><p><span style=\" color:#d50606;\">Invalid Spaceship Model</span></p></body></html>", 0));
        back->setText(QApplication::translate("driver_register", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class driver_register: public Ui_driver_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVER_REGISTER_H
