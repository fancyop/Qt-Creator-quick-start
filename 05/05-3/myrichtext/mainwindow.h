#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void showTextFrame();           //遍历文档框架
    void showTextBlock();           //遍历所有文本块
    void setTextFont(bool checked); //设置字体格式
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
