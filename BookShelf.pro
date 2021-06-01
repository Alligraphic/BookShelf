QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Login.cpp \
    addbook.cpp \
    data.cpp \
    deletebooks.cpp \
    lendbook.cpp \
    main.cpp \
    mainwindow.cpp \
    signup.cpp

HEADERS += \
    Login.h \
    addbook.h \
    data.h \
    deletebooks.h \
    lendbook.h \
    mainwindow.h \
    signup.h

FORMS += \
    Login.ui \
    addbook.ui \
    deletebooks.ui \
    lendbook.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
