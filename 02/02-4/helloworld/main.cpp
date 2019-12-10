#include <QApplication>
#include <QDialog>
#include <QLabel>
#include "ui_hellodialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog w;
    QLabel label(&w);
    w.resize(200, 200);
//    w.setWindowTitle("hello world");
    label.setText("Hello World! 你好 Qt !");
    Ui::HelloDialog ui;
    ui.setupUi(&w);
    w.show();
    return a.exec();
}
