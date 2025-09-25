/********************************************************************************
** Form generated from reading UI file 'passenger_register.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGER_REGISTER_H
#define UI_PASSENGER_REGISTER_H

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

class Ui_passenger_register
{
public:
    QLabel *username;
    QLabel *phone_number;
    QLabel *password;
    QLineEdit *lnusername;
    QLineEdit *lnpassword;
    QLineEdit *lnphone_number;
    QLabel *invalid_username;
    QPushButton *register_2;
    QLabel *invalid_phone_number;
    QLabel *unfill_username;
    QLabel *unfill_phone_number;
    QLabel *unfill_password;
    QPushButton *back;
    QLineEdit *lndiscount_code;
    QLabel *discount_code;
    QLabel *invalid_discount_code;

    void setupUi(QWidget *passenger_register)
    {
        if (passenger_register->objectName().isEmpty())
            passenger_register->setObjectName(QStringLiteral("passenger_register"));
        passenger_register->resize(950, 500);
        username = new QLabel(passenger_register);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(270, 90, 111, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        username->setFont(font);
        phone_number = new QLabel(passenger_register);
        phone_number->setObjectName(QStringLiteral("phone_number"));
        phone_number->setGeometry(QRect(220, 225, 161, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        phone_number->setFont(font1);
        password = new QLabel(passenger_register);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(270, 160, 101, 41));
        QFont font2;
        font2.setPointSize(15);
        password->setFont(font2);
        lnusername = new QLineEdit(passenger_register);
        lnusername->setObjectName(QStringLiteral("lnusername"));
        lnusername->setGeometry(QRect(390, 100, 120, 40));
        lnpassword = new QLineEdit(passenger_register);
        lnpassword->setObjectName(QStringLiteral("lnpassword"));
        lnpassword->setGeometry(QRect(390, 160, 120, 40));
        lnphone_number = new QLineEdit(passenger_register);
        lnphone_number->setObjectName(QStringLiteral("lnphone_number"));
        lnphone_number->setGeometry(QRect(390, 220, 120, 40));
        invalid_username = new QLabel(passenger_register);
        invalid_username->setObjectName(QStringLiteral("invalid_username"));
        invalid_username->setGeometry(QRect(390, 140, 121, 21));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        invalid_username->setFont(font3);
        register_2 = new QPushButton(passenger_register);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(390, 360, 110, 40));
        register_2->setFont(font3);
        invalid_phone_number = new QLabel(passenger_register);
        invalid_phone_number->setObjectName(QStringLiteral("invalid_phone_number"));
        invalid_phone_number->setGeometry(QRect(390, 260, 161, 21));
        invalid_phone_number->setFont(font3);
        unfill_username = new QLabel(passenger_register);
        unfill_username->setObjectName(QStringLiteral("unfill_username"));
        unfill_username->setGeometry(QRect(515, 110, 21, 21));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        unfill_username->setFont(font4);
        unfill_phone_number = new QLabel(passenger_register);
        unfill_phone_number->setObjectName(QStringLiteral("unfill_phone_number"));
        unfill_phone_number->setGeometry(QRect(516, 230, 20, 21));
        unfill_phone_number->setFont(font4);
        unfill_password = new QLabel(passenger_register);
        unfill_password->setObjectName(QStringLiteral("unfill_password"));
        unfill_password->setGeometry(QRect(515, 170, 21, 21));
        unfill_password->setFont(font4);
        back = new QPushButton(passenger_register);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(60, 20, 80, 22));
        lndiscount_code = new QLineEdit(passenger_register);
        lndiscount_code->setObjectName(QStringLiteral("lndiscount_code"));
        lndiscount_code->setGeometry(QRect(390, 280, 120, 40));
        discount_code = new QLabel(passenger_register);
        discount_code->setObjectName(QStringLiteral("discount_code"));
        discount_code->setGeometry(QRect(230, 280, 161, 41));
        discount_code->setFont(font2);
        invalid_discount_code = new QLabel(passenger_register);
        invalid_discount_code->setObjectName(QStringLiteral("invalid_discount_code"));
        invalid_discount_code->setGeometry(QRect(390, 320, 151, 21));
        invalid_discount_code->setFont(font3);

        retranslateUi(passenger_register);

        QMetaObject::connectSlotsByName(passenger_register);
    } // setupUi

    void retranslateUi(QWidget *passenger_register)
    {
        passenger_register->setWindowTitle(QApplication::translate("passenger_register", "Form", 0));
        username->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:14pt; color:#00ffff;\">username</span></p></body></html>", 0));
        phone_number->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:14pt; color:#00ffff;\">phone number</span></p></body></html>", 0));
        password->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00ffff;\">password</span></p></body></html>", 0));
        invalid_username->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Username</span></p></body></html>", 0));
        register_2->setText(QApplication::translate("passenger_register", "Register", 0));
        invalid_phone_number->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Phone Number</span></p></body></html>", 0));
        unfill_username->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:20pt; color:#e30000;\">*</span></p></body></html>", 0));
        unfill_phone_number->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:20pt; color:#e30000;\">*</span></p></body></html>", 0));
        unfill_password->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:20pt; color:#e30000;\">*</span></p></body></html>", 0));
        back->setText(QApplication::translate("passenger_register", "Back", 0));
        discount_code->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00ffff;\">discount code</span></p></body></html>", 0));
        invalid_discount_code->setText(QApplication::translate("passenger_register", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Discount Code</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class passenger_register: public Ui_passenger_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGER_REGISTER_H
