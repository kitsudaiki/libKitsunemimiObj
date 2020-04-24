include(../defaults.pri)

QT -= qt core gui

CONFIG   -= app_bundle
CONFIG += c++14 console

LIBS += -L../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../libKitsunemimiCommon/include

LIBS += -L../../libKitsunemimiPersistence/src -lKitsunemimiPersistence
LIBS += -L../../libKitsunemimiPersistence/src/debug -lKitsunemimiPersistence
LIBS += -L../../libKitsunemimiPersistence/src/release -lKitsunemimiPersistence
INCLUDEPATH += ../../libKitsunemimiPersistence/include

LIBS +=  -lboost_filesystem -lboost_system

INCLUDEPATH += $$PWD

LIBS += -L../src -lKitsunemimiObj

SOURCES += \
        main.cpp \
        objConverterTest.cpp

HEADERS += \
        objConverterTest.h
