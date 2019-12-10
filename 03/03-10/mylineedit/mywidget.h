#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>

namespace Ui {
class MyWidget;
}

class MyWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_lineEdit_2_returnPressed();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
