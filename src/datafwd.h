#ifndef DATAFWD_H
#define DATAFWD_H
#include<list>
namespace data
{
	enum
	{
		LINE = 20,
		ROW = 12
	};
	enum box
	{
		I=1,
		J,L,
		O,S,
		Z,T
	};
	typedef char[ROW] line;
	struct data_type
	{
		std::list<line> static_box;
		struct 
		{
			char type;
			char x,y;
			char direction;
		}mov_box;
	};	
}
#endif

