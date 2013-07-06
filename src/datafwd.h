#ifndef DATAFWD_H
#define DATAFWD_H
#include<vector>
namespace data
{
	enum
	{
		LINE = 20,
		ROW = 12
	};
	namespace box
	{
		enum
		{
			I=1,
			J,L,
			O,S,
			Z,T
		};
	}
	enum
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	typedef char line[ROW];
	typedef std::vector<line> static_box_type;
	struct pos_array_type
	{
		char x[4], y[4];
	};
	struct mov_box_type
	{
		char type;
		char x,y;
		char direction;
		pos_array_type toArray() const;
	};
}
#endif

