#-------------------------------------------------
#
# Project created by QtCreator 2013-07-03T11:49:25
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = bin/tst_chinesenumbertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR

SOURCES +=  tst_chinesenumbertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"


QMAKE_CXXFLAGS += -std=c++11

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ChineseNumberLib/release/ -lChineseNumberLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ChineseNumberLib/debug/ -lChineseNumberLib
else:unix: LIBS += -L$$OUT_PWD/../ChineseNumberLib/ -lChineseNumberLib

INCLUDEPATH += $$PWD/../ChineseNumberLib
DEPENDPATH += $$PWD/../ChineseNumberLib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ChineseNumberLib/release/libChineseNumberLib.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ChineseNumberLib/debug/libChineseNumberLib.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../ChineseNumberLib/libChineseNumberLib.a
