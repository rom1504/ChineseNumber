QT       += core

TEMPLATE = lib
CONFIG+= staticlib
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR


SOURCES += chinesenumber.cpp \

HEADERS  +=  chinesenumber.h \

QMAKE_CXXFLAGS += -std=c++11

