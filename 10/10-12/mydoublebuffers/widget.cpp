#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pix = QPixmap(400,300);
    pix.fill(Qt::green);
    tempPix = pix;
    isDrawing = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        startPoint = event->pos();
        isDrawing = true;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton){
        endPoint = event->pos();
        tempPix = pix;
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        endPoint = event->pos();
        isDrawing = false;
        update();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    QPainter painter;
    painter.begin(&tempPix);
    painter.drawRect(x,y,width,height);
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    //如果完成了绘制更新缓冲区
    if(!isDrawing)
        pix = tempPix;
}
