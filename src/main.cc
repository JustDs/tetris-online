#include<QtGui/QApplication>
#include"static/config.h"
#include"MainWindow.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow window;
	window.setWindowTitle(QObject::tr("Tetris Online"));
	window.resize(WINDOW_WIDTH,WINDOW_HEIGHT);
	window.show();
	return app.exec();
}
