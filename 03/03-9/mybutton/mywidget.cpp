#include "mywidget.h"
#include "ui_mywidget.h"
#include <QtDebug>
#include <QMenu>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->pushButton_1->setText(tr("&nihao"));    //指定Alt+N为加速键
    ui->pushButton_2->setText(tr("帮助(&H)"));
    ui->pushButton_2->setIcon(QIcon("../mybutton/help.png"));
    ui->pushButton_3->setText(tr("z&oom"));
    QMenu * menu = new QMenu(this);
    menu->addAction(QIcon("../mybutton/zoom-in.png"), tr("放大"));
    ui->pushButton_3->setMenu(menu);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_1_toggled(bool checked)
{
    qDebug()<< tr("按钮1是否被按下：") << checked;
}
