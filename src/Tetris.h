#ifndef ONLINEDATA_H
#define ONLINEDATA_H
#include"datafwd.h"
#include<vector>
#ifdef _MSC_VCR
	#include<functional>
#else
	#include<tr1/functional>
#endif
class TetrisData;
class Tetris
{
public:
	typedef std::tr1::function<void(void)> regist_func;
	enum //statement
	{
		SELECT = 0,
		SINGLEGAME = 1,
		ONLINEGAME = 2,
		GAMESETTING = 3,

		SINGLEINIT = 10,
		SINGLEGAMING = 11,

		ONLINEINIT = 20,
		ONLINEGAMING = 21,

		SETTINGINIT = 30,
		SETTINGEND  = 31
	};
	Tetris();
	~Tetris();
	void start(int mode);
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
	void notify();
	void regist(regist_func func);
	void select_mode(int mode)
	{
		start(mode);
		state = mode * 10;
	}
	int get_mode()
	{
		return state/10;
	}
	int get_sub()
	{
		return get_state() % 10;
	}
	int get_state()
	{
		return state;
	}
	void next()
	{
		++state;
	}
	void prev()
	{
		--state;
	}
	void restart()
	{
		state = get_mode()*10;
		start(get_mode());
	}
private:
	int state;
	std::vector<regist_func> observers;
	TetrisData *self, *other;

	void start_single();
	void start_online();
};

#endif

