
05-1	主窗口框架，菜单栏（动作组QActionGroup），
	工具栏（QToolButton），资源文件，
	中心部件（QMdiSubWindow），Dock部件
	状态栏（临时消息，永久部件-标签）
05-2	自定义菜单，QWidgetAction，inherits()判断父部件
05-3	富文本文档，QTextEdit: QTextCursor，QTextDocument
	QTextFrame: 	QTextFrame
			QTextBlock
			QTextTable
			QTextList
	showTextFrame，showTextBlock，setTextFont
05-4	05-3 + 表格，列表，图片
05-5	05-4 + 查找功能：查找文本 ui->textEdit->find
05-6	05-5 + 语法高亮QSyntaxHighlightersetFormat， 
	setFormat匹配正则表达式，富文本支持HTML或者CSS
05-7	桌面上的.txt文本文件拖入程序打开
		QDragEnterEvent
		QDropEvent
05-8	程序内图片鼠标拖动
		QMouseEvent
		QDraEnterEvent
		QDragMoveEvent
		QDropEvent
		QMimeData
		QPainter
05-9	打印文档：打印、打印预览、生成PDF文件
		QPrinter, QPrintDialog, QPrintPreview