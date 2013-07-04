#include "Painter.h"
#include "Singleton.h"
#include "GlobalSettings.h"
#include<assert.h>
Painter::Painter(paint_func &func)
	:window_width(Singleton<GlobalSettings>::instance().window_width),
	window_height(Singleton<GlobalSettings>::instance().window_height)
{
	setColor = func.setColor;
	fillRect = func.fillRect;
}

Painter::~Painter()
{

}

void Painter::paintOnline()
{
	assert(self_data&&other_data);
	setColor(255, 0, 0, 255);
	fillRect(0,0,100,100);
}

void Painter::init()
{

}

void Painter::setData(const TetrisData *self_data, const TetrisData *other_data)
{
	this->self_data = self_data;
	this->other_data = other_data;
}
