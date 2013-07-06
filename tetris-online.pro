SOURCES += \
		src/main.cc \
		src/MainWindow.cc \
		src/GlobalSettings.cc \
		src/Painter.cc \
		src/TetrisData.cc \
		src/TetrisDataLogic.cc \
		src/Tetris.cc \
		src/BoxToArray.cc \
		src/Controller.cc \
		src/ImageLoader.cc
HEADERS += \
		src/MainWindow.h \
		src/static/config.h \
		src/GlobalSettings.h \
		src/Painter.h \
		src/TetrisData.h \
		src/Tetris.h \
		src/Controller.h \
		src/ImageLoader.h

SOURCES += \
		lib/lodepng.cc
FORMS += \

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ./include \

QT += \
	opengl
CONFIG += qt debug
