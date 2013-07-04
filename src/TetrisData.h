#ifndef TETRISDATA_H
#define TETRISDATA_H
#include"datafwd.h"
class TetrisData
{
public:
	using data::data_type;
	TetrisData();
	~TetrisData();
	const data_type& get_data() const
	{
		return _data;
	}
private:
	data_type _data;

};
#endif

