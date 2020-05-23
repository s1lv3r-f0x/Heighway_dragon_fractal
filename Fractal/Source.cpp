#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <GL/glut.h>


double n = 8;
void Matr(double xA, double yA, double xB,
    double yB, int n)
{
    if (n == 0)
    {
        glVertex2d(xA, yA);
        glVertex2d(xB, yB);
    }
    else
    {
        double xC = (xA + xB) / 2 + (yB - yA) / 2;
        double yC = (yA + yB) / 2 - (xB - xA) / 2;
        Matr(xA, yA, xC, yC, n - 1);
        Matr(xB, yB, xC, yC, n - 1);
    }
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 1.0, 0.0); glLineWidth(2.0);
    glBegin(GL_LINES);
    Matr(0.4, 0.0, -0.4, 0.0, n);
    glEnd();
    glFinish();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Фрактал Дракон Хартера-Хейтуэя");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}