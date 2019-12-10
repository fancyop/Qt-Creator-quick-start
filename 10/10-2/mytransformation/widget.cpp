#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //填充界面背景为暗灰色
    painter.fillRect(rect(),Qt::darkGray);
    painter.setPen(QPen(Qt::red,11));
    //绘制一条线段
    painter.drawLine(QPoint(5,6),QPoint(100,99));
    //将坐标系统进行平移，使(200,150)点作为原点
    painter.translate(200,150);
    //开启抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    //重新绘制相同的线段
    painter.drawLine(QPoint(5,6),QPoint(100,99));

    painter.setPen(QPen(Qt::white,2));
    painter.drawLine(QPointF(-100,0),QPointF(100,0));
    painter.drawLine(QPointF(0,-100),QPointF(0,100));
    //平移后的原点
    painter.setPen(QPen(Qt::green,10,Qt::DotLine,Qt::MPenCapStyle,Qt::BevelJoin));
    painter.drawPoint(QPoint(0,0));

    //保存painter的状态
    painter.save();
    //将坐标系统旋转90度
    painter.rotate(90);
    painter.setPen(Qt::cyan);
    //重新绘制相同的线段
    painter.drawLine(QPoint(5,6),QPoint(100,99));
    //恢复painter的状态
    painter.restore();

    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkYellow);
    painter.drawEllipse(QRect(60,-100,50,50));
    painter.shear(1.5,-0.7);
    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(QRect(60,-100,50,50));
}
