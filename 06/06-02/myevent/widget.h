#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class MyLineEdit;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject *obj, QEvent *event);
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Widget *ui;
    MyLineEdit *lineEdit;
};

#endif // WIDGET_H
