QT += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

SOURCES += \
        main.cpp \
        login.cpp

HEADERS += \
        login.h

FORMS += \
        ../home/home.ui \
        login.ui
