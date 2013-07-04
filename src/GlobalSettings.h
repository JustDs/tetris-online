#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H
#include<Singleton.h>
class GlobalSettings
{
public:
	GlobalSettings();
	~GlobalSettings();
	int window_width, window_height;
	int max_frames;
private:
	void init();
};
#endif

