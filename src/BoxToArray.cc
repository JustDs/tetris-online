#include"TetrisData.h"
using namespace data;

pos_array_type mov_box_type::toArray()
{
	pos_array_type array;
	for(int i = 0; i < 4; ++i)
	{
		array.x[i] = i + 1;
		array.y[i] = LINE;
	}
	return array;
}
