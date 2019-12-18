第11章 图形视图、动画和状态机框架
11-01	场景视图
		场景：QGraphicsScene
		视图：QGraphicsView
		setForegroundBrush setBackgroundBrush resize show
11-02	图形项（自定义）
		场景图形项基类：QGraphicsItem
		重新实现的两个纯虚公共函数：boundingRect paint
11-03	坐标系统
		获取鼠标左键单击在视图、场景、和图形项中的坐标，并打印
		QGraphicsScene：setSceneRect
		QGraphicsRectItem：setParentItem setRotation
		QGraphicsView：mousePressEvent setScene
11-04	