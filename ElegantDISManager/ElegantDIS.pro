QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lmuduo_net
LIBS += -lmuduo_base
LIBS += -lpthread
LIBS += -ljsoncpp

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    codec.cpp \
    main.cpp \
    hub.cpp \
    pubsubserver.cpp \
    settingwidget.cpp \
    timer.cpp

HEADERS += \
    codec.h \
    hub.h \
    pubsubserver.h \
    settingwidget.h \
    topic.h \
    timer.h

FORMS += \
    hub.ui \
    settingwidget.ui

CONFIG+=debug_and_release
CONFIG(debug, debug|release){
    TARGET = ElegantDISManager
    } else {
    TARGET = ElegantDISManager
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
