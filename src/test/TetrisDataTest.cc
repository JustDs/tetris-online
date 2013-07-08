#include"../TetrisData.h"
#include"../Tetris.h"
#include"../Controller.h"
#include"../../include/Singleton.h"
#include<iostream>
#ifdef _MSC_VER
	#include<windows.h>
#else
	#include<unistd.h>
#endif

int main()
{
	Tetris &tetris = Singleton<Tetris>::instance();
	Controller ctrl;
	auto self = tetris.get_self();
	while(1)
	{
		auto stat = self->get_static();
		auto mov = self->get_mov();
		ctrl.on_timer();
		if(tetris.state % 10 == 0)
			continue;
		std::cout<<"static:"<<std::endl;
		for(auto iter = stat.rbegin(); iter != stat.rend(); ++iter)
		{
			for(int i = 0; i < data::ROW; ++i)
			{
				std::cout<<(int)((*iter)[i]);
			}
			std::cout<<std::endl;
		}
		std::cout<<"mov:"<<std::endl;
		std::cout<<(int)mov.type<<" "<<(int)mov.x<<" "<<(int)mov.y<<" "<<(int)mov.direction<<std::endl;
		auto mov_pos = mov.toArray();
		for(int i = 0; i < 4; i++)
		{
			std::cout<<i<<":"<<(int)mov_pos.x[i]<<" "<<(int)mov_pos.y[i]<<std::endl;
		}
	//#ifdef _MSC_VER
	//	Sleep(2000);
	//#else
	//	sleep(2);
	//#endif
	}
	return 0;
}
