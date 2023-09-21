#pragma once

#include "Point.hpp"

class Line
{
public:
    Point *a, *b;
    Line(Point *_a, Point *_b);
    Line(Point *a, Point *b, bool flag);
    Line(Point *a, double theta, double l);
    void render();
};