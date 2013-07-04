#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtOpenGL/QGLWidget>
#include<QTimer>
class GlobalSettings;
class Painter;

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
	
	void setColor(int R, int G, int B, int A);
	void fillRect(int x, int y, int width, int height);
	void fillRectf(float x, float y, float width, float height);
	
	// current coordinate to opengl coordinate
	float gl_x(int x);
	float gl_y(int y);
	float gl_width(int width);
	float gl_height(int height);
	float gl_color(int c);

	QTimer *timer;
	Painter *painter;
	GlobalSettings &settings;
};

#endif

