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
    QPainterPath path;
    //绘制一条直线
    path.moveTo(50,250);
    path.lineTo(50,230);

    //绘制从当前点和(120,60)直接绘制一条三次贝塞尔曲线
    path.cubicTo(QPointF(50,40),QPointF(115,140),QPointF(120,60));
    path.lineTo(130,130);

    path.addEllipse(QPoint(130,130),30,30);
    painter.setPen(Qt::darkYellow);
    path.translate(200,0);
    painter.setPen(Qt::darkBlue);

    painter.drawPath(path);
}
