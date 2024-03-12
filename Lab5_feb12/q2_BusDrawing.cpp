#include <GL/glut.h>
#include <cmath>
#include <iostream>


/*
Sairaj R. Loke 210001035
CS352 Lab5 Q2

Note:
My experiments with scan color have removed as according to CR this scan coloring was not to be submitted for q2 of lab5 
*/

struct Color{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};
Color boundaryColor = {1.0, 1.0, 1.0}; // white boundary
Color backgroundColor = {1.0, 1.0, 1.0}; // black background


int centreX = 200.0;
int centreY = 150.0;


void setPixelcolor(int x, int y) {
    glColor3f(boundaryColor.red, boundaryColor.green, boundaryColor.blue); 
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}



void drawLine(int x1, int y1, int xn, int yn) {
    int dx = abs(xn - x1);
    int dy = abs(yn - y1);
    int x = x1;
    int y = y1;
    int step_X = (x1 < xn) ? 1 : -1;
    int step_Y = (y1 < yn) ? 1 : -1;
    int d = 2*dy - dx;

    if (dx >= dy) {
        while(x!=xn){
            setPixelcolor(x,y);
            if (d >= 0) {
                y += step_Y;
                d -= 2*dx;
            }
            x += step_X;
            d += 2*dy;
        }
    } else {
        while (y != yn) {
            setPixelcolor(x,y);
            if (d >= 0) {
                x += step_X;
                d -= 2*dy;
            }
            y += step_Y;
            d += 2*dx;
        }
    }
}


void drawCircle(double xc, double yc, double r)
{
    glBegin(GL_POINTS);
    double x1 = 0, y1 = r;
    double x = x1, y = y1;
    double p = 3 - 2 * r;

    while (x <= y)
    {
        //translating the circle/ 
        glVertex2f(x + xc, y + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);
        glVertex2f(y + xc, x + yc);
        glVertex2f(-y + xc, x + yc);
        glVertex2f(y + xc, -x + yc);
        glVertex2f(-y + xc, -x + yc);

        x = x + 1;
        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            p = p + 4 * x - 4 * y + 10;
            y = y - 1;
        }
    }
    glEnd();
}

void drawBus() {

    glColor3f(boundaryColor.red, boundaryColor.green, boundaryColor.blue); 

    int wheelRadius = 45;
    int fx = 600;
    int fy = 100;
    int rx = 200;
    int ry = 100;

    //outer
    drawLine(rx-100, ry, rx-wheelRadius, ry);
    drawLine(rx+wheelRadius, ry, fx-wheelRadius, ry);
    drawLine(fx+wheelRadius, fy, fx+100, fy);
    drawLine(rx-100,ry, rx-100, ry+160); 
    drawLine(fx+100, fy, fx+100, fy+160); 
    drawLine(rx-100, ry+160, fx+100, fy+160); 

    //door
    drawLine(fx/2 , ry, fx /2 , ry+100);
    drawLine(fx/2, 200, fx/2 + 60, 200);
    drawLine(fx/2 + 60, ry, fx/2 + 60, ry+100);

    //window1
    drawLine(fx-200, fy+100, fx-140, fy+100);
    drawLine(fx-200, fy+40, fx-140, fy+40);
    drawLine(fx-200, fy+40, fx-200, fy+100);
    drawLine(fx-140, fy+40, fx-140, fy+100);

    //window2
    drawLine(fx-100, fy+100, fx-40, fy+100);
    drawLine(fx-100, fy+40, fx-40, fy+40);
    drawLine(fx-100, fy+40, fx-100, fy+100);
    drawLine(fx-40, fy+40, fx-40, fy+100);

    drawCircle(rx, ry , wheelRadius);
    drawCircle(fx, fy, wheelRadius);
}

struct pt{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
};

void display() {
    glColor3f(boundaryColor.red, boundaryColor.green, boundaryColor.blue); 


    //below pts were the scan seeds
    pt bdy;
    bdy.x = 200;
    bdy.y = 150;

    pt door;
    door.x = 400;
    door.y = 150;
    pt dr = door;

    pt tyre;
    tyre.x = 600;
    tyre.y = 125;


    drawBus();
    //  not doing the scan color as according to CR this scan coloring was not to be submitted for q2 of lab5 


    glFlush();
}





int main(int argc, char** argv) {
    glutInit(&argc, argv);
    int windowHeight = 800;
    int windowWidth = 800;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Madhav Lab5 Q2 Drawing");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}