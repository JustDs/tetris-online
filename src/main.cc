#include<QtGui/QApplication>
#include"MainWindow.h"
enum
{
	WINDOW_WIDTH = 800,
	WINDOW_HEIGHT = 600
};
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow window;
	window.setWindowTitle(QObject::tr("Tetris Online"));
	window.resize(WINDOW_WIDTH,WINDOW_HEIGHT);
	window.show();
	return app.exec();
}
