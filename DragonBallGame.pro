QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    game.cpp \
    player.cpp \
    enemy.cpp \
    physicsengine.cpp \
    physicsmodel.cpp \
    level.cpp \
    objective.cpp

HEADERS += \
    mainwindow.h \
    game.h \
    player.h \
    enemy.h \
    physicsengine.h \
    physicsmodel.h \
    level.h \
    objective.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc