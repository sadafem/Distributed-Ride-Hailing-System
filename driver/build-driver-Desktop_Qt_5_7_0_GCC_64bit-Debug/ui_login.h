/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_login
{
public:
    QLabel *invalid_password;
    QPushButton *register_2;
    QLabel *unfill_username;
    QLabel *username;
    QLabel *invalid_username;
    QLineEdit *lnpassword;
    QLabel *unfill_password;
    QLineEdit *lnusername;
    QLabel *label;
    QLabel *password;
    QPushButton *login_2;
    QLabel *not_accepted;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(950, 500);
        invalid_password = new QLabel(login);
        invalid_password->setObjectName(QStringLiteral("invalid_password"));
        invalid_password->setGeometry(QRect(450, 245, 121, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        invalid_password->setFont(font);
        register_2 = new QPushButton(login);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(450, 345, 110, 40));
        register_2->setFont(font);
        unfill_username = new QLabel(login);
        unfill_username->setObjectName(QStringLiteral("unfill_username"));
        unfill_username->setGeometry(QRect(574, 158, 21, 21));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        unfill_username->setFont(font1);
        username = new QLabel(login);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(328, 150, 121, 41));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        username->setFont(font2);
        invalid_username = new QLabel(login);
        invalid_username->setObjectName(QStringLiteral("invalid_username"));
        invalid_username->setGeometry(QRect(450, 185, 121, 21));
        invalid_username->setFont(font);
        lnpassword = new QLineEdit(login);
        lnpassword->setObjectName(QStringLiteral("lnpassword"));
        lnpassword->setGeometry(QRect(450, 215, 120, 30));
        unfill_password = new QLabel(login);
        unfill_password->setObjectName(QStringLiteral("unfill_password"));
        unfill_password->setGeometry(QRect(574, 217, 16, 21));
        unfill_password->setFont(font1);
        lnusername = new QLineEdit(login);
        lnusername->setObjectName(QStringLiteral("lnusername"));
        lnusername->setGeometry(QRect(450, 155, 120, 30));
        lnusername->setContextMenuPolicy(Qt::DefaultContextMenu);
        lnusername->setReadOnly(false);
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 345, 131, 41));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        password = new QLabel(login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(330, 215, 111, 31));
        password->setFont(font2);
        login_2 = new QPushButton(login);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(450, 275, 110, 40));
        login_2->setFont(font);
        not_accepted = new QLabel(login);
        not_accepted->setObjectName(QStringLiteral("not_accepted"));
        not_accepted->setGeometry(QRect(570, 280, 151, 31));
        not_accepted->setFont(font);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", 0));
        invalid_password->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Password</span></p></body></html>", 0));
        register_2->setText(QApplication::translate("login", "Register", 0));
        unfill_username->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#e30000;\">*</span></p></body></html>", 0));
        username->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#00007f;\">username</span></p></body></html>", 0));
        invalid_username->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Username</span></p></body></html>", 0));
        unfill_password->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#e30000;\">*</span></p></body></html>", 0));
        lnusername->setInputMask(QString());
        lnusername->setText(QString());
        label->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ff0000;\">Not Register?</span></p></body></html>", 0));
        password->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#00007f;\">password</span></p></body></html>", 0));
        login_2->setText(QApplication::translate("login", "Login", 0));
        not_accepted->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ff0000;\">Pending Registration</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
