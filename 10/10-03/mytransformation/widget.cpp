#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int side = qMin(width(),height());
    int x = (width()/2);
    int y = (height()/2);
    //设置视口
    painter.setViewport(x,y,side,side);
    painter.setWindow(0, 0, 100, 100);      //设置逻辑坐标起点和将宽高等分个数
    painter.setBrush(Qt::green);
    painter.drawRect(0,0,20,20);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString(" %1, %2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}
