#include "MainWindow.h"
#include<assert.h>
#include "static/config.h"

MainWindow::MainWindow(QWidget *parents)
				:QGLWidget(parents)
{
	timer = new QTimer;
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
}

MainWindow::~MainWindow()
{
	timer -> stop();
	delete timer;
}

void MainWindow::initializeGL()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	setAutoBufferSwap(false); //swap buffer by hand(timer)
	assert(doubleBuffer()); //must be double buffer

	timer -> start(1000.0f/MAX_FRAMES); //updateGL every few milliseconds
}

void MainWindow::resizeGL(int width, int height)
{
}

void MainWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	swapBuffers();
}
