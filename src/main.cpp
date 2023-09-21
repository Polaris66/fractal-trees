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

/**
 * @brief This function iniatilises viewport
 */
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief This function is used to make the objects needed.
 */
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // new Line(new Point(320, 20), new Point(311, 37));
    new Tree(new Point(100, 100), 40);
    glutSwapBuffers();
}

/**
 * @param  -the main function of the program.
 *
 * @brief This function is used to call to make the window and all the object needed
 */
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