#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rButtonMan->setChecked(true);

    connect(ui->rButtonWeman, &QRadioButton::clicked, this, [=](){
       qDebug() << "选中女";
    });

    connect(ui->cBox, &QCheckBox::stateChanged, this, [=](int state){
        qDebug() << state;
    });

//    //利用ListWidget写诗
//    QListWidgetItem* item = new QListWidgetItem("锄禾日当午，");
//    //将一行诗放入到ListWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList QList<QString>
    QStringList list;
    list << "锄禾日当午，" << "汗滴禾下土。" << "谁知盘中餐，" << "粒粒皆辛苦。";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
