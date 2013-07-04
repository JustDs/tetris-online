#ifndef ONLINEDATA_H
#define ONLINEDATA_H
#include"datafwd.h"
class TetrisData;
class Tetris
{
public:
	Tetris();
	~Tetris();
	const TetrisData* get_self() const
	{
		return self;
	}
	const TetrisData* get_other() const
	{
		return other;
	}
	TetrisData* get_self()
	{
		return self;
	}
	TetrisData* get_other()
	{
		return other;
	}
private:
	TetrisData *self, *other;
};

#endif

