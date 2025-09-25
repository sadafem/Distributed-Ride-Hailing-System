/********************************************************************************
** Form generated from reading UI file 'run.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUN_H
#define UI_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_run
{
public:
    QPushButton *set_status;
    QPushButton *show_trip;
    QPushButton *accept_trip;

    void setupUi(QWidget *run)
    {
        if (run->objectName().isEmpty())
            run->setObjectName(QStringLiteral("run"));
        run->resize(950, 500);
        set_status = new QPushButton(run);
        set_status->setObjectName(QStringLiteral("set_status"));
        set_status->setGeometry(QRect(140, 40, 110, 40));
        show_trip = new QPushButton(run);
        show_trip->setObjectName(QStringLiteral("show_trip"));
        show_trip->setGeometry(QRect(140, 90, 110, 40));
        accept_trip = new QPushButton(run);
        accept_trip->setObjectName(QStringLiteral("accept_trip"));
        accept_trip->setGeometry(QRect(140, 140, 110, 40));

        retranslateUi(run);

        QMetaObject::connectSlotsByName(run);
    } // setupUi

    void retranslateUi(QWidget *run)
    {
        run->setWindowTitle(QApplication::translate("run", "Form", 0));
        set_status->setText(QApplication::translate("run", "set status", 0));
        show_trip->setText(QApplication::translate("run", "show trip", 0));
        accept_trip->setText(QApplication::translate("run", "accept trip", 0));
    } // retranslateUi

};

namespace Ui {
    class run: public Ui_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUN_H
