#include <GL/glut.h>
#include <iostream>
#include <stack>

#include "Headers/Point.hpp"
#include "Headers/Line.hpp"
#include "Headers/Circle.hpp"
#include "Headers/Tree.hpp"

// Global Variables
int WIDTH;
int HEIGHT;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Draw Scene Function
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // new Line(new Point(320, 20), new Point(311, 37));
    new Tree(new Point(100, 100), 40);
    glutSwapBuffers();
}

// Main Function
// Returns integer for error handling
int main(int argc, char **argv)
{
    WIDTH = 1080, HEIGHT = 1080;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Window");

    init();

    glutDisplayFunc(render);

    glutMainLoop();
}