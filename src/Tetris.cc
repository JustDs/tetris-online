#include "Tetris.h"
#include "TetrisData.h"
Tetris::Tetris()
		:state(0)
{
	self = new TetrisData;
	other = new TetrisData; //only for test
}

Tetris::~Tetris()
{
	delete self;
	delete other;
}

