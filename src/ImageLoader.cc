#include "ImageLoader.h"
#include<assert.h>
ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

unsigned int ImageLoader::load(const char *filename)
{
	PNG_PTR png(new PNG);
	unsigned int error = lodepng::decode(png->data,	png->width,
										png->height, filename);
	assert(!error);
	images.push_back(png);
	return images.size()-1;
}

ImageLoader::PNG_PTR ImageLoader::get(unsigned int id)
{
	return images.at(id);
}

