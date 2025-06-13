QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    direction.cpp \
    fileutils.cpp \
    main.cpp \
    mainwindow.cpp \
    maze.cpp \
    mazetraverser.cpp \
    micromouse.cpp \
    painter.cpp \
    properties.cpp \
    tile.cpp \
    traversingStrategies/turnleftstrategy.cpp \
    traversingStrategies/turnright.cpp \
    traversingstrategy.cpp

HEADERS += \
    direction.h \
    fileutils.h \
    mainwindow.h \
    maze.h \
    mazetraverser.h \
    micromouse.h \
    painter.h \
    properties.h \
    tile.h \
    traversingStrategies/turnleftstrategy.h \
    traversingStrategies/turnright.h \
    traversingstrategy.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test.txt \
    traversingStrategies/bmptest.bmp
