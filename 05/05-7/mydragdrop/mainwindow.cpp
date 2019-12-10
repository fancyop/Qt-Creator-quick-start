#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QFile>
#include <QMimeData>
#include <QTextStream>
#include <QDragEnterEvent>
#include <QDropEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //允许主窗口接受数据，将文件拖入主窗口界面（不是里面的Text Edit部件中，拖入部件中只有文件路径）
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) //拖入事件
{
    if(event->mimeData()->hasUrls())    // 数据中是否包含URL
        event->acceptProposedAction();  // 如果是则接受动作
    else event->ignore();               // 否，则忽略该事件
}

void MainWindow::dropEvent(QDropEvent *event)   //放下事件
{
    const QMimeData *mimeData = event->mimeData();          //获取MIME数据
    if(mimeData->hasUrls()){                                //如果数据中包含URL
        QList <QUrl> urlList = mimeData->urls();            //获取URL列表
        // 将其中第一个URL表示为本地文件路径
        QString fileName = urlList.at(0).toLocalFile();
        if(!fileName.isEmpty()){                            //如果文件路径不为空
            QFile file(fileName);           //建立QFILE对象并且以支付方式打开文件
            if(!file.open(QIODevice::ReadOnly)) return;
            QTextStream in(&file);                          //建立文本流对象
            ui->textEdit->setText(in.readAll());        //将文件中所有内容读入编辑器
        }
    }
}
