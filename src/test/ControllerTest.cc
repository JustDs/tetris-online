#include"../Controller.h"
#include"../Tetris.h"
#include"../TetrisData.h"
#include"../../include/Singleton.h"
#include<assert.h>
int main()
{
	Tetris &tetris = Singleton<Tetris>::instance();
	Controller ctrl;
	ctrl.on_timer();
	assert(tetris.get_self()->get_static().empty());
	assert(tetris.get_self()->get_mov().type);
	ctrl.on_timer();
	assert(tetris.get_self()->get_mov().type);
	assert(tetris.get_self()->get_static().empty());
	return 0;
}

