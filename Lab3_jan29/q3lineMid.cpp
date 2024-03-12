#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;


/*
Sairaj R. Loke 210001035
CS352 Lab3 Q3 Midpt for line drawing

Note:
*/


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // green color
    double x1 = 0, y1 = 0, x2 = 100, y2 = 100;
    if (x1 == x2)  //to take care of vertical line
    {
        glBegin(GL_POINTS);

        if (y2 < y1){std::swap(y1, y2);}
        double y = y1;
        while (y <= y2){glVertex2f(x1, y);y += 1;}

        glEnd();
        glFlush();
        return;
    }

    double m = (y2 - y1) / (x2 - x1);
    double c = (y1 * x2 - y2 * x1) / (x2 - x1);
    glBegin(GL_POINTS);
    double dx = (x2 - x1), dy = (y2 - y1);
    if (abs(m) < 1)
    {
        if (x1 > x2)  //to go from left to right
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        double a = dy, b = -dx;
        double d = a + b / 2; //decision para
        double x = x1, y = y1;
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;
            if (d < 0){d = d + dy;}
            else{d = d + dy - dx;y = y + 1;}
        }
    }
    else
    {
        if (y1 > y2){std::swap(x1, x2);std::swap(y1, y2);}

        double a = dy, b = -dx;
        double d = dx - dy / 2;
        double x = x1, y = y1;
        while (y <= y2)
        {
            glVertex2f(x, y);
            y = y + 1;
            if (d < 0){d = d + dx;}
            else{d = d + dx - dy;x = x + 1;}
        }
    }
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sairaj Q3_midpoint");
    glutDisplayFunc(displayMe);
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop();
    return 0;
}