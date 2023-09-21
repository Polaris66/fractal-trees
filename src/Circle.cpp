#include "Headers/Point.hpp"
#include "Headers/Circle.hpp"

/**
 * @param -The x and y values of the center of the circle and the radius of the circle
 *
 * @brief The base function to create a circle object
 *
 */
Circle::Circle(Point *_c, int _r)
{
    c = _c;
    r = _r;
}

/**
 * @param  - the x and y values of the point on the circle
 *
 * @brief This function is used to symmetrically make the circle by rendering it in 8 quadrants.
 *
 * @return It renders the circle on the window.
 */
void Circle::drawAll(Point *p)
{
    c->renderTranslated(p->x, p->y);
    c->renderTranslated(-p->x, p->y);
    c->renderTranslated(p->x, -p->y);
    c->renderTranslated(-p->x, -p->y);
    c->renderTranslated(p->y, p->x);
    c->renderTranslated(-p->y, p->x);
    c->renderTranslated(p->y, -p->x);
    c->renderTranslated(-p->y, -p->x);
}

/**
 * @brief This function is the actual behind making the circle as taught in the class.
 *
 * @return It shows the logic behind the code and renders the circle by calling the render function.
 */
void Circle::render()
{
    int d = 1 - r;
    int deltaE = 3;
    int deltaSE = -2 * r + 5;

    Point *p = new Point(0, r);

    drawAll(p);

    while ((p->y) > (p->x))
    {
        if (d < 0)
        {
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;
        }
        else
        {
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            (p->y)--;
        }
        (p->x)++;
        drawAll(p);
    }
}