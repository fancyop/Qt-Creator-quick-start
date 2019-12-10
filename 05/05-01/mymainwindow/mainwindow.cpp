#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QToolButton"
#include "QSpinBox"
#include "QTextEdit"
#include "QMdiSubWindow"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //代码方式添加菜单栏及其图标到工具栏
    QMenu * editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction * action_Open = editMenu->addAction(
        QIcon(":/image/images/open.png"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->mainToolBar->addAction(action_Open);

    //动作组
    QActionGroup * group = new QActionGroup(this);
    QAction * action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction * action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    //工具栏
    QToolButton * toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu * colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    QSpinBox * spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    //状态栏
    //显示临时消息，显示2000ms
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"), 2000);
    //创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel * permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("www.baidu.com");
    ui->statusBar->addPermanentWidget(permanent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    //中心部件
    QTextEdit * edit = new QTextEdit(this);
    QMdiSubWindow * child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_action_dock_triggered()
{
    //Dock栏
    ui->dockWidget_5->show();
}
