#include <GL/glut.h>
#include <cmath>
#include <iostream>

int windowHeight = 600;
int windowWidth = 800;
struct Color{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};
Color boundColor = {1.0, 0.0, 0.0}; // red boundary
Color backgroundColor = {1.0, 1.0, 1.0}; // black background


int centreX = 200.0;
int centreY = 150.0;


void setPixel(int x, int y) {
    glColor3f(boundColor.red, boundColor.green, boundColor.blue); 
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// check whether current pixel color is same as background color
bool colorEqualBoundary(Color currentColor){
	return (currentColor.green == boundColor.green && currentColor.blue == boundColor.blue && currentColor.red == boundColor.red);
}

// check whether current pixel color is same as fill color
bool colorEqualFill(Color currentColor,Color insideColor){
	return (currentColor.green == insideColor.green && currentColor.blue == insideColor.blue && currentColor.red == insideColor.red);
}

Color getColorPixel(GLint pointX, GLint pointY){
	Color pointColor;
    // used to return pixel data
	glReadPixels(pointX, pointY, 1, 1, GL_RGB, GL_FLOAT, &pointColor);
	return pointColor;
}

bool isPixelValid(int x, int y,Color insideColor){
	return (!colorEqualBoundary(getColorPixel(x, y)) && !colorEqualFill(getColorPixel(x, y),insideColor));
}

void fillColorPixel(GLint pointX, GLint pointY,Color insideColor){
    // set color of a pixel to be the internal color
	glColor3f(insideColor.red, insideColor.green, insideColor.blue);
	glBegin(GL_POINTS);
	glVertex2i(pointX, pointY); // draw the point (internal to the polygon)
	glEnd();
	glFlush();
}


// fill inside of polygon using flood fill algorithm - recursion based
void ScanLineSeedAlgoRecursionBased(int currX, int currY,Color insideColor){
	
	if(!isPixelValid(currX, currY,insideColor)){return;}//valid means 

	// find right end point and meanwhile fill current scan line
	int currRightPixel = currX;
	while(!colorEqualBoundary(getColorPixel(currRightPixel, currY))){
		fillColorPixel(currRightPixel, currY,insideColor);
		currRightPixel++;
	}
	currRightPixel--; // inside polygon

	// find left end point and meanwhile fill current scan line
	int currLeftPixel = currX;
	while(!colorEqualBoundary(getColorPixel(currLeftPixel, currY))){
		fillColorPixel(currLeftPixel, currY,insideColor);
		currLeftPixel--;
	}
	currLeftPixel++; // inside polygon

	// scan above scan line
	int xtemp = currLeftPixel;
	int ytemp = currY + 1;
	bool findNewSeed = false;
	while(xtemp <= currRightPixel){
		findNewSeed = false;
		while(isPixelValid(xtemp, ytemp,insideColor) && (xtemp < currRightPixel)){
			findNewSeed= true;
			xtemp++;
		}
		if(findNewSeed){
			if(isPixelValid(xtemp, ytemp,insideColor) && (xtemp == currRightPixel))
				ScanLineSeedAlgoRecursionBased(xtemp, ytemp,insideColor);
			else { //if(isPixelValid(xtemp, ytemp,insideColor) )
                std::cout<<xtemp<<" "<<ytemp<<"-";
				ScanLineSeedAlgoRecursionBased(xtemp-1, ytemp,insideColor);
            }
		}
		/* Skips the internal invalid point to the right (the case where there is an obstacle at the right end of the processing interval)*/
		int xspan = 0;
		while(colorEqualBoundary(getColorPixel(xtemp+xspan, ytemp)))
			xspan++;
		/* handles special cases to exit the while(x<=currRightPixel) loop*/
		xtemp += (xspan ==0) ? 1 : xspan;
	}

	// scan below scan line
	xtemp = currLeftPixel;
	ytemp = currY - 1;
	findNewSeed = false;
	while(xtemp <= currRightPixel){
		findNewSeed = false;
		while(isPixelValid(xtemp, ytemp,insideColor) && (xtemp < currRightPixel)){
			findNewSeed= true;
			xtemp++;
		}
		if(findNewSeed){
			if(isPixelValid(xtemp, ytemp,insideColor) && (xtemp == currRightPixel))
				ScanLineSeedAlgoRecursionBased(xtemp, ytemp,insideColor);
			else
				ScanLineSeedAlgoRecursionBased(xtemp-1, ytemp,insideColor);
		}
		/* Skips the internal invalid point to the right (the case where there is an obstacle at the right end of the processing interval)*/
		int xspan = 0;
		while(colorEqualBoundary(getColorPixel(xtemp+xspan, ytemp)))
			xspan++;
		/* handles special cases to exit the while(x<=currRightPixel) loop*/
		xtemp += (xspan == 0) ? 1 : xspan;
	}


}


// #-------------------------------------------------------------------------------


void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;

    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;

    int d = 2 * dy - dx;

    if (dx >= dy) {
        while (x != x2) {
            setPixel(x, y);

            if (d >= 0) {
                y += stepY;
                d -= 2 * dx;
            }

            x += stepX;
            d += 2 * dy;
        }
    } else {
        while (y != y2) {
            setPixel(x, y);

            if (d >= 0) {
                x += stepX;
                d -= 2 * dy;
            }

            y += stepY;
            d += 2 * dx;
        }
    }
}

void drawCircle(int centerX, int centerY, int radius) {
    int x = 0, y = radius;
    int d = 1 - radius;

    while (x <= y) {
        setPixel(centerX + x, centerY + y);
        setPixel(centerX - x, centerY + y);
        setPixel(centerX + x, centerY - y);
        setPixel(centerX - x, centerY - y);
        setPixel(centerX + y, centerY + x);
        setPixel(centerX - y, centerY + x);
        setPixel(centerX + y, centerY - x);
        setPixel(centerX - y, centerY - x);

        x++;

        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}

void drawBus() {

    glColor3f(boundColor.red, boundColor.green, boundColor.blue); 
    drawLine(100, 100, 700, 100);
    drawLine(100, 100, 100, 260); 
    drawLine(700, 100, 700, 260); 
    drawLine(100, 260, 700, 260); 

    drawLine(300, 100, 300, 200);
    drawLine(300, 200, 360, 200);
    drawLine(360, 100, 360, 200);

    drawLine(400, 200, 460, 200);
    drawLine(400, 140, 460, 140);
    drawLine(400, 140, 400, 200);
    drawLine(460, 140, 460, 200);

    drawLine(500, 200, 560, 200);
    drawLine(500, 140, 560, 140);
    drawLine(500, 140, 500, 200);
    drawLine(560, 140, 560, 200);

    glColor3f(0.5, 0.5, 0.5);
    drawCircle(200, 100, 45);
    drawCircle(600, 100, 45);
}

struct pt{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
};

void display() {
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(boundColor.red, boundColor.green, boundColor.blue); 

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

    Color insideColor2 = {0.0, 0.0, 1.0}; // fill inside with white color
    Color insideColor3 = {0.0, 1.0, 0.0}; // fill inside with white color
    Color insideColor4 = {1.0, 0.0, 1.0}; // fill inside with white color

    drawBus();
    // ScanLineSeedAlgoRecursionBased(dr.x,dr.y,insideColor2);
    
    // ScanLineSeedAlgoRecursionBased(bdy.x,bdy.y,insideColor3);
    ScanLineSeedAlgoRecursionBased(tyre.x,tyre.y,insideColor4);
    ScanLineSeedAlgoRecursionBased(tyre.x,tyre.y-50,insideColor4);
    ScanLineSeedAlgoRecursionBased(tyre.x-400,tyre.y+16,insideColor4);
    ScanLineSeedAlgoRecursionBased(tyre.x-400,tyre.y-50,insideColor4);

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Car Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}