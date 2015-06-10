#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<functional>
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
	void key_press_setting(int key);
	Tetris &tetris;

};
#endif

