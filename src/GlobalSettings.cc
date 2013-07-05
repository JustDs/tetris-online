#include "GlobalSettings.h"
#include "static/config.h"
GlobalSettings::GlobalSettings()
{
	init();
}

GlobalSettings::~GlobalSettings()
{

}

void GlobalSettings::init()
{
	window_width = WINDOW_WIDTH;
	window_height = WINDOW_HEIGHT;
	max_frames = MAX_FRAMES;
	interval = TIME_INTERVAL;
}

