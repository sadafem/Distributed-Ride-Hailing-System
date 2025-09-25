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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_run
{
public:
    QPushButton *menu;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *discout_code;
    QPushButton *charge_account;
    QPushButton *log_out;
    QLineEdit *start;
    QLineEdit *end;
    QLabel *label;
    QLabel *label_2;
    QPushButton *request;
    QPushButton *estimate;

    void setupUi(QWidget *run)
    {
        if (run->objectName().isEmpty())
            run->setObjectName(QStringLiteral("run"));
        run->resize(950, 500);
        menu = new QPushButton(run);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(30, 10, 101, 31));
        scrollArea = new QScrollArea(run);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(29, 40, 161, 241));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 159, 239));
        discout_code = new QPushButton(scrollAreaWidgetContents);
        discout_code->setObjectName(QStringLiteral("discout_code"));
        discout_code->setGeometry(QRect(0, 10, 161, 41));
        charge_account = new QPushButton(scrollAreaWidgetContents);
        charge_account->setObjectName(QStringLiteral("charge_account"));
        charge_account->setGeometry(QRect(0, 90, 161, 41));
        log_out = new QPushButton(scrollAreaWidgetContents);
        log_out->setObjectName(QStringLiteral("log_out"));
        log_out->setGeometry(QRect(0, 170, 161, 41));
        scrollArea->setWidget(scrollAreaWidgetContents);
        start = new QLineEdit(run);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(410, 260, 241, 51));
        end = new QLineEdit(run);
        end->setObjectName(QStringLiteral("end"));
        end->setGeometry(QRect(410, 320, 241, 51));
        label = new QLabel(run);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 270, 151, 31));
        label_2 = new QLabel(run);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 320, 151, 51));
        request = new QPushButton(run);
        request->setObjectName(QStringLiteral("request"));
        request->setGeometry(QRect(410, 410, 110, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        request->setFont(font);
        estimate = new QPushButton(run);
        estimate->setObjectName(QStringLiteral("estimate"));
        estimate->setGeometry(QRect(540, 410, 110, 40));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        estimate->setFont(font1);

        retranslateUi(run);

        QMetaObject::connectSlotsByName(run);
    } // setupUi

    void retranslateUi(QWidget *run)
    {
        run->setWindowTitle(QApplication::translate("run", "Form", 0));
        menu->setText(QApplication::translate("run", "menu", 0));
        discout_code->setText(QApplication::translate("run", "Discount Code", 0));
        charge_account->setText(QApplication::translate("run", "Charge Account", 0));
        log_out->setText(QApplication::translate("run", "Log out", 0));
        label->setText(QApplication::translate("run", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00ffff;\">Current Place</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("run", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00ffff;\">Destinations</span></p></body></html>", 0));
        request->setText(QApplication::translate("run", "Request", 0));
        estimate->setText(QApplication::translate("run", "Estimate", 0));
    } // retranslateUi

};

namespace Ui {
    class run: public Ui_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUN_H
