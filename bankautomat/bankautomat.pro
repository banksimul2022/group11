QT       += core gui
QT       += network
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tilakone.cpp

HEADERS += \
    mainwindow.h \
    tilakone.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/build-RFID125-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/release/ -lRFID125
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/build-RFID125-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lRFID125
else:unix: LIBS += -L$$PWD/libraries/build-RFID125-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/ -lRFID125

INCLUDEPATH += $$PWD/libraries/DLL-RFID
DEPENDPATH += $$PWD/libraries/DLL-RFID

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/build-DLLRestAPI-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/release/ -lDLLRestAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/build-DLLRestAPI-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lDLLRestAPI

INCLUDEPATH += $$PWD/libraries/DLLRestAPI
DEPENDPATH += $$PWD/libraries/DLLRestAPI
