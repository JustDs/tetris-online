#include "Controller.h"
#include "Tetris.h"
#include "TetrisData.h"
#include "Singleton.h"
#include<QtGui/QKeyEvent>
using namespace std::tr1;
using namespace std::tr1::placeholders;
Controller::Controller()
			:tetris(Singleton<Tetris>::instance())
{

}

Controller::~Controller()
{

}

void Controller::key_press(int key)
{
	key_press_playing(key);
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

void Controller::on_timer()
{

}

