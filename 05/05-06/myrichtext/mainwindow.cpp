#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextFrame"
#include "QtDebug"
#include "QLineEdit"
#include "QDialog"
#include "QPushButton"
#include "QVBoxLayout"
#include "mysyntaxhighlighter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTextFrame
    QTextDocument *document = ui->textEdit->document(); //获取文档对象
    QTextFrame *rootFrame = document->rootFrame();      //获取根框架
    QTextFrameFormat format;                            //创建框架格式
    format.setBorderBrush(Qt::red);                     //边界颜色
    format.setBorder(3);                                //边界宽度
    rootFrame->setFrameFormat(format);                  //框架使用格式
    //QTextCursor
    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::yellow);              //设置背景颜色
    frameFormat.setMargin(10);                          //设置边距
    frameFormat.setPadding(10);                         //设置填衬
    frameFormat.setBorder(20);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Inset);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);

    QAction *action_textFrame = new QAction(tr("框架"), this);
    connect(action_textFrame, &QAction::triggered, this, &MainWindow::showTextFrame);
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction(tr("文本块"), this);
    connect(action_textBlock, &QAction::triggered, this, &MainWindow::showTextBlock);
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("字体"), this);
    action_font->setCheckable(true);
    connect(action_font, &QAction::toggled, this, &MainWindow::setTextFont);
    ui->mainToolBar->addAction(action_font);


    QAction *action_textTable = new QAction(tr("表格"), this);
    connect(action_textTable, &QAction::triggered, this, &MainWindow::insertTable);
    ui->mainToolBar->addAction(action_textTable);

    QAction *action_textList = new QAction(tr("列表"), this);
    connect(action_textList, &QAction::triggered, this, &MainWindow::insertList);
    ui->mainToolBar->addAction(action_textList);

    QAction *action_textImage = new QAction(tr("图片"), this);
    connect(action_textImage, &QAction::triggered, this, &MainWindow::insertImage);
    ui->mainToolBar->addAction(action_textImage);

    QAction *action_textFind  = new QAction(tr("查找"), this);
    connect(action_textFind, &QAction::triggered, this, &MainWindow::textFind);
    ui->mainToolBar->addAction(action_textFind);

    findDialog = new QDialog(this);                         //创建对话框
    lineEdit = new QLineEdit(findDialog);                   //创建行编辑器
    QPushButton *btn = new QPushButton(findDialog);         //创建按钮
    btn->setText(tr("查找下一个"));
    connect(btn, &QPushButton::clicked, this, &MainWindow::findNext);
    QVBoxLayout *layout = new QVBoxLayout;                  //添加垂直布局管理器
    layout->addWidget(lineEdit);                            //添加部件
    layout->addWidget(btn);
    findDialog->setLayout(layout);                          //在对话框中使用布局管理器

    highlighter = new MySyntaxHighlighter(ui->textEdit->document());
    ui->textEdit->append(tr("<h1><font color=red>使用HTML</font></h1>"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()        //遍历框架
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    QTextFrame::iterator it;
    for(it = frame->begin(); !(it.atEnd()); ++it){
        QTextFrame *childFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if(childFrame){
            qDebug()<< "frame";
        }
        else if(childBlock.isValid()){
            qDebug()<< "block:" << childBlock.text();
        }
    }
}

void MainWindow::showTextBlock()        //遍历文本块
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i<document->blockCount(); i++){
        qDebug()<< tr("文本块%1,文本块首行行号为：%2,长度为：%3,内容为：")
                   .arg(i).arg(block.firstLineNumber()).arg(block.length())
                << block.text();
        block = block.next();                   //获取下一文本块
    }
}

void MainWindow::setTextFont(bool checked)              //设置字体格式
{
    if(checked){                                        //如果处于选中状态
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;                   //文本块格式
        blockFormat.setAlignment(Qt::AlignCenter);      //水平居中
        cursor.insertBlock(blockFormat);                //使用文本块格式
        QTextCharFormat charFormat;                     //字符格式
        charFormat.setBackground(Qt::lightGray);        //背景色
        charFormat.setForeground(Qt::blue);             //前景色-即字体颜色
        charFormat.setFont(QFont(tr("宋体"), 12, QFont::Bold, true));
        charFormat.setFontUnderline(true);              //使用下划线
        cursor.setCharFormat(charFormat);               //使用字符格式
        cursor.insertText(tr("测试字体"));
    }
    else
    {/** 恢复默认的字体格式 **/}
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;                            //表格格式
    format.setCellSpacing(2);                           //表格外边白
    format.setCellPadding(10);                          //表格内边白
    cursor.insertTable(2,2,format);                     //插入2行2列表格
}

void MainWindow::insertList()
{
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);      //列表格式
    ui->textEdit->textCursor().insertList(format);      //数字编号
}

void MainWindow::insertImage()
{
    QTextImageFormat format;
    format.setName("../myrichtext/logo.png");
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::textFind()                             //查找文本
{
      findDialog->show();
}

void MainWindow::findNext()                             //查找下一个
{
    QString string = lineEdit->text();
    //使用查找函数查找指定字符串，查找方式为向后查找
    bool isfind = ui->textEdit->find(string, QTextDocument::FindBackward);
    /*
     *      bool isfind = ui->textEdit->find(string);   //默认查找方式为向前查找
     *      FindBackward            向后查找
     *      FindCaseSensitively     不区分大小写
     *      FindWholeWords          匹配整个单词
     *      行号，列号都是从0号开始编号
     */
    if(isfind){
        qDebug()<< tr("行号：%1 列号：%2")
                   .arg(ui->textEdit->textCursor().blockNumber())
                   .arg(ui->textEdit->textCursor().columnNumber());
    }
}
