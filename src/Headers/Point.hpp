#pragma once

class Point
{
public:
    int x, y;
    Point(int _x, int _y);
    void render();
    void renderTranslated(int _x, int _y);
    Point *copy();
    void reflectDiagonal();
    void reflectX();
    void reflectY();
};