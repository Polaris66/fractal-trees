#include <GL/glut.h>
#include <iostream>

// Global Variables
int WIDTH;
int HEIGHT;

void draw_pixel(int x, int y)
{

    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    std::cout << x << ' ' << y << '\n';
    glVertex2i(x, y);
    glEnd();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawLine(int x0, int y0, int x1, int y1)
{
    std::cin >> x0 >> y0 >> x1 >> y1;
    int dx = x1 - x0;
    int dy = y1 - y0;

    int s;
    if (dx > 0 && dy > 0)
    {
        s = 0;
    }
    else if (dx < 0 && dy < 0)
    {
        s = 1;
        std::swap(x0, x1);
        std::swap(y0, y1);
        dx = x1 - x0;
        dy = y1 - y0;
    }
    else if (dx < 0)
    {
        s = 2;
        y0 = -y0;
        y1 = -y1;
        std::swap(x0, x1);
        std::swap(y0, y1);
        dx = x1 - x0;
        dy = y1 - y0;
    }
    else
    {
        s = 3;
        y0 = -y0;
        y1 = -y1;
        dx = x1 - x0;
        dy = y1 - y0;
    }

    int b = 0;
    if (abs(dy) > abs(dx))
    {
        b = 1;
        std::swap(x0, y0);
        std::swap(x1, y1);
        dx = x1 - x0;
        dy = y1 - y0;
    }

    std::cout << s;
    int d = 2 * dy - dx;

    int E = 2 * dy;
    int NE = 2 * (dy - dx);

    int x = x0;
    int y = y0;

    if (b)
    {
        std::swap(x, y);
    }
    if (s >= 2)
    {
        draw_pixel(x, -y);
    }
    else
    {
        draw_pixel(x, y);
    }
    if (b)
    {
        std::swap(x, y);
    }
    while (x < x1)
    {
        if (d <= 0)
        {
            d += E;
        }
        else
        {
            d += NE;
            y++;
        }
        x++;
        if (b)
        {
            std::swap(x, y);
        }
        if (s >= 2)
        {
            draw_pixel(x, -y);
        }
        else
        {
            draw_pixel(x, y);
        }
        if (b)
        {
            std::swap(x, y);
        }
    }
}

// Draw Scene Function
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(0, 100, 100, 50);
    glutSwapBuffers();
}

// Main Function
// Returns integer for error handling
int main(int argc, char **argv)
{
    WIDTH = 640, HEIGHT = 480;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Window");

    init();

    glutDisplayFunc(render);

    glutMainLoop();
}