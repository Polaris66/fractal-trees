#pragma once

#include "Point.hpp"

class Line
{
public:
    Point *a, *b;
    Line(Point *_a, Point *_b);
    void render();
};