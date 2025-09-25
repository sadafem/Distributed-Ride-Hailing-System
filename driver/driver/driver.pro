#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T22:45:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = driver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client_socket.cpp \
    driver_client.cpp \
    tools.cpp \
    login.cpp \
    driver_register.cpp \
    run.cpp \
    set_status.cpp

HEADERS  += mainwindow.h \
    client_socket.h \
    driver_client.h \
    network_exception.h \
    tools.h \
    login.h \
    driver_register.h \
    run.h \
    set_status.h

FORMS    += mainwindow.ui \
    login.ui \
    driver_register.ui \
    run.ui \
    set_status.ui
