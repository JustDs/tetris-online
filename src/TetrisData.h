#ifndef TETRISDATA_H
#define TETRISDATA_H
#include"datafwd.h"
#include<list>
namespace data
{
	struct mov_box_type
	{
		char type;
		char x,y;
		char direction;
		pos_array_type toArray();
	};
}
class TetrisData
{
public:
	TetrisData();
	~TetrisData();
	const data::static_box_type& get_static() const
	{
		return static_box;
	}
	const data::mov_box_type& get_mov() const
	{
		return mov_box;
	}
	const data::mov_box_type& get_mov_next() const
	{
		return mov_box_next;
	}
	void move(char direction);
	void revolve();  // xuan zhuan
	void remove(int begin, int n);
	void fix();
private:
	typedef std::list<data::line> _static_box_type;
	data::static_box_type static_box;
	data::mov_box_type mov_box, mov_box_next;

};
#endif

