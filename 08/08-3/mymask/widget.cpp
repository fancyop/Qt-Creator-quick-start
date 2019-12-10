#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pixmap(":/image/gouzi.jpg");
//    ui->label->setPixmap(pixmap);
//    ui->label->setMask(pixmap.mask());

    QPixmap pix;
    //加载图片
    pix.load(":/image/gouzi.jpg");
    //设置窗口大小为图片大小
    resize(pix.size());
    //为窗口设置遮罩
    setMask(pix.mask());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //从窗口左上角开始绘制图片
    painter.drawPixmap(0,0,QPixmap(":/image/gouzi.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *)
{
    //关闭窗口
    close();
}
