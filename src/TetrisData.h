#ifndef TETRISDATA_H
#define TETRISDATA_H
#include"datafwd.h"
#include<list>
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
	void init_data(); //only for _self
	bool move(char direction);
	bool revolve();  // xuan zhuan
	void remove(int begin, int n);
	void fix();
	TetrisData& operator=(const TetrisData& rhs)
	{
		this->static_box = rhs.static_box;
		this->mov_box = rhs.mov_box;
		this->mov_box_next = rhs.mov_box_next;
		return *this;
	}
private:
	bool canDown() const;
	bool canLeft() const;
	bool canRight() const;
	bool canRevolve() const;
	bool canFix() const;

	void create_mov();
	//typedef std::list<data::line> _static_box_type;
	data::static_box_type static_box;
	data::mov_box_type mov_box, mov_box_next;

};
#endif

