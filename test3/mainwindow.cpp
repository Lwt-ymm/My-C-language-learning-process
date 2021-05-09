#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600, 400);
    //菜单栏创建  最多只能有一个
    QMenuBar* bar = menuBar();
    //将菜单栏放入到窗口中
    setMenuBar(bar);
    //创建菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");
    //创建菜单项
    QAction* newAction = fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    QAction* openAction = fileMenu->addAction("打开");
    //创建编辑项
    editMenu->addAction("粘贴");
    //添加分隔符
    editMenu->addSeparator();
    editMenu->addAction("全选");

    //创建工具栏 可以有多个
    QToolBar* toolbar = new QToolBar(this);
    //将工具栏放入到窗口中
    addToolBar(Qt::LeftToolBarArea, toolbar);
    //后期设置只允许左右移动
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolbar->setFloatable(false);
    //设置移动（总开关）
    toolbar->setMovable(true);
    //设置工具栏内容
    toolbar->addAction(newAction);
    //添加分割线
    toolbar->addSeparator();
    toolbar->addAction(openAction);
    //添加控件
    QPushButton* btn = new QPushButton("略略略", this);
    toolbar->addWidget(btn);

    //创建状态栏 最多只能有一个
    QStatusBar* statuBar = new QStatusBar();
    //将状态栏放入到窗口中
    setStatusBar(statuBar);
    //添加状态栏控件
    QLabel* lable = new QLabel("左侧", this);
    statuBar->addWidget(lable);
    QLabel* lable2 = new QLabel("右侧", this);
    statuBar->addPermanentWidget(lable2);

    //铆接部件（浮动窗口）可以有多个
    QDockWidget* dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    //设置后期停靠只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //中心部件
    QTextEdit* text = new QTextEdit(this);
    setCentralWidget(text);
}

MainWindow::~MainWindow()
{

}
