#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H
#include<Singleton.h>
class GlobalSettings : Singleton<GlobalSettings>
{
public:
	void init();
	int window_width, window_height;
	int max_frames;
};
#endif

