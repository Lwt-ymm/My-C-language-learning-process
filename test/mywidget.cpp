#include "mywidget.h"
#include <QPushButton> //按钮控件的头文件

//命名规范
//类名 首字母大写，单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释 ctrl+/  运行 ctrl+r  编译 ctrl+b 整行移动 ctrl+shift+↑/↓  自动对齐 ctrl+i
//同名之间的.h和.cpp切换 F4

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn=new QPushButton;
    //btn->show();show以顶层方式弹出窗口控件
    //让btn对象 依赖在 MyWidget 窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");

    QPushButton * btn2=new QPushButton("第二个按钮",this);

    //移动按钮
    btn2->move(100,100);

    //点击我的按钮关闭窗口
    //参数1 信号的发送者 参数2 发送的信号（函数地址） 参数3 信号的接受者 参数4 处理的槽函数
    connect( btn2, &QPushButton::clicked, this, &MyWidget::close);

    //重置窗口的大小
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

}

MyWidget::~MyWidget()
{

}
