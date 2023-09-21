#include <GL/glut.h>
#include <iostream>

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
    glOrtho(0, 200, 0, 200, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Draw Scene Function
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    new Tree(new Point(100, 100), 40);
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