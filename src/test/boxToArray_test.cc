#include "../datafwd.h"
#include "../TetrisData.h"
#include <assert.h>

using namespace data;
int main()
{
	struct mov_box_type test;
	test.type = box::O;
	test.x = test.y = 100;
	test.direction = 3;
	assert(test.toArray().x[0] == 100);
	assert(test.toArray().x[1] == 101);
	assert(test.toArray().x[2] == 100);
	assert(test.toArray().x[3] == 101);
	assert(test.toArray().y[0] == 100);
	assert(test.toArray().y[1] == 100);
	assert(test.toArray().y[2] == 101);
	assert(test.toArray().y[3] == 101);
}
