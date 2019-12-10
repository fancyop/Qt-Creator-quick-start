#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//05-5
class QLineEdit;
class QDialog;
class MySyntaxHighlighter;

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
    //05-3
    void showTextFrame();           //遍历文档框架
    void showTextBlock();           //遍历所有文本块
    void setTextFont(bool checked); //设置字体格式
    //05-4
    void insertTable();             //插入表格
    void insertList();              //插入列表
    void insertImage();             //插入图片
    //05-5
    void textFind();                //查找文本
    void findNext();                //查找下一个
private:
    Ui::MainWindow *ui;
    //05-5
    QLineEdit *lineEdit;
    QDialog *findDialog;
    MySyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H
