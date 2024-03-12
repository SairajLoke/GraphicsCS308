#include <GL/glut.h>
#include <cmath>
#include <iostream>

int windowHeight = 600;
int windowWidth = 800;

void drawPixelNew(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int incX = (x1 < x2) ? 1 : -1;
    int incY = (y1 < y2) ? 1 : -1;
    float fillColor[3] = {1, 0, 0};

    int x = x1;
    int y = y1;

    drawPixelNew(x, y);

    if (dx > dy) {
        int p = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            if (p >= 0) {
                y += incY;
                p -= 2 * dx;
            }
            x += incX;
            p += 2 * dy;
            drawPixelNew(x, y);
        }
    } else {
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            if (p >= 0) {
                x += incX;
                p -= 2 * dy;
            }
            y += incY;
            p += 2 * dx;
            drawPixelNew(x, y);
        }
    }
}

void drawCircle(int xc, int yc, int x, int y) {
    float fillColor[3] = {1, 0, 0};
    drawPixelNew(xc + x, yc + y);
    drawPixelNew(xc - x, yc + y);
    drawPixelNew(xc + x, yc - y);
    drawPixelNew(xc - x, yc - y);
    drawPixelNew(xc + y, yc + x);
    drawPixelNew(xc - y, yc + x);
    drawPixelNew(xc + y, yc - x);
    drawPixelNew(xc - y, yc - x);
}

void bresenhamCircle(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    drawCircle(xc, yc, x, y);

    while (y >= x) {
        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }

        drawCircle(xc, yc, x, y);
    }
}

void drawCar() {

    glColor3f(1, 1, 0.5);
    drawLine(100, 100, 700, 100);
    drawLine(100, 100, 100, 180); 
    drawLine(700, 100, 700, 180); 
    drawLine(100, 180, 700, 180); 
    drawLine(250, 180, 280, 250);
    drawLine(280, 250, 520, 250);
    drawLine(550, 180, 520, 250);

    glColor3f(0.5, 0.5, 0.5);
    bresenhamCircle(250, 100, 35);
    bresenhamCircle(550, 100, 35);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCar();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Bus Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}