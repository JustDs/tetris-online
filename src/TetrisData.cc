#include "TetrisData.h"
#include<algorithm>
using namespace data;

TetrisData::TetrisData()
{

}

TetrisData::~TetrisData()
{

}

bool TetrisData::move(char direction)
{
	switch(direction)
	{
		case DOWN:
			if(canDown())
			{
				--mov_box.y;
				return true;
			}
			break;
		case LEFT:
			if(canLeft())
			{
				--mov_box.x;
				return true;
			}
			break;
		case RIGHT:
			if(canRight())
			{
				++mov_box.x;
				return true;
			}
			break;
		default:
			break;
	}
	return false;
}

bool TetrisData::revolve()
{
	if(!canRevolve())
		return false;
	if(++mov_box.direction > 3)
		mov_box.direction = 0;
	return true;
}

void TetrisData::remove(int begin, int n)
{
	auto it_erease_1 = static_box.begin();
	std::advance(it_erease_1, begin);
	auto it_erease_n = it_erease_1;
	std::advance(it_erease_n, n);
	static_box.erase(it_erease_1, it_erease_n);
}

void TetrisData::fix()
{
	auto pos_mov = mov_box.toArray();
	for(int i = 0; i < 4; ++i)
	{
		if(pos_mov.y[i] < mov_box.size())
		{
			auto iter = static_box.begin();
			std::advance(iter, pos_mov.y[i]);
			(*iter)[pos_mov.x[i]] = mov_box.type;
		}
		else //out of range
		{
			data::line new_line = {0};
			new_line[pos_mov.x[i]] = mov_box.type;
			static_box.push_back(new_line);
		}		
	}
	//TODO:fix mov box to static_box
	//TODO:create a new mov_box
}

