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
private:
	const TetrisData *self_data, *other_data;
	int &window_width, &window_height;
	func4i fillRect;	
	func4i setColor;
};
#endif

