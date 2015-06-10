#include "Controller.h"
#include "Tetris.h"
#include "TetrisData.h"
#include "Singleton.h"
#include<QtGui/QKeyEvent>
using namespace std;
using namespace std::placeholders;
Controller::Controller()
			:tetris(Singleton<Tetris>::instance())
{

}

Controller::~Controller()
{

}

void Controller::key_press(int key)
{
	if(key == Qt::Key_Escape)
		tetris.select_mode(Tetris::SELECT);
	switch(tetris.get_mode())
	{
		case Tetris::SINGLEGAME:
		case Tetris::ONLINEGAME:
			key_press_playing(key);
			break;
		case Tetris::SELECT:
			key_press_select(key);
			break;
		case Tetris::GAMESETTING:
			key_press_setting(key);
			break;
		default:
			break;
	}
}

void Controller::key_press_playing(int key)
{
	TetrisData *self = tetris.get_self();
	switch(key)
	{
		case Qt::Key_Up:
		case Qt::Key_W:
			self->revolve();
			break;
		case Qt::Key_Down:
		case Qt::Key_S:
			self->move(data::DOWN);
			break;
		case Qt::Key_Left:
		case Qt::Key_A:
			self->move(data::LEFT);
			break;
		case Qt::Key_Right:
		case Qt::Key_D:
			self->move(data::RIGHT);
			break;
		default:
			break;
	}
}

void Controller::key_press_select(int key)
{
	switch(key)
	{
		case Qt::Key_Up:
			if(tetris.get_sub() > Tetris::SINGLEGAME)
				tetris.prev();
			break;
		case Qt::Key_Down:
			if(tetris.get_sub() < Tetris::GAMEEXITING)
				tetris.next();
			break;
		case Qt::Key_Return:
			tetris.select_mode(tetris.get_sub());
			break;
		default:
			break;
	}
}

void Controller::key_press_setting(int key)
{
	tetris.select_mode(Tetris::SELECT);
}

void Controller::on_timer()
{
	int mode = tetris.get_mode();
	if(mode != Tetris::SINGLEGAME && mode != Tetris::ONLINEGAME)
		return;
	TetrisData *self = tetris.get_self();
	if(mode == Tetris::ONLINEGAME)
		tetris.get_other()->init_data();
	if(tetris.get_state()%10 == 0) //game not start
	{
		self->init_data();
		tetris.next();
		return;
	}
	if(!self->fix())
	{
		tetris.restart();
		return;
	}
	self->remove();
	self->move(data::DOWN);
}

