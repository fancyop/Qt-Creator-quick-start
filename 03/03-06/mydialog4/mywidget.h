#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

public slots:
    void showChildDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // WIDGET_H
