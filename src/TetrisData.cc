#include "TetrisData.h"
#include<algorithm>
#include<stdlib.h>
using namespace data;

TetrisData::TetrisData()
{

}

TetrisData::TetrisData(const char *other)
{
	int num_line = *reinterpret_cast<const int*>(other);
	other += sizeof(int);
	mov_box = *reinterpret_cast<const data::mov_box_type*>(other);
	other += sizeof(data::mov_box_type);
	mov_box_next = *reinterpret_cast<const data::mov_box_type*>(other);
	other += sizeof(data::mov_box_type);

	for(int i = 0; i < num_line; i++)
	{
		data::line temp(data::ROW);
		for(int j = 0; j < data::ROW; j++)
		{
			temp[j] = *other;
			++other;
		}
		static_box.push_back(temp);
	}
}

TetrisData::~TetrisData()
{

}

int TetrisData::c_str(char *buff)
{
	int num_line = static_cast<int>(static_box.size());
	int packet_size = sizeof(int) + data::ROW * num_line \
						+ 2 * sizeof(data::mov_box_type);
	*reinterpret_cast<int*>(buff) = num_line;
	buff += sizeof(int);
	*reinterpret_cast<mov_box_type*>(buff) = mov_box;
	buff += sizeof(mov_box_type);
	*reinterpret_cast<mov_box_type*>(buff) = mov_box_next;
	buff += sizeof(mov_box_type);
	for(int i = 0; i < num_line; i++)
	{
		for(int j = 0; j < data::ROW; j++)
		{
			*buff = static_box[i][j];
			++buff;
		}
	}
	return packet_size;
}

void TetrisData::init_data()
{
	if(!static_box.empty())
	{
		static_box.erase(static_box.begin(), static_box.end());
	}
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
		return true;
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
	swap_mov();
	if(static_box.size() >= LINE)
		return false;
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
