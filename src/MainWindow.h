#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtOpenGL/QGLWidget>
#include<QTimer>

class MainWindow : public QGLWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parents = 0);
	~MainWindow();

private:
	virtual void initializeGL();
	virtual void resizeGL(int width, int height);
	virtual void paintGL();
	QTimer *timer;
};

#endif

