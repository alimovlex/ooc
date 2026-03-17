//
// Created by alalimov on 3/16/26.
//
#pragma once
#include "shape.h" /* the base class interface */

typedef struct {
    Shape super; /* <== inherits Shape */

    /* attributes added by this subclass... */
    uint16_t rad;
} Circle;

/* constructor */
void Circle_ctor(Circle * const me, int16_t x, int16_t y,
                 uint16_t rad);