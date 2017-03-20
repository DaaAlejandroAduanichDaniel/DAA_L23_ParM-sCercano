TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    algorithm.cpp \
    brute.cpp \
    divide.cpp \
    plane.cpp \
    point.cpp \
    Tests/tests.cpp

HEADERS += \
    algorithm.h \
    brute.h \
    divide.h \
    plane.h \
    point.h
