#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include<vector>
#ifdef _MSC_VER
	#include<memory>
#else
	#include<tr1/memory>
#endif
struct PNG
{
	std::vector<unsigned char> data;
	unsigned int width, height;
};
class ImageLoader
{
public:
	typedef std::tr1::shared_ptr<PNG> PNG_PTR;
	ImageLoader();
	~ImageLoader();
	unsigned int load(const char *filename);
	PNG_PTR get(unsigned int id);
private:
	std::vector<PNG_PTR> images;
};
#endif

