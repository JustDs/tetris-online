SOURCES += \
		src/main.cc \
		src/MainWindow.cc \
		src/GlobalSettings.cc \
		src/Painter.cc \
		src/TetrisData.cc \
		src/Tetris.cc
HEADERS += \
		src/MainWindow.h \
		src/static/config.h \
		src/GlobalSettings.h \
		src/Painter.h \
		src/TetrisData.h \
		src/Tetris.h
FORMS += \

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ./include \

QT += \
	opengl
CONFIG += qt debug
