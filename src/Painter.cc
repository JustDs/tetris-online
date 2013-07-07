#include "Painter.h"
#include "Singleton.h"
#include "GlobalSettings.h"
#include "TetrisData.h"
#include<assert.h>
Painter::Painter(paint_func &func)
	:window_width(Singleton<GlobalSettings>::instance().window_width),
	window_height(Singleton<GlobalSettings>::instance().window_height),
	default_window_width(800),default_window_height(600)
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
			img_id = block_img_id_list[1];
			break;
		case data::box::J :
			img_id = block_img_id_list[1];
			break;
		case data::box::L :
			img_id = block_img_id_list[2];
			break;
		case data::box::O :
			img_id = block_img_id_list[3];
			break;
		case data::box::S :
			img_id = block_img_id_list[4];
			break;		
		case data::box::Z :
			img_id = block_img_id_list[5];
			break;
		case data::box::T :
			img_id = block_img_id_list[6];
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
		if( y_index < data::LINE - 1 )
		{
			paintImage( x_index * width + offset_x , y_index * height + offset_y , width , height , block_img_id);
	
		}
	}
}

void Painter::paintSingle(int offset_x,int offset_y,const TetrisData *data)
{
	data::static_box_type static_box_data = data->get_static();
	int i = 1;
	for(auto iter = static_box_data.begin(); iter != static_box_data.end(); iter++,i++)
	{
		for(int j=0; j <= data::ROW; j++)
		{
			unsigned int img_id = getImageId((*iter)[j]);
			paintBlock( offset_x , offset_y , j , data::LINE - 1 - i , img_id );
		}
	}

	auto mov_box_data = data->get_mov().toArray();
	for(int i=0;i<4;i++)
	{
		if( mov_box_data.x[i] < data::ROW && mov_box_data.y[i] < data::LINE )
		{
			paintBlock( offset_x, offset_y , mov_box_data.x[i] ,data::LINE - 1 - mov_box_data.y[i] , getImageId(data->get_mov().type));
	 	}
	} 
}

void Painter::paintBackground()
{
	paintImage(0,0,window_width,window_height,background_img_id);
}

void Painter::resizeWindow(int width,int height)
{
	window_width = width;
 	window_height = height;
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

	paintSingle(left_box_offset_left , box_top_offset , self_data);
 	paintSingle(right_box_offset_left , box_top_offset , other_data);
	paintBackground();
}

void Painter::init()
{
	//TODO : Load the image from the resource files.
	block_img_id_list[0] = loadImage("I.png");
	block_img_id_list[1] = loadImage("J.png");
	block_img_id_list[2] = loadImage("L.png");
	block_img_id_list[3] = loadImage("O.png");
	block_img_id_list[4] = loadImage("S.png");
	block_img_id_list[5] = loadImage("Z.png");
	block_img_id_list[6] = loadImage("T.png");
	background_img_id = loadImage("background.png");
}

void Painter::setData(const TetrisData *self_data, const TetrisData *other_data)
{
	this->self_data = self_data;
	this->other_data = other_data;
}
