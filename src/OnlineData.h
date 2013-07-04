#ifndef ONLINEDATA_H
#define ONLINEDATA_H
#include"datafwd.h"
class TetriData;
class OnlineData
{
public:
	using data::data_type;
	OnlineData();
	~OnlineData();
	const data_type& get_self() const;
	const data_type& get_other() const;
private:
	TetriData &self, &other;

#endif

