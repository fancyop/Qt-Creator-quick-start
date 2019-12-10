#include <QtWidgets>
#include <QDialog>
#include <QSplashScreen>
#include <QFrame>
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    //窗口下面创建的label对象

    //默认
//    QLabel * label = new QLabel();
    //无边框
//    QLabel * label = new QLabel(nullptr, Qt::SplashScreen);
    //窗口置顶
    QLabel * label = new QLabel(nullptr, Qt::WindowStaysOnTopHint);

    label->setText(QObject::tr("label: 我是个窗口"));
    label->setWindowTitle(QObject::tr("我是 label"));
    label->resize(300, 20);

    //窗口下创建的widget对象

    //默认对话框
    QWidget * widget = new QWidget();
    //欢迎窗口
//    QWidget * widget = new QWidget(nullptr, Qt::Dialog);
    //无边框窗口
//    QWidget * widget = new QWidget(nullptr, Qt::Dialog | Qt::FramelessWindowHint);

    widget->setWindowTitle(QObject::tr("我是 widget"));

    QLabel * label2 = new QLabel(widget);

    label2->setText(QObject::tr("label2:我不是独立窗口，只是widget的子部件"));
    label2->resize(250, 20);

    label->show();
    widget->show();

//    delete label;
//    delete widget;

    return a.exec();
}
