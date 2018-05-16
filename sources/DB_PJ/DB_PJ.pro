#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T14:35:21
#
#-------------------------------------------------

QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB_PJ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    db.cpp \
    session.cpp \
    login.cpp \
    problems.cpp \
    editproblem.cpp

HEADERS  += mainwindow.h \
    db.h \
    config.h \
    tables.h \
    session.h \
    login.h \
    problems.h \
    editproblem.h

FORMS    += mainwindow.ui \
    login.ui \
    problems.ui \
    editproblem.ui

DISTFILES +=
