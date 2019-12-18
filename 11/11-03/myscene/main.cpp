#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QGraphicsView>
#include <myitem.h>
#include <myview.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //新建场景
    QGraphicsScene scene;
    scene.setSceneRect(0,0,400,300);
    //创建矩形图形项
    MyItem *item = new MyItem;

    //将图形项添加到场景中
    scene.addItem(item);
    item->setPos(10,10);
//    item->setZValue(1);             //将item置于rectItem上层，默认ZValue为0
    QGraphicsRectItem *rectItem = scene.addRect(QRect(0,0,100,100),QPen(Qt::blue),QBrush(Qt::green));
    rectItem->setPos(20,20);
    item->setParentItem(rectItem);  //item设置为rectItem的子图形项，在其内部显示
    rectItem->setRotation(45);      //rectItem旋转45度

    //为场景创建视图
    MyView view;
    view.setScene(&scene);
    view.setForegroundBrush(QColor(255,255,0,100));
    view.setBackgroundBrush(QPixmap("../myscene/background.png"));
    view.resize(800,500);
    view.show();

    return app.exec();
}
