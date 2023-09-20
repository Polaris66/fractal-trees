#include <GL/glut.h>

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0); // Adjust the projection matrix

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(0.0f, 1.5f);      // Top vertex
    glVertex2f(-1.5f, -1.0f);    // Bottom-left vertex
    glVertex2f(1.5f, -1.0f);     // Bottom-right vertex
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Example");

    glutDisplayFunc(render);

    glutMainLoop();

    return 0;
}
