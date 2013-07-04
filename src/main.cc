#include<QtGui/QApplication>
#include"GlobalSettings.h"
#include"MainWindow.h"
int main(int argc, char *argv[])
{
	GlobalSettings &settings = Singleton<GlobalSettings>::instance();
	QApplication app(argc, argv);
	MainWindow window;
	window.setWindowTitle(QObject::tr("Tetris Online"));
	window.resize(settings.window_width, settings.window_height);
	window.show();
	return app.exec();
}
