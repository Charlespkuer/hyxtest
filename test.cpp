#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(-5, 0, 0);
    glVertex3f(5, 0, 0);
    glVertex3f(0, -5, 0);
    glVertex3f(0, 5, 0);
    glVertex3f(0, 0, -5);
    glVertex3f(0, 0, 5);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    for (float x = -PI; x <= PI; x += 0.1)
    {
        float y = sin(x);
        float z = cos(x);
        glVertex3f(x, y, z);
    }
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Function Plot");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
