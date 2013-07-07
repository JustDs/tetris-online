#include<algorithm>
#include"TetrisData.h"
#include<assert.h>
using namespace data;
bool TetrisData::canDown() const
{
	assert(get_mov().type);
	pos_array_type temp = get_mov().toArray();
	for(int i=0; i<4; i++)
	{
		temp.y[i]--;
		if(temp.y[i]<0)
			return false;
		else
		{
			if(temp.y[i] >= static_box.size())
				continue;
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

bool TetrisData::canLeft() const
{
	pos_array_type temp = get_mov().toArray();
	for(int i=0; i<4; i++)
	{
		temp.x[i]--;
		if(temp.x[i]<0)
			return false;
		else
		{
			if(temp.y[i] >= static_box.size())
				continue;
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

bool TetrisData::canRight() const
{
	pos_array_type temp = get_mov().toArray();
	for(int i=0; i<4; i++)
	{
		temp.x[i]++;
		if(temp.x[i]>ROW-1)
			return false;
		else
		{
			if(temp.y[i] >= static_box.size())
				continue;
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

bool TetrisData::canRevolve() const
{
	mov_box_type mov_temp(get_mov());
	mov_temp.direction++;
	mov_temp.direction %= 4;
	pos_array_type temp = mov_temp.toArray();
	for(int i=0; i<4; i++)
	{
		if((temp.y[i]<0)||(temp.x[i]<0)||(temp.x[i]>ROW))
			return false;
		else
		{
			if(temp.y[i] >= static_box.size())
				continue;
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

bool TetrisData::canFix() const
{
	mov_box_type mov_box_temp = get_mov();
	assert(mov_box.type);
	pos_array_type temp = mov_box_temp.toArray();
	if(temp.y[0] == 0)
		return true;
	for(int i = 0; i < 4; i++)
	{
		int y = temp.y[i];
		if(y > static_box.size())
			continue;
		if(static_box.at(y-1).at(temp.x[i]))
		{
			return true;
		}
	}
	return false;
}

bool TetrisData::canRemove::operator()(const data::line& each_line) const
{
	auto result = std::find(each_line.begin(), each_line.end(), 0);
	return result == each_line.end();
}
