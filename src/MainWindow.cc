#include "MainWindow.h"
#include "Tetris.h"
#include "GlobalSettings.h"
#include "Painter.h"
#include<Singleton.h>
#include<assert.h>
#ifdef _WIN32
	#include<functional>
#else
	#include<tr1/functional>
#endif
using namespace std::tr1;
using namespace std::tr1::placeholders;
MainWindow::MainWindow(QWidget *parents)
				:QGLWidget(parents),
				settings(Singleton<GlobalSettings>::instance()),
				tetris(Singleton<Tetris>::instance()),
				ctrl()
{
	paint_timer = new QTimer;
	connect(paint_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	process_timer = new QTimer;
	connect(process_timer, SIGNAL(timeout()), this, SLOT(on_process()));
	process_timer -> start(settings.interval);
	paint_func func;
	func.setColor = bind(&MainWindow::setColor, this, _1, _2, _3, _4);
	func.fillRect = bind(&MainWindow::fillRect, this, _1, _2, _3, _4);
	//TODO:write fillImage and other paind function
	painter = new Painter(func);
	painter->init();
}

MainWindow::~MainWindow()
{
	timer -> stop();
	delete timer;
	delete painter;
}

void MainWindow::on_process()
{
	ctrl.on_timer();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	ctrl.key_press(event->key());
}

void MainWindow::initializeGL()
{
	glClearColor(0.0f, 0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	setAutoBufferSwap(false); //swap buffer by hand(timer)
	assert(doubleBuffer()); //must be double buffer

	paint_timer -> start(1000.0f/settings.max_frames); //updateGL every few milliseconds
}

void MainWindow::resizeGL(int width, int height)
{
	settings.window_width = width;
	settings.window_height = height;
	glViewport(0, 0, width, height);
}

void MainWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//next line is a temporary to test
	painter->setData(tetris.get_self(), tetris.get_other());
	painter->paintOnline();
	swapBuffers();
}

void MainWindow::setColor(int R, int G, int B, int A)
{
	glColor4f(gl_color(R), gl_color(G), gl_color(B), gl_color(A));
}

void MainWindow::fillRect(int x, int y, int width, int height)
{
	fillRectf(gl_x(x), gl_y(y), gl_width(width), gl_height(height));
}

void MainWindow::fillRectf(float x, float y, float width, float height)
{
	assert(x<=1.0f&&y<=1.0f&&width<=1.0f&&height<=1.0f);
	glBegin(GL_POLYGON);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x, y + height, 0.0f);
		glVertex3f(x + width, y + height, 0.0f);
		glVertex3f(x + width, y, 0.0f);
	glEnd();
}

float MainWindow::gl_x(int x)
{
	return static_cast<float>(x)*2/settings.window_width - 1.0f;
}

float MainWindow::gl_y(int y)
{
	return 1.0f-static_cast<float>(y)*2/settings.window_height;
}

float MainWindow::gl_width(int width)
{
	return static_cast<float>(width)*2/settings.window_width;
}

float MainWindow::gl_height(int height)
{
	return -static_cast<float>(height)*2/settings.window_height;
}

float MainWindow::gl_color(int c)
{
	return static_cast<float>(c)/255;
}
