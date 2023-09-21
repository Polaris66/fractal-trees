#include <iostream>
#include <GL/glut.h>

#include "Headers/Point.hpp"

/**
 * @param  - the x and y values of the point
 *
 * @brief This function is used to make the point object.
 *
 */
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}

/**
 * @param  - the x and y values of the point
 *
 * @brief This function is used to shift the point in x and y direction.
 *
 * @return It returns the shifted point.
 */
Point *Point::translate(double _x, double _y)
{
    x += _x;
    y += _y;

    return this;
}

/**
 * @param  - the x and y values of the point
 *
 * @brief This function is used to render the point.
 *
 * @return It renders the point.
 */
void Point::render()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    // this->print();
    glVertex2i(x, y);
    glEnd();
}

/**
 * @param  - the x and y values of the point
 *
 * @brief This function is used to shift the point in x and y direction and render it.
 *
 * @return It retunrns the shifted point.
 */
void Point::renderTranslated(int _x, int _y)
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(x + _x, y + _y);
    glEnd();
}

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to make a copy of a point.
 *
 * @return It returns the new point.
 */
Point *Point::copy()
{
    return new Point(x, y);
}

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to swap the x and y values of the point.
 */
void Point::reflectDiagonal()
{
    std::swap(x, y);
}

/**
 * @brief This function is used to print the point
 */

void Point::print()
{
    std::cout << x << ' ' << y << std::endl;
}

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to reflect the x value of the point.
 */
void Point::reflectX()
{
    x *= -1;
}

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to reflect the y value of the point.
 */
void Point::reflectY()
{
    y *= -1;
}

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to swap the x and y values of the point and render the point.
 */
void Point::renderReflectedDiagonal()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(y, x);
    glEnd();
};

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to reflect the x value of the point and render the point.
 */
void Point::renderReflectedX()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(-x, y);
    glEnd();
};

/**
 * @param  - It takes the point object as a paramter
 *
 * @brief This function is used to reflect the y value of the point and then render the point.
 */
void Point::renderReflectedY()
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2i(x, -y);
    glEnd();
};