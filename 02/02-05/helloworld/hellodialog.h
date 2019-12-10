#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

namespace Ui {
class HelloDialog;
}

class HelloDialog:public QDialog
{

    Q_OBJECT

public:
    //显示构造函数用来指定父窗口
    explicit HelloDialog(QWidget *parent = nullptr);
    //析构函数
    ~HelloDialog();

private:
    //定义类对象指针
    Ui::HelloDialog *ui;

};

#endif // HELLODIALOG_H
