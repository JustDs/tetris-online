#ifndef ONLINEDATA_H
#define ONLINEDATA_H
#include"datafwd.h"
class TetrisData;
class Tetris
{
public:
	Tetris();
	~Tetris();
	enum //statement
	{
		UNINITIALIZED = 0,
		SINGLEINIT = 10,
		SINGLEGAMING = 11,

		ONLINEINIT = 20,
		ONLINEGAMING = 21
	};
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
	int state;
private:
	TetrisData *self, *other;
};

#endif

