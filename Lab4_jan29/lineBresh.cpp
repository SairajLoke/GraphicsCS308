

#include <bits/stdc++.h>
using namespace std;
#include <GL/glut.h>
#include <cmath>

struct Point {
    float x, y;
};

vector<Point> points; // Vector to store points

void drawPoint(float x, float y) {
    glColor3f(0.0f, 1.0f, 0.0f); // green color
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void addPoint(float x, float y) {
    points.push_back({x, y});
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
    float xStart, yStart, xEnd, yEnd;
    xStart = 30;
    yStart = 40;
    xEnd = 70;
    yEnd = 100;
    float slope = (yEnd - yStart) / (xEnd - xStart);
    float deltaY = yEnd - yStart;
    float deltaX = xEnd - xStart;
    int steps;

    // First case m < 1
    if (slope < 1.0) {
        steps = xEnd - xStart;
        float x = xStart;
        float y = yStart;
        float decisionParam = 2 * deltaY - deltaX;

        addPoint(x, y);

        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaY;
                x += 1;
            } else {
                decisionParam += 2 * deltaY - 2 * deltaX;
                x += 1;
                y += 1;
            }

            addPoint(x, y);
        }
    }
    // Second case m = 1
    if (slope == 1.0) {
        float x = xStart, y = yStart;

        addPoint(x, y);

        steps = xEnd - xStart;
        for (int add = 1; add <= steps; add++) {
            x += 1;
            y += 1;

            addPoint(x, y);
        }
    }
    // Third case m > 1
    if (slope > 1) {
        float x = xStart, y = yStart;
        addPoint(x, y);

        steps = yEnd - yStart;
        float decisionParam = 2 * deltaX - deltaY;
        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaX;
                y += 1;
            } else {
                decisionParam += 2 * deltaX - 2 * deltaY;
                x += 1;
                y += 1;
            }

            addPoint(x, y);
        }
    }

    // Draw points from the vector
    for (const auto& point : points) {
        drawPoint(point.x, point.y);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q2 Bresenham's");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    gluOrtho2D(0, 100, 0, 100);             // 2D Orthographic projection

    glutDisplayFunc(displayMe);

    glutMainLoop();

    return 0;
}












































// #include <iostream>













// #include <GL/glut.h>

// using namespace std;

// // Structure to hold a point (x, y)
// struct Point {
//     int x;
//     int y;
// };

// // Function to draw a line using Bresenham's algorithm
// void drawLine(Point p1, Point p2) {
//     int dx = abs(p2.x - p1.x);
//     int dy = abs(p2.y - p1.y);

//     int x, y;
//     int incrX = p1.x < p2.x ? 1 : -1;
//     int incrY = p1.y < p2.y ? 1 : -1;

//     int err = dx - dy;

//     x = p1.x;
//     y = p1.y;

//     glBegin(GL_POINTS);
//     while (true) {
//         glVertex2i(x, y);
//         cout<<x<<" "<<y<<endl;
//         if (x == p2.x && y == p2.y)
//             break;

//         int err2 = 2 * err; //2dx - 2dy  >  -dy
//         if (err2 > -dy) {
//             err -= dy;  //dx -
//             x += incrX;
//         }
//         if (err2 < dx) {
//             err += dx;
//             y += incrY;
//         }
//     }
//     glEnd();
//     glFlush();
// }

// // Function to handle drawing
// void display() {
//     Point p1, p2;
//     p1.x = 0;
//     p1.y = 200;

//     p2.x = 700;
//     p2.y = 500;


//     // Set the color of the line to blue
//     glColor3f(0.0, 1.0, 0.0);

//     // Draw the line
//     drawLine(p1, p2);
// }

// int main(int argc, char** argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("Bresenham's Line Drawing");
//     glutDisplayFunc(display);
//     glClearColor(1.0, 1.0, 1.0, 0.0);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, 500, 0, 500);

//     // Start the main loop
//     glutMainLoop();

// return 0;
// }