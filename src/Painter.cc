#include "Painter.h"
Painter::Painter(paint_func &func)
{
	setColor = func.setColor;
	fillRect = func.fillRect;
}

Painter::~Painter()
{

}

void Painter::paint()
{
	setColor(255, 0, 0, 255);
	fillRect(0,0,100,100);
}

void Painter::init()
{

}

