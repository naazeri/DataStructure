TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    database.cpp \
    person.cpp \
    team.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    database.h \
    list.h \
    person.h \
    team.h
