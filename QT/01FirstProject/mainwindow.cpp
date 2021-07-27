#include "mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *btn1 = new QPushButton;
    //btn->show(); //show以顶层方式弹出窗口控件
    btn1->setParent(this); //设置父亲，让btn对象依赖在myWight窗口中
    btn1->setText("第一个按钮"); //显示文本
    QPushButton *btn2 = new QPushButton("第二个按钮", this);
    btn1->resize(100, 25);
    btn2->move(100, 100);
    resize(600, 400);
    setFixedSize(600, 400);
    setWindowTitle("第一个窗口");
    connect(btn2, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{

}
