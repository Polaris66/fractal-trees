#pragma once

#include "Point.hpp"

class Circle
{
private:
    void drawAll(Point *p);

public:
    Point *c;
    int r;

    Circle(Point *_c, int _r);
    void render();
};