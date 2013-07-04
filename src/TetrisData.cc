#include "TetrisData.h"
#include<algorithm>
using namespace data;

TetrisData::TetrisData()
{

}

TetrisData::~TetrisData()
{

}

void TetrisData::move(char direction)
{
	switch(direction)
	{
		case DOWN:
			--mov_box.y;
			break;
		case LEFT:
			--mov_box.x;
			break;
		case RIGHT:
			++mov_box.x;
			break;
		default:
			break;
	}
}

void TetrisData::revolve()
{
	if(++mov_box.direction > 3)
		mov_box.direction = 0;
}

void TetrisData::remove(int n)
{
	auto it_erease_1 = static_box.begin();
	auto it_erease_n = it_erease_1;
	std::advance(it_erease_n, n);
	static_box.erase(it_erease_1, it_erease_n);
}

void TetrisData::fix()
{
	auto pos_mov = mov_box.toArray();
	//TODO:fix mov box to static_box
}

