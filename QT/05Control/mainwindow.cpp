#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButtonMan->setChecked(true);
    connect(ui->radioButtonWomen, &QRadioButton::clicked, [=](){
        qDebug() << "选中女" << endl;
    });

    QListWidgetItem *item = new QListWidgetItem("汗滴禾下土。");
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignRight);
    QStringList items;
    items << "谁知盘中餐，" << "粒粒皆辛苦。";
    ui->listWidget->addItems(items);

    ui->treeWidget->setHeaderLabels(QStringList() << "英雄名称" << "英雄介绍");
    QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    QTreeWidgetItem *minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    ui->treeWidget->addTopLevelItem(minItem);
    QTreeWidgetItem *l1 = new QTreeWidgetItem(QStringList() << "L1" << "111111111111");
    liItem->addChild(l1);

    ui->stackedWidget->setCurrentIndex(2);
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_toolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_tabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
