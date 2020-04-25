QT -= qt core gui

TARGET = KitsunemimiObj
CONFIG += c++14
TEMPLATE = lib
VERSION = 0.1.0

LIBS += -L../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../libKitsunemimiCommon/include

LIBS += -L../../libKitsunemimiPersistence/src -lKitsunemimiPersistence
LIBS += -L../../libKitsunemimiPersistence/src/debug -lKitsunemimiPersistence
LIBS += -L../../libKitsunemimiPersistence/src/release -lKitsunemimiPersistence
INCLUDEPATH += ../../libKitsunemimiPersistence/include

LIBS +=  -lboost_filesystem -lboost_system

INCLUDEPATH += $$PWD \
            $$PWD/../include

SOURCES += \
    obj_item.cpp \
    obj_parser.cpp \
    obj_creator.cpp

HEADERS += \
    ../include/libKitsunemimiObj/obj_item.h \
    obj_parser.h \
    obj_creator.h
