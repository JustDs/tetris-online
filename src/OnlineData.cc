#include "OnlineData.h"
#include "TetriData.h"
using data::data_type;
OnlineData::OnlineData()
			:self(),other()
{

}

OnlieData::~OnlineData()
{

}

const data_type& get_self() const
{
	return self.get_data();
}

const data_type& get_other() const
{
	return other.get_data();
}
