#include "myview.h"
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QDebug>
MyView::MyView(QWidget *parent):QGraphicsView (parent)
{

}

void MyView::mousePressEvent(QMouseEvent *event)
{
    //获取鼠标左键单击在视图、场景、和图形项中的坐标，并打印
    QPoint viewPos = event->pos();
    qDebug()<< "viewPos"<<viewPos;
    QPointF scenePos = mapToScene(viewPos);
    qDebug()<< "scenePos: "<<scenePos;

    QGraphicsItem *item = scene()->itemAt(scenePos, QTransform());
    if(item) {
        QPointF itemPos = item->mapFromScene(scenePos);
        qDebug()<<"itemPos: "<< itemPos;
    }
}
