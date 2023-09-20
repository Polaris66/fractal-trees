#include <iostream>
#include <GL/glut.h>

#include "Headers/Point.hpp"

Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Point::render()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    std::cout << x << ' ' << y << '\n';
    glVertex2i(x, y);
    glEnd();
}

void Point::renderTranslated(int _x, int _y)
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    std::cout << x << ' ' << y << '\n';
    glVertex2i(x + _x, y + _y);
    glEnd();
}

Point *Point::copy()
{
    return new Point(x, y);
}

void Point::reflectDiagonal()
{
    std::swap(x, y);
}

void Point::reflectX()
{
    x *= -1;
}

void Point::reflectY()
{
    y *= -1;
}