#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->te = new teacher(this);
    this->st = new student(this);
    //connect(te, &teacher::hungry, st, &student::treat);
//    void(teacher::*teacherSignal)(QString) = &teacher::hungry;
//    void(student::*studentSlot)(QString) = &student::treat;
//    connect(te, teacherSignal, st, studentSlot);
//    classIsOver();
    QPushButton *btn = new QPushButton("下课", this);
    void(teacher::*teacherSignal)(void) = &teacher::hungry;
    void(student::*studentSlot)(void) = &student::treat;
    connect(btn, &QPushButton::clicked, te, teacherSignal);
    connect(te, teacherSignal, st, studentSlot);

}

void Widget::classIsOver() {
    //emit te->hungry();
    emit te->hungry("鱼香肉丝");
}

Widget::~Widget()
{

}
