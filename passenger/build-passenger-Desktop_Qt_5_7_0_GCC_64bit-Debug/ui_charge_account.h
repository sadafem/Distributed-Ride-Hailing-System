/********************************************************************************
** Form generated from reading UI file 'charge_account.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGE_ACCOUNT_H
#define UI_CHARGE_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_charge_account
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *money;
    QLabel *label;

    void setupUi(QDialog *charge_account)
    {
        if (charge_account->objectName().isEmpty())
            charge_account->setObjectName(QStringLiteral("charge_account"));
        charge_account->resize(950, 500);
        buttonBox = new QDialogButtonBox(charge_account);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(400, 550, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        money = new QLineEdit(charge_account);
        money->setObjectName(QStringLiteral("money"));
        money->setGeometry(QRect(60, 90, 113, 22));
        label = new QLabel(charge_account);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 301, 16));

        retranslateUi(charge_account);
        QObject::connect(buttonBox, SIGNAL(accepted()), charge_account, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), charge_account, SLOT(reject()));

        QMetaObject::connectSlotsByName(charge_account);
    } // setupUi

    void retranslateUi(QDialog *charge_account)
    {
        charge_account->setWindowTitle(QApplication::translate("charge_account", "Dialog", 0));
        label->setText(QApplication::translate("charge_account", "How Much Do You Want To Add To Your Credit ?", 0));
    } // retranslateUi

};

namespace Ui {
    class charge_account: public Ui_charge_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGE_ACCOUNT_H
