#ifndef MAINWINDOW_H //防止头文件重复包含
#define MAINWINDOW_H

#include <QMainWindow> //包含头文件QWidget窗口类

class MainWindow : public QMainWindow
{
    Q_OBJECT //Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    MainWindow(QWidget *parent = 0); //构造函数
    ~MainWindow(); //析构函数
};

#endif // MAINWINDOW_H
