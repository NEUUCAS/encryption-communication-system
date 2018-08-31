#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T21:51:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cipher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    caesar.cpp \
    keyword.cpp \
    connection.cpp \
    socket_cli.cpp \
    socket_ser.cpp \
    exchange.cpp \
    autokey.cpp \
    double_trans.cpp \
    playfair.cpp \
    rc4.cpp \
    vigenere.cpp \
    rsa.cpp \
    generation.cpp \
    des.cpp \
    column.cpp \
    ca.cpp

HEADERS  += mainwindow.h \
    caesar.h \
    keyword.h \
    connection.h \
    socket_cli.h \
    socket_ser.h \
    exchange.h \
    autokey.h \
    double_trans.h \
    playfair.h \
    rc4.h \
    vigenere.h \
    rsa.h \
    generation.h \
    des.h \
    column.h \
    ca.h

FORMS    += mainwindow.ui \
    connection.ui \
    exchange.ui \
    generation.ui
LIBS+=-lws2_32
