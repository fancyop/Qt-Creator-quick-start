#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyButton *button = new MyButton(this);
    button->setText(tr("button"));

    //两个MyButton部件没有指定父部件
    MyButton *button2 = new MyButton;
    MyButton *button3 = new MyButton;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    setLayout(layout);          //在窗口中使用布局管理器

    qDebug()<< children();      //输出所有子部件的列表
}

Widget::~Widget()
{
    delete ui;
    qDebug()<< "delete widget";
}
