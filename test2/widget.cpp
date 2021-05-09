#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

//Teacher 老师类
//Student 学生类
//下课后，老师会触发一个信号，饿了。学生响应信号，请客吃饭

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);
    //创建一个学生对象
    this->st = new Student(this);
    //老师饿了，学生请客的链接
    //connect(zt, &Teacher::hungry, st, &Student::treat);
    //void(Teacher::*TeacherSignal)(QString) = &Teacher::hungry;
    //void(Student::*StudentSignal)(QString) = &Student::treat;
    //connect(zt, TeacherSignal, st, StudentSignal);
    //调用下课函数
    this->classIsOver();

    //点击一个下课按钮再触发下课
    QPushButton * btn = new QPushButton("下课", this);
    //重置窗口大小
    this->resize(600, 400);
    //点击按钮触发下课
    //connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    //无参信号和槽连接
    void(Teacher::*TeacherSignal)(void) = &Teacher::hungry;
    void(Student::*StudentSignal)(void) = &Student::treat;
    connect(zt, TeacherSignal, st, StudentSignal);
    //信号连接信号
    connect(btn, &QPushButton::clicked, zt, TeacherSignal);
    //断开信号
    disconnect(zt, TeacherSignal, st, StudentSignal);

    //利用lambda表达式实现点击按钮关闭窗口
    QPushButton* btn2 = new QPushButton("关闭", this);
    connect(btn2, &QPushButton::clicked, this, [=](){this->close();});


}

void Widget::classIsOver()
{
    //下课函数，调用后触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}
