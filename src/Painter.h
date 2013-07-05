#ifndef PAINTER_H
#define PAINTER_H
#ifdef _WIN32
	#include<functional>
#else
	#include<tr1/functional>
#endif
#include"datafwd.h"
typedef std::tr1::function<void(int, int, int)> func3i;
typedef std::tr1::function<void(int, int, int, int)> func4i;
struct paint_func
{
	func4i setColor;
	func4i fillRect;
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
	func4i fillRect;	
	func4i setColor;
	unsigned int loadImage(char* filename);//load image from the resource
	void paintImage(int x,int y, int width, int height, unsigned int img_id);//paint a picture

	unsigned int block_img_id_list[7];
	unsigned int background_img_id; 
	unsigned int getImageId(char block_type);
	void paintBackground();
	void paintBlock(int x,int y,unsigned int block_img_id);
	void paintSingle(int offset_x,int offset_y);
};
#endif