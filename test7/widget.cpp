#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treeWidget树控件的使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    //加载顶层的节点
    QTreeWidgetItem* llitem = new QTreeWidgetItem(QStringList() << "力量型");
    QTreeWidgetItem* mjitem = new QTreeWidgetItem(QStringList() << "敏捷型");
    QTreeWidgetItem* zhitem = new QTreeWidgetItem(QStringList() << "智慧型");
    ui->treeWidget->addTopLevelItem(llitem);
    ui->treeWidget->addTopLevelItem(mjitem);
    ui->treeWidget->addTopLevelItem(zhitem);
    //追加子节点
    //QStringList heroL1;
    //heroL1 << "刚背猪" << "前排坦克，能在吸收伤害的同时造成可观的伤害输出";
    QTreeWidgetItem* ll1 = new QTreeWidgetItem(QStringList() << "刚背猪" << "前排坦克，能在吸收伤害的同时造成可观的伤害输出");
    llitem->addChild(ll1);
}

Widget::~Widget()
{
    delete ui;
}
