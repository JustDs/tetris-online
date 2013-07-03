#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtOpenGL/QGLWidget>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parents);

private:
	virtual void initializeGL();
	virtual void resizeGL();
	virtual void paintGL();
};

#endif

