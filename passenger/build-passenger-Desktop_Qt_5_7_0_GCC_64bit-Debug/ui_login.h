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

class Ui_Login
{
public:
    QLabel *username;
    QLabel *password;
    QLineEdit *lnusername;
    QLineEdit *lnpassword;
    QLabel *invalid_username;
    QLabel *invalid_password;
    QPushButton *login;
    QLabel *label;
    QPushButton *register_2;
    QLabel *unfill_username;
    QLabel *unfill_password;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(950, 500);
        username = new QLabel(Login);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(334, 120, 121, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        username->setFont(font);
        password = new QLabel(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(336, 185, 111, 41));
        password->setFont(font);
        lnusername = new QLineEdit(Login);
        lnusername->setObjectName(QStringLiteral("lnusername"));
        lnusername->setGeometry(QRect(456, 130, 120, 30));
        lnusername->setContextMenuPolicy(Qt::DefaultContextMenu);
        lnusername->setReadOnly(false);
        lnpassword = new QLineEdit(Login);
        lnpassword->setObjectName(QStringLiteral("lnpassword"));
        lnpassword->setGeometry(QRect(456, 190, 120, 30));
        invalid_username = new QLabel(Login);
        invalid_username->setObjectName(QStringLiteral("invalid_username"));
        invalid_username->setGeometry(QRect(456, 160, 121, 21));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        invalid_username->setFont(font1);
        invalid_password = new QLabel(Login);
        invalid_password->setObjectName(QStringLiteral("invalid_password"));
        invalid_password->setGeometry(QRect(456, 220, 121, 21));
        invalid_password->setFont(font1);
        login = new QPushButton(Login);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(460, 250, 110, 40));
        login->setFont(font1);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 320, 121, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        register_2 = new QPushButton(Login);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(460, 320, 110, 40));
        register_2->setFont(font1);
        unfill_username = new QLabel(Login);
        unfill_username->setObjectName(QStringLiteral("unfill_username"));
        unfill_username->setGeometry(QRect(580, 133, 21, 21));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        unfill_username->setFont(font3);
        unfill_password = new QLabel(Login);
        unfill_password->setObjectName(QStringLiteral("unfill_password"));
        unfill_password->setGeometry(QRect(580, 192, 16, 21));
        unfill_password->setFont(font3);
        login->raise();
        password->raise();
        label->raise();
        lnusername->raise();
        unfill_password->raise();
        lnpassword->raise();
        invalid_username->raise();
        username->raise();
        unfill_username->raise();
        register_2->raise();
        invalid_password->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        username->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#00007f;\">username</span></p></body></html>", 0));
        password->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#00007f;\">password</span></p></body></html>", 0));
        lnusername->setInputMask(QString());
        lnusername->setText(QString());
        invalid_username->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Username</span></p></body></html>", 0));
        invalid_password->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Password</span></p></body></html>", 0));
        login->setText(QApplication::translate("Login", "Login", 0));
        label->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#ff0000;\">Not Register?</span></p></body></html>", 0));
        register_2->setText(QApplication::translate("Login", "Register", 0));
        unfill_username->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#e30000;\">*</span></p></body></html>", 0));
        unfill_password->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" color:#e30000;\">*</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
