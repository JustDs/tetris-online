#include"TetrisData.h"
using namespace data;
bool TetrisData::canDown() const
{
	pos_array_type temp = get_mov().toArray();
	for(int i=0; i<4; i++)
	{
		temp.y[i]--;
		if(temp.y[i]<0)
			return false;
		else
		{
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
		if(temp.x[i]>ROW)
			return false;
		else
		{
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

bool TetrisData::canRevolve() const
{
	mov_box_type mov_temp(get_mov());
	mov_temp.derection++;
	mov_temp.derection %= 4;
	pos_array_type temp = mov_temp.toArray();
	for(int i=0; i<4; i++)
	{
		if((temp.y[i]<0)||(temp.x[i]<0)||(temp.x[i]>ROW))
			return false;
		else
		{
			if(static_box[temp.y[i]][temp.x[i]])
				return false;
		}
	}
	return true;
}

