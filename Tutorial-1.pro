QT += core
QT -= gui

CONFIG += c++11

TARGET = Tutorial-1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    scanner.cpp \
    scanner_driver.cpp

HEADERS += \
    exception.h \
    scanner.h
