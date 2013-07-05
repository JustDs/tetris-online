#include "../BoxToArray.cc"
#include <assert.h>



struct mov_box_type test;
test.type = L;
test.x = test.y = 100;
test.derction = 0;
assert(test.toArray.x[0] == 101)
assert(test.toArray.x[1] == 102)
assert(test.toArray.x[2] == 101)
assert(test.toArray.x[3] == 101)
assert(test.toArray.y[0] == 100)
assert(test.toArray.y[1] == 100)
assert(test.toArray.y[2] == 101)
assert(test.toArray.y[3] == 102)