#include "TetrisData.h"
#include<algorithm>
using namespace data;

TetrisData::TetrisData()
{

}

TetrisData::~TetrisData()
{

}

void TetrisData::init_data()
{
	create_mov();
	swap_mov();
}

void TetrisData::swap_mov()
{
	mov_box = mov_box_next;
	create_mov();
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

void TetrisData::remove()
{
	static_box.erase(std::remove_if(static_box.begin(), static_box.end(),
								canRemove()), static_box.end());
}

bool TetrisData::fix()
{
	if(!canFix())
		return false;
	auto pos_mov = mov_box.toArray();
	for(int i = 0; i < 4; ++i)
	{
		if(pos_mov.y[i] < static_box.size())
		{
			auto iter = static_box.begin();
			std::advance(iter, pos_mov.y[i]);
			(*iter)[pos_mov.x[i]] = mov_box.type;
		}
		else //out of range
		{
			data::line new_line(ROW); //ensure line.size == 12
			new_line[pos_mov.x[i]] = mov_box.type;
			static_box.push_back(new_line);
		}		
	}
	mov_box = mov_box_next;
	create_mov();
	return true;
	//TODO:fix mov box to static_box //DONE
	//TODO:create a new mov_box //DONE
}

void TetrisData::create_mov()
{
	mov_box_next.type = rand()%box::T + 1;
	mov_box_next.x = ROW/2 -1;
	mov_box_next.y = LINE;
	mov_box_next.direction = 0;
}
