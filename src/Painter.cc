#include "Painter.h"
#include "Singleton.h"
#include "GlobalSettings.h"
#include "TetrisData.h"
#include<assert.h>
#include<string>

Painter::Painter(paint_func &func)
 	:window_width(Singleton<GlobalSettings>::instance().window_width),
	window_height(Singleton<GlobalSettings>::instance().window_height),
	default_window_width(800),default_window_height(600),options_num(4)
{
 	setColor = func.setColor;
	fillRect = func.fillRect;
	loadImage = func.loadImage;
	paintImage = func.paintImage;
}

Painter::~Painter()
{

}

unsigned int Painter::getImageId(char block_type)
{
	unsigned int img_id;
	switch(block_type)
	{
		case data::box::I :
			img_id = block_img_id[1];
			break;
		case data::box::J :
			img_id = block_img_id[2];
			break;
		case data::box::L :
			img_id = block_img_id[3];
			break;
		case data::box::O :
			img_id = block_img_id[4];
			break;
		case data::box::S :
			img_id = block_img_id[5];
			break;		
		case data::box::Z :
			img_id = block_img_id[6];
			break;
		case data::box::T :
			img_id = block_img_id[7];
			break;
		default:
			img_id = 0;
	}
	return img_id;
}

void Painter::paintBlock(int offset_x,int offset_y,int x_index,int y_index,unsigned int block_img_id)
{
	if(block_img_id != 0)
	{
		int height,width;
		//TODO : caculate the block size & the position to paint from the window size
		width = 800/40;
		height = 600/30;
		if( y_index <= data::LINE - 1 )
		{
			paintImage( x_index * width + offset_x , y_index * height + offset_y , width , height , block_img_id);
		}
	}
}

void Painter::paintMenu(int state)
{
	int offset_x = 270 * window_width/default_window_width;
	int offset_y = 300 * window_height/default_window_height;
	int width = 260 * window_width/default_window_width;
	int height = 60 * window_height/default_window_height;
	for(int i=0;i<options_num;i++)
	{
		if(i == state-1)
		{
			paintImage(offset_x, offset_y + i*height ,width,height,options_img_id[2*i+1]);
		}
		else
		{
			paintImage(offset_x, offset_y + i*height,width,height,options_img_id[2*i]);
		}
	}
	paintBackground(background_img_id[0]);
}

void Painter::paintInstructions()
{
	paintImage(0,0,window_width,window_height,background_img_id[3]);
}

void Painter::paintStatic(int offset_x,int offset_y,const TetrisData *data)
{
	data::static_box_type static_box_data = data->get_static();
	int i = 0;
	for(auto iter = static_box_data.begin(); iter != static_box_data.end(); ++iter,++i)
	{
		for(int j=0; j < data::ROW; j++)
		{
			unsigned int img_id = getImageId((*iter).at(j));
			paintBlock( offset_x , offset_y , j , data::LINE - 1 - i , img_id );
		}
	}
}

void Painter::paintMov(int offset_x,int offset_y,data::mov_box_type mov_box_data, bool still)
{
	auto mov_box_pos_data = mov_box_data.toArray();
	for(int i=0;i<4;i++)
	{
		if( still || (mov_box_pos_data.x[i] < data::ROW && mov_box_pos_data.y[i] < data::LINE) )
		{
			paintBlock( offset_x, offset_y , mov_box_pos_data.x[i] ,data::LINE - 1 - mov_box_pos_data.y[i] , getImageId(mov_box_data.type));
	 	}
	} 
}

void Painter::paintPlayer(int offset_x,int offset_y,const TetrisData *data)
{
	paintStatic(offset_x,offset_y,data);
	paintMov(offset_x,offset_y,data->get_mov(),false);
}

void Painter::paintBackground(unsigned int background_id)
{
	paintImage(0,0,window_width,window_height,background_id);
}

void Painter::resizeWindow(int width,int height)
{
	window_width = width;
 	window_height = height;
}

void Painter::paintSingle()
{
	int left_box_offset_left = 260 * window_width/default_window_width;
	int box_top_offset = 140 * window_height/default_window_height;
	int next_left_offset = 520 * window_width/default_window_width;
	int next_top_offset = 300 * window_height/default_window_height;

	paintPlayer(left_box_offset_left , box_top_offset , self_data);
	paintMov(next_left_offset,next_top_offset,self_data->get_mov_next(),true);
	paintBackground(background_img_id[1]);
}

void Painter::paintOnline()
{
	assert(self_data&&other_data);
	//setColor(255, 0, 0, 255);
	//fillRect(0,0,100,100);
	//TODO : calulate the offset from the window size
	int left_box_offset_left = 100 * window_width/default_window_width;
	int right_box_offset_left = 460 * window_width/default_window_width;
	int box_top_offset = 140 * window_height/default_window_height;

	int next_left_offset = 280 * window_width/default_window_width; 
	int next_top_offset = 300 * window_height/default_window_height;

	paintPlayer(left_box_offset_left , box_top_offset , self_data);
 	paintPlayer(right_box_offset_left , box_top_offset , other_data);
	paintMov(next_left_offset,next_top_offset,self_data->get_mov_next(),true);
	paintBackground(background_img_id[2]);
}

void Painter::init()
{
	//TODO : Load the image from the resource files.
	block_img_id[0] = loadImage("holder.png");
	#ifdef _WIN32
		block_img_id[1] = loadImage("blocks//I.png");
		block_img_id[2] = loadImage("blocks//J.png");
		block_img_id[3] = loadImage("blocks//L.png");
		block_img_id[4] = loadImage("blocks//O.png");
		block_img_id[5] = loadImage("blocks//S.png");
		block_img_id[6] = loadImage("blocks//Z.png");
		block_img_id[7] = loadImage("blocks//T.png");
		background_img_id[0] = loadImage("backgrounds//start.png");
		background_img_id[1] = loadImage("backgrounds//single.png");
		background_img_id[2] = loadImage("backgrounds//online.png");
		background_img_id[3] = loadImage("backgrounds//instructions.png");
		
		options_img_id[0] = loadImage("options//single_0.png");
		options_img_id[1] = loadImage("options//single_1.png");
		options_img_id[2] = loadImage("options//double_0.png");
		options_img_id[3] = loadImage("options//double_1.png");
		options_img_id[4] = loadImage("options//instructions_0.png");
		options_img_id[5] = loadImage("options//instructions_1.png");
		options_img_id[6] = loadImage("options//exit_0.png");
		options_img_id[7] = loadImage("options//exit_1.png");
	#else
		block_img_id[1] = loadImage("blocks/I.png");
		block_img_id[2] = loadImage("blocks/J.png");
		block_img_id[3] = loadImage("blocks/L.png");
		block_img_id[4] = loadImage("blocks/O.png");
		block_img_id[5] = loadImage("blocks/S.png");
		block_img_id[6] = loadImage("blocks/Z.png");
		block_img_id[7] = loadImage("blocks/T.png");
		background_img_id[0] = loadImage("backgrounds/start.png");
		background_img_id[1] = loadImage("backgrounds/single.png");
		background_img_id[2] = loadImage("backgrounds/online.png");
		background_img_id[3] = loadImage("backgrounds/instructions.png");
		
		options_img_id[0] = loadImage("options/single_0.png");
		options_img_id[1] = loadImage("options/single_1.png");
		options_img_id[2] = loadImage("options/double_0.png");
		options_img_id[3] = loadImage("options/double_1.png");
		options_img_id[4] = loadImage("options/instructions_0.png");
		options_img_id[5] = loadImage("options/instructions_1.png");
		options_img_id[6] = loadImage("options/exit_0.png");
		options_img_id[7] = loadImage("options/exit_1.png");
	#endif
}

void Painter::setData(const TetrisData *self_data, const TetrisData *other_data)
{
	this->self_data = self_data;
	this->other_data = other_data;
}
