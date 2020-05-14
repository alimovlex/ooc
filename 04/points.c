#include "Point.h"
#include "new.h"
#include "Circle.h"

int main (int argc, char ** argv)
{
        void * p;
        p = new(Point, 1, 2);
		draw(p);
		move(p, 10, 20);
		draw(p);
		delete(p);
	return 0;
}
