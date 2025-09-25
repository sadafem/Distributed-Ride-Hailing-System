/********************************************************************************
** Form generated from reading UI file 'set_status.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_STATUS_H
#define UI_SET_STATUS_H

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

class Ui_set_status
{
public:
    QPushButton *available;
    QPushButton *unavailabe;
    QLineEdit *address;
    QLabel *label;
    QLabel *unfill_address;
    QLabel *invalid_addres;

    void setupUi(QWidget *set_status)
    {
        if (set_status->objectName().isEmpty())
            set_status->setObjectName(QStringLiteral("set_status"));
        set_status->resize(950, 500);
        available = new QPushButton(set_status);
        available->setObjectName(QStringLiteral("available"));
        available->setGeometry(QRect(170, 190, 110, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        available->setFont(font);
        unavailabe = new QPushButton(set_status);
        unavailabe->setObjectName(QStringLiteral("unavailabe"));
        unavailabe->setGeometry(QRect(370, 190, 110, 40));
        unavailabe->setFont(font);
        address = new QLineEdit(set_status);
        address->setObjectName(QStringLiteral("address"));
        address->setGeometry(QRect(210, 120, 300, 30));
        label = new QLabel(set_status);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 119, 111, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        unfill_address = new QLabel(set_status);
        unfill_address->setObjectName(QStringLiteral("unfill_address"));
        unfill_address->setGeometry(QRect(518, 122, 21, 21));
        invalid_addres = new QLabel(set_status);
        invalid_addres->setObjectName(QStringLiteral("invalid_addres"));
        invalid_addres->setGeometry(QRect(210, 150, 91, 21));

        retranslateUi(set_status);

        QMetaObject::connectSlotsByName(set_status);
    } // setupUi

    void retranslateUi(QWidget *set_status)
    {
        set_status->setWindowTitle(QApplication::translate("set_status", "Form", 0));
        available->setText(QApplication::translate("set_status", "available", 0));
        unavailabe->setText(QApplication::translate("set_status", "unavailable", 0));
        label->setText(QApplication::translate("set_status", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; color:#00007f;\">current address</span></p></body></html>", 0));
        unfill_address->setText(QApplication::translate("set_status", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600; color:#aa0000;\">*</span></p></body></html>", 0));
        invalid_addres->setText(QApplication::translate("set_status", "<html><head/><body><p><span style=\" color:#ff0000;\">Invalid Address</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class set_status: public Ui_set_status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_STATUS_H
