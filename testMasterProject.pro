#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T11:18:32
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testMasterProject
TEMPLATE = app


VERSION = 1.0.0
QMAKE_TARGET_COMPANY = GatesB Co
QMAKE_TARGET_PRODUCT = AIS University
QMAKE_TARGET_COPYRIGHT = Bon Alexey Mihailovich

SOURCES += main.cpp\
        mainmenu.cpp \
    settingmenu.cpp \
    lookdatabase.cpp \
    filterdialog.cpp \
    ubd_faculty.cpp \
    ubdc_ranks.cpp \
    createschedule.cpp \
    ubd_subject.cpp \
    ubdc_schedulealarm.cpp \
    ubdc_week.cpp \
    ubd_lecturehalls.cpp \
    ubd_groups.cpp \
    ubd_teachers.cpp \
    ubd_subjectteacher.cpp \
    res_schedule.cpp \
    genetic.cpp

HEADERS  += mainmenu.h \
    settingmenu.h \
    lookdatabase.h \
    filterdialog.h \
    ubd_faculty.h \
    ubdc_ranks.h \
    createschedule.h \
    ubd_subject.h \
    ubdc_schedulealarm.h \
    ubdc_week.h \
    ubd_lecturehalls.h \
    ubd_groups.h \
    ubd_teachers.h \
    ubd_subjectteacher.h \
    res_schedule.h \
    genetic.h

FORMS    += mainmenu.ui \
    settingmenu.ui \
    lookdatabase.ui \
    createschedule.ui

RESOURCES += \
    image.qrc

RC_FILE = iconFile.rc

