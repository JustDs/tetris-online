#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H
class GlobalSettings
{
public:
	GlobalSettings();
	~GlobalSettings();
	int window_width, window_height;
	int max_frames;
	int interval; //time interval to process data
private:
	void init();
};
#endif

