#include <QApplication>
#include <QWidget>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;

    widget.resize(400, 300);    //设置窗口大小
    widget.move(200, 100);      //设置窗口位置
    widget.show();

    int x = widget.x();
    int y = widget.y();
    //格式化输出可以不添加头文件
    qDebug("x: %d", x);
    qDebug("y: %d", y);

    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();

    //输出流方式需要添加头文件
    qDebug() << "geometry:" << geometry << "frame: " << frame;

    return a.exec();
}
