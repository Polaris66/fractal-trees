#pragma once

class Point
{
public:
    int x, y;
    Point(int _x, int _y);
    void render();
    Point *copy();
    void reflectDiagonal();
    void reflectX();
    void reflectY();
};