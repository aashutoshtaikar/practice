TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#QMAKE_CXXFLAGS += -std=gnu++0x -pthread
#QMAKE_CFLAGS += -std=gnu++0x -pthread
#LIBS += -pthread


SOURCES += \
        main.cpp \
    BTree.cpp

HEADERS += \
    BTree.h

