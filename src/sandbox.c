/*
    sandbox.c
    The module represents my demo functions in parallel multithreaded programming method.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <threads.h>
#include "log.h"
#include "rect.h"
#include "circle.h"

//WORK ON THREADS IS IN PROGRESS
static volatile int COUNTER = 10;  // Static value shared between threads

void* run(void *arg)
{
    int n = *(int*)arg;  // Thread number for humans to differentiate

    //free(arg);

    int x = COUNTER;  // Automatic local variable--each thread has its own

    // We just assigned x from foo, so they'd better be equal here.
    // (In all my test runs, they were, but even this isn't guaranteed!)

    log_info("Thread %d: x = %d, COUNTER = %d", n, x, COUNTER);

    // And they should be equal here, but they're not always!
    // (Sometimes they were, sometimes they weren't!)

    // What happens is another thread gets in and increments foo
    // right now, but this thread's x remains what it was before!

    COUNTER++;  // Increment shared value

    return NULL;
}

int multithreaded_sandbox()
{
    const int THREAD_COUNT = 8;
    thrd_t t[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof *n);  // Holds a thread serial number
        *n = i;
        thrd_create(t + i, (thrd_start_t) run, n);
        free(n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }
    log_debug("COUNTER = %d", COUNTER);

    pthread_t t0, t1;
    int *n = malloc(sizeof *n);
    *n=1;
    pthread_create(&t0,NULL,run,n);
    pthread_create(&t1,NULL,run,n);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    free(n);
    return 0;
}

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