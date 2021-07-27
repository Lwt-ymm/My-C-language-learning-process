#include "student.h"
#include "QDebug"
student::student(QObject *parent) : QObject(parent)
{

}

void student::treat() {
    qDebug() << "请吃饭" << endl;
}

void student::treat(QString foodname) {
    qDebug() << "请吃" << foodname.toUtf8().data() << endl;
}
