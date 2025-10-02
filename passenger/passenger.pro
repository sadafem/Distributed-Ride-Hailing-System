#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T11:32:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = passenger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client_socket.cpp \
    passenger_client.cpp \
    tools.cpp \
    login.cpp \
    passenger_register.cpp \
    run.cpp \
    charge_account.cpp

HEADERS  += mainwindow.h \
    client_socket.h \
    network_exception.h \
    passenger_client.h \
    tools.h \
    login.h \
    passenger_register.h \
    run.h \
    charge_account.h

FORMS    += mainwindow.ui \
    login.ui \
    passenger_register.ui \
    run.ui \
    charge_account.ui
