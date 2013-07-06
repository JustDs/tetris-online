#ifndef PAINTER_H
#define PAINTER_H
#ifdef _MSC_VER
	#include<functional>
#else
	#include<tr1/functional>
#endif
#include"datafwd.h"
typedef std::tr1::function<void(int, int, int, int)> funcv4i;
typedef std::tr1::function<unsigned int(const char*)> funcu1p;
typedef std::tr1::function<void(int, int, int, int, unsigned int)> funcv5i;
struct paint_func
{
	funcv4i setColor;
	funcv4i fillRect;
	funcu1p loadImage;
	funcv5i paintImage;
};
class TetrisData;
class Painter
{
public:
	Painter(paint_func &func);
	~Painter();
	void init();
	void paintOnline();
	void setData(const TetrisData *self_data, const TetrisData *other_data);
	void resizeWindow(int width,int height);

private:
	const TetrisData *self_data, *other_data;
	int window_width, window_height;
	funcv4i fillRect;	
	funcv4i setColor;
	funcu1p loadImage;//load image from the resource
	funcv5i paintImage;//paint a picture

	const int default_window_width = 800;
	const int default_window_height = 600;

	unsigned int block_img_id_list[7];
	unsigned int background_img_id; 
	unsigned int getImageId(char block_type);
	void paintBackground();
	void paintBlock(int offset_x,int offset_y,int x_index,int y_index,unsigned int block_img_id);
	void paintSingle(int offset_x,int offset_y,const TetrisData *data);
};
#endif
