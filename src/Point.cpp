#include <iostream>
#include <GL/glut.h>

#include "Headers/Point.hpp"

Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}

Point *Point::translate(double _x, double _y)
{
    x += _x;
    y += _y;

    return this;
}

void Point::render()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    // this->print();
    glVertex2i(x, y);
    glEnd();
}

void Point::renderTranslated(int _x, int _y)
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
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

void Point::print()
{
    std::cout << x << ' ' << y << std::endl;
}

void Point::reflectX()
{
    x *= -1;
}

void Point::reflectY()
{
    y *= -1;
}

void Point::renderReflectedDiagonal()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(y, x);
    glEnd();
};
void Point::renderReflectedX()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(-x, y);
    glEnd();
};
void Point::renderReflectedY()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(x, -y);
    glEnd();
};