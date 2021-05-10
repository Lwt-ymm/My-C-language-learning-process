#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //tableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设计水平标头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
    //ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));
    QStringList nameList;
    nameList << "111" << "222" << "333" << "444" << "555";
    QStringList sexList;
    sexList << "男" << "女" << "男" << "女" << "男";
    for(int i = 0; i < 5; i++)
    {
        int column = 0;
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(QString::number(i + 18)));
    }
}

Widget::~Widget()
{
    delete ui;
}
