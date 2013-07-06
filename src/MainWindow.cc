#include "MainWindow.h"
#include "Tetris.h"
#include "GlobalSettings.h"
#include "Painter.h"
#include "Controller.h"
#include "ImageLoader.h"
#include<Singleton.h>
#include<assert.h>
#include<QtGui/QKeyEvent>
#ifdef _MSC_VER
	#include<functional>
#else
	#include<tr1/functional>
#endif
using namespace std::tr1;
using namespace std::tr1::placeholders;
MainWindow::MainWindow(QWidget *parents)
				:QGLWidget(parents),
				settings(Singleton<GlobalSettings>::instance()),
				tetris(Singleton<Tetris>::instance())
{
	ctrl = new Controller;
	paint_timer = new QTimer;
	connect(paint_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	process_timer = new QTimer;
	connect(process_timer, SIGNAL(timeout()), this, SLOT(on_process()));
	process_timer -> start(settings.interval);
	paint_func func;
	func.setColor = bind(&MainWindow::setColor, this, _1, _2, _3, _4);
	func.fillRect = bind(&MainWindow::fillRect, this, _1, _2, _3, _4);
	func.loadImage = bind(&MainWindow::loadImage, this, _1);
	func.paintImage = bind(&MainWindow::paintImage, this, _1, _2, _3, _4, _5);
	//TODO:write fillImage and other paind function
	image_loader = new ImageLoader;
	painter = new Painter(func);
	painter->init();
}

MainWindow::~MainWindow()
{
	glDisable(GL_BLEND);
	paint_timer -> stop();
	process_timer -> stop();
	delete paint_timer;
	delete process_timer;
	delete painter;
}

void MainWindow::on_process()
{
	ctrl->on_timer();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	ctrl->key_press(event->key());
}

void MainWindow::initializeGL()
{
	glClearColor(0.0f, 0.0f,0.0f,0.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glEnable(GL_BLEND); //allow alpha
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); //comment setting alpha)
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

void MainWindow::paintImage(int x, int y, int width, int height, unsigned int id)
{
	assert(id_images.size()>id);
	glBindTexture(GL_TEXTURE_2D, id_images.at(id));
	paintImagef(gl_x(x), gl_y(y), gl_width(width), gl_height(height));
}

void MainWindow::paintImagef(float x, float y, float width, float height)
{
	assert(x<=1.0f&&y<=1.0f&&width<=1.0f&&height<=1.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f,0.0f);glVertex3f(x, y, 0.0f);
		glTexCoord2f(0.0f,1.0f);glVertex3f(x, y + height, 0.0f);
		glTexCoord2f(1.0f,1.0f);glVertex3f(x + width, y + height, 0.0f);
		glTexCoord2f(1.0f,0.0f);glVertex3f(x + width, y, 0.0f);
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

unsigned int MainWindow::loadImage(const char *filename)
{
#ifdef _WIN32
	std::string image_file("images\\");
#else
	std::string image_file("images/");
#endif
	image_file += filename;
	unsigned int id = image_loader->load(image_file.c_str());
	id_images.push_back(GLuint(0));
	glGenTextures(1, &id_images[id]);
	glBindTexture(GL_TEXTURE_2D, id_images[id]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	ImageLoader::PNG_PTR image = image_loader->get(id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width,
							image->height, 0, GL_RGBA,
	 						GL_UNSIGNED_BYTE, &image->data[0]);
	return id;
}

