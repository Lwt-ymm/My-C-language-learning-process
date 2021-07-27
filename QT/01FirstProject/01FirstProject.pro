#-------------------------------------------------
#
# Project created by QtCreator 2021-07-08T13:58:51
#
#-------------------------------------------------

#Qt包含的模块
QT       += core gui

#大于4版本以上包含widget模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#目标 生成的 .exe 文件的名称
TARGET = 01FirstProject
#模板 应用程序模板application
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#源文件
SOURCES += \
        main.cpp \
        mainwindow.cpp

#头文件
HEADERS += \
        mainwindow.h
