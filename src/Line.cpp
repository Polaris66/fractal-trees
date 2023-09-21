#include <iostream>
#include <cmath>
#include "Headers/Line.hpp"

Line::Line(Point *_a, Point *_b)
{
    Line(_a, _b, true);
}

Line::Line(Point *_a, Point *_b, bool flag)
{
    a = _a;
    b = _b;
    if (flag)
    {
        render();
    }
}

Line::Line(Point *_a, double theta, double l)
{
    a = _a->copy();
    b = a->copy()->translate(l * std::cos(theta), l * std::sin(theta));
    a->print();
    b->print();
    render();
}

void Line::render()
{
    int dx = b->x - a->x;
    int dy = b->y - a->y;
    int s;
    if (dx > 0 && dy > 0)
    {
        s = 0;
    }
    else if (dx < 0 && dy < 0)
    {
        s = 1;
        std::swap(a, b);
        dx = b->x - a->x;
        dy = b->y - a->y;
    }
    else if (dx < 0 && dy > 0)
    {
        s = 2;
        a->reflectY();
        b->reflectY();
        std::swap(a, b);
        dx = b->x - a->x;
        dy = b->y - a->y;
    }
    else if (dy < 0 && dx > 0)
    {
        s = 3;
        a->reflectY();
        b->reflectY();

        dx = b->x - a->x;
        dy = b->y - a->y;
    }
    else if (dx == 0)
    {
        if (a->y > b->y)
        {
            std::swap(a, b);
        }

        while (a->y <= b->y)
        {
            a->render();
            a->y += 1;
        }
        return;
    }
    else if (dy == 0)
    {
        if (a->x > b->x)
        {
            std::swap(a, b);
        }

        while (a->x <= b->x)
        {
            a->render();
            a->x += 1;
        }
        return;
    }

    int fl = 0;
    if (abs(dy) > abs(dx))
    {
        fl = 1;
        a->reflectDiagonal();
        b->reflectDiagonal();
        dx = b->x - a->x;
        dy = b->y - a->y;
    }

    int d = 2 * dy - dx;
    int E = 2 * dy;
    int NE = 2 * (dy - dx);
    Point *p = a->copy();

    if (fl)
    {
        p->reflectDiagonal();
    }
    if (s >= 2)
    {
        p->reflectY();
        p->render();
        p->reflectY();
    }
    else
    {
        p->render();
    }
    if (fl)
    {
        p->reflectDiagonal();
    }
    while ((p->x) < (b->x))
    {
        if (d <= 0)
        {
            d += E;
        }
        else
        {
            d += NE;
            p->y += 1;
        }

        p->x += 1;

        if (fl)
        {
            p->reflectDiagonal();
        }

        if (s >= 2)
        {
            p->reflectY();
            p->render();
            p->reflectY();
        }
        else
        {
            p->render();
        }

        if (fl)
        {
            p->reflectDiagonal();
        }
    }
}