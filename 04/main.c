#include "Circle.h"
#include "new.h"

int main (int argc, char ** argv)
{	void *p;
    void *s;
		p = new(Circle, 1, 2, 3);
		s = new(Point, 1, 2);
		draw(p);
		move(s, 10, 20);
		draw(s);
		delete(p);
		delete(s);
	return 0;
}
