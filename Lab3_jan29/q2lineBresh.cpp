#include <bits/stdc++.h>
using namespace std;
#include <GL/glut.h>
#include <cmath>


/*
Sairaj R. Loke 210001035
CS352 Lab3 Q2 Bresenhem for line drawing

Note:
*/



struct Point {
    float x, y;
};

vector<Point> points; // Vector to store points

void drawthisPoint(float x, float y) {
    glColor3f(0.0f, 1.0f, 1.0f); // pt color
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void addthisPoint(float x, float y) {
    points.push_back({x, y});
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
    float xStart, yStart, xEnd, yEnd;
    xStart = 40;
    yStart = 40;
    xEnd = 100;
    yEnd = 100;
    float slope = (yEnd - yStart) / (xEnd - xStart);
    float delta_Y = yEnd - yStart;
    float delta_X = xEnd - xStart;
    int steps;

    // First case m < 1
    if (slope < 1.0) {
        steps = xEnd - xStart;
        float x = xStart;
        float y = yStart;
        float decisionParam = 2*delta_Y - delta_X;

        addthisPoint(x, y);

        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2*delta_Y;
                x += 1;
            } else {
                decisionParam += 2*delta_Y - 2*delta_X;
                x += 1;
                y += 1;
            }
            addthisPoint(x, y);
        }
    }
    // Second case m = 1
    if (slope == 1.0) {
        float x = xStart, y = yStart;
        addthisPoint(x, y);
        steps = xEnd - xStart;
        for (int add = 1; add <= steps; add++) {
            x += 1;
            y += 1;
            addthisPoint(x, y);
        }
    }
    // Third case m > 1
    if (slope > 1) {
        float x = xStart, y = yStart;
        addthisPoint(x, y);
        steps = yEnd - yStart;
        float decisionParam = 2*delta_X - delta_Y;
        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2*delta_X;
                y += 1;
            } else {
                decisionParam += 2*delta_X - 2*delta_Y;
                x += 1;
                y += 1;
            }
            addthisPoint(x, y);
        }
    }

    // Draw points from the vector
    for (const auto& point : points) {
        drawthisPoint(point.x, point.y);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Q2 Sairaj Bresenham's");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    gluOrtho2D(0, 100, 0, 100);             // 2D Orthographic projection

    glutDisplayFunc(displayMe);

    glutMainLoop();

    return 0;
}


