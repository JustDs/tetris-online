#include "Tetris.h"
#include "TetrisData.h"
Tetris::Tetris()
		:state(0)
{

}

Tetris::~Tetris()
{
	delete self;
	delete other;
}

void Tetris::notify()
{
	for(auto iter = observers.begin(); iter != observers.end(); ++iter)
	{
		(*iter)();
	}
}

void Tetris::regist(regist_func func)
{
	observers.push_back(func);
}

void Tetris::start(int mode)
{
	switch(mode)
	{
		case SINGLEGAME:
			start_single();
		case ONLINEGAME:
			start_online();
		default:
			break;
	}
	notify();
}

void Tetris::start_single()
{
	auto origin = self;
	self = new TetrisData;
	if(origin)
		delete origin;
}

void Tetris::start_online()
{
	auto origin_self = self;
	auto origin_other = other;
	self = new TetrisData;
	other = new TetrisData;
	if(origin_self)
		delete origin_self;
	if(origin_other)
		delete origin_other;
}

