/*
    sandbox.c
    The module represents my demo functions in parallel multithreaded programming method.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include "log.h"
#include "rect.h"
#include "circle.h"

int test_encapsulation()
{
    Shape s1, s2; /* multiple instances of Shape */

    Shape_ctor(&s1, 0, 1);
    Shape_ctor(&s2, -1, 2);

    log_debug("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    log_debug("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));

    Shape_moveBy(&s1, 2, -4);
    Shape_moveBy(&s2, 1, -2);

    log_debug("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    log_debug("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));
    return 0;
}

int test_inheritance()
{
    Rectangle r1, r2; /* multiple instances of Rect */

    /* instantiate rectangles... */
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    log_debug("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r1.super), Shape_getY(&r1.super),
           r1.width, r1.height);
    log_debug("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r2.super), Shape_getY(&r2.super),
           r2.width, r2.height);

    /* re-use inherited function from the superclass Shape... */
    Shape_moveBy((Shape *)&r1, -2, 3);
    Shape_moveBy(&r2.super, 2, -1);

    log_debug("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r1.super), Shape_getY(&r1.super),
           r1.width, r1.height);
    log_debug("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r2.super), Shape_getY(&r2.super),
           r2.width, r2.height);
    return 0;
}

int test_polymorphism()
{
    Rectangle r1, r2; /* multiple instances of Rectangle */
    Circle    c1, c2; /* multiple instances of Circle */
    Shape const *shapes[] = { /* collection of shapes */
            &c1.super,
            &r2.super,
            &c2.super,
            &r1.super
    };
    Shape const *s;

    /* instantiate rectangles... */
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    /* instantiate circles... */
    Circle_ctor(&c1, 1, -2, 12);
    Circle_ctor(&c2, 1, -3, 6);

    s = largestShape(shapes, sizeof(shapes)/sizeof(shapes[0]));
    log_debug("largetsShape s(x=%d,y=%d)\n",
           Shape_getX(s), Shape_getY(s));

    drawAllShapes(shapes, sizeof(shapes)/sizeof(shapes[0]));
    return 0;
}