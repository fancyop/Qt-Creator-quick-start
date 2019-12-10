#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);       //鼠标按下事件
    void dragEnterEvent(QDragEnterEvent *event);    //拖动进入事件
    void dragMoveEvent(QDragMoveEvent *event);      //拖动事件
    void dropEvent(QDropEvent *event);              //放下事件
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
