QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    manage.cpp \
    manage_login.cpp \
    stu.cpp \
    stu_changepwd.cpp \
    stu_choose.cpp \
    stu_del.cpp \
    stu_main.cpp \
    stu_regis.cpp \
    tea.cpp \
    tea_add.cpp \
    tea_changepwd.cpp \
    tea_del.cpp \
    tea_give.cpp \
    tea_main.cpp \
    tea_regis.cpp

HEADERS += \
    global.h \
    mainwindow.h \
    manage.h \
    manage_login.h \
    stu.h \
    stu_changepwd.h \
    stu_choose.h \
    stu_del.h \
    stu_main.h \
    stu_regis.h \
    tea.h \
    tea_add.h \
    tea_changepwd.h \
    tea_del.h \
    tea_give.h \
    tea_main.h \
    tea_regis.h

FORMS += \
    mainwindow.ui \
    manage.ui \
    manage_login.ui \
    stu.ui \
    stu_changepwd.ui \
    stu_choose.ui \
    stu_del.ui \
    stu_main.ui \
    stu_regis.ui \
    tea.ui \
    tea_add.ui \
    tea_changepwd.ui \
    tea_del.ui \
    tea_give.ui \
    tea_main.ui \
    tea_regis.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
