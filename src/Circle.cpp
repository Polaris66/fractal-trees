#include "Headers/Point.hpp"
#include "Headers/Circle.hpp"

Circle::Circle(Point *_c, int _r)
{
    c = _c;
    r = _r;
}

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