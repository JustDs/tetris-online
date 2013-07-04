SOURCES += \
		src/main.cc \
		src/MainWindow.cc \
		src/GlobalSettings.cc \
		src/Painter.cc
HEADERS += \
		src/MainWindow.h \
		src/static/config.h \
		src/GlobalSettings.h \
		src/Painter.h
FORMS += \

INCLUDEPATH += ./include \

QT += \
	opengl
CONFIG += qt debug
