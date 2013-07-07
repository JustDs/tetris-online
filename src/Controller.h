#ifndef CONTROLLER_H
#define CONTROLLER_H
#ifdef _MSC_VER
	#include<functional>
#else
	#include<tr1/functional>
#endif
class Tetris;
class Controller
{
public:
	Controller();
	~Controller();
	void key_press(int key);
	void on_timer();
private:
	void key_press_playing(int key);
	void key_press_select(int key);
	Tetris &tetris;

};
#endif

