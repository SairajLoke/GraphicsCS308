#include <GL/glut.h>  //already in hpp but pragma once takes care of it
#include<iostream>
#include<queue>
using std::cout ;
using std::endl ;
using std::swap ; 
using std::queue ;
using std::pair  ;

#include "q1_floodfill_utils.hpp"

/*
Sairaj R. Loke 210001035
CS352 Lab5 Q1

Note:
Main file for Q1
the cpp and hpp have been created to decrease the content in this single file...
didnt do it for other files as the content was comparatively less, also making another doesnt affect performance
*/



void verticalLine(double x1, double y1, double x2, double y2){
    glBegin(GL_POINTS);
        if (y2 < y1)
            std::swap(y1, y2);
        double y = y1;
        while (y <= y2)
        {
            glVertex2f(x1, y);
            y += 1;
        }
        glEnd();
        // glFlush();
        return;
}
void circle_b(double xc, double yc, double r)
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
void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    // float xc,yc,r;
    // cout<<"Input the coordinates of centre and radius as xc yc r  : ";
    // cin>>xc>>yc>>r;
	circle_b(0,0,15);
	
	glFlush();
}
void lineBRE(double x1,double y1, double x2, double y2)
{
    // double x1 = x1, y1 = y1, x2 = x2, y2 = y2;
    // if vertical line is there
    if (x1 == x2)
    {
        verticalLine(x1,y1,x2,y2);
        return;
    }
    // now we start Bresenham aalgorithm
    double dx = (x2 - x1), dy = (y2 - y1);
    double m = dy / dx;
    // double c = (y1 * x2 - y2 * x1) / (x2 - x1);
	
    glBegin(GL_POINTS);
    double p = 2 * dy - dx;
    if (abs(m) < 1)
    {
        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        double x = x1, y = y1;
        while (x <= x2)
        {

            glVertex2f(x, y);
            if (p < 0)
            {
                p = p + 2 * dy;
                y = y;
                x += 1;
            }
            else
            {
                p += 2 * dy - 2 * dx;
                x++;
				if(m>=0)y+=1;
				else y-=1;
            }
        }
    }
    else
    {
        if (y1 > y2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        double x = x1, y = y1, m2 = 1 / m;
        while (y <= y2)
        {
            glVertex2f(x, y);
            if (p < 0)
            {
                p = p + 2 * dx;
                // y = y;
                y += 1;
            }
            else
            {
                p += 2 * dx - 2 * dy;
                if(m>=0)x+=1;
				else x-=1;
                y++;
            }
        }
    }
    glEnd();
}

// Function for line generation using bresenhem
void lineBRE_2(double x1, double y1, double x2, double y2)
{
    // Find Delta
    double dx = x2-x1;
    double dy = y2-y1;
	if(x1==x2){
		verticalLine(x1,y1,x2,y2);
        return;
	}
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);
    double x = x1;
    double y = y1;
    bool swad = 0;
    if(abs(dy) > abs(dx))
    {
        swap(dx,dy);
        swad=1;
    }
    double p = 2*abs(dy) - abs(dx);

    //Print Initial Point
	glBegin(GL_POINTS);
    glVertex2f(x,y);

    // Loop for dx times
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(swad == 0){
                x = x + sx;
                glVertex2f(x,y);
            }
            else{
                y = y+sy;
                glVertex2f(x,y);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            glVertex2f(x,y);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
	glEnd();
}



void floodFill(GLint x, GLint y, Color oldColor, Color newColor,Color Boundary, queue<pair<double,double>>&q) {
	Color color;
	
    q.push({x,y});
    int count=0;
    setPixelColor(x, y, newColor);
    while (!q.empty())
    {   
        count++;
        auto pr = q.front();
        x = pr.first;
        y= pr.second;
        
        q.pop();//remove the current node

        auto neighdir = dir8;//by default dir8 ( as in question)
        if(is4NeighBdry(Boundary,x,y)){  //ie. if neighboudring ( NEWS directions then only do dir4 neigbour
                                         //  to avoid leaking into the surroudning space)
            neighdir = dir4;
        }

        
        for(auto adt:neighdir){  //for each of the neighbours
            
            double tempX=adt.first+x;
            double tempY=adt.second+y;
            color = getPixelColor(tempX, tempY);

            if(isBoundaryORAlreadyFilled(Boundary,newColor, color)){
                // std::cout<<"condition works "<<tempX<<" "<<tempY<<std::endl;
                continue;
            }else{
                setPixelColor(tempX, tempY, newColor);
                q.push({tempX,tempY});//add the neigh in queue if valid
            }
        }
        
        
        
    }
    
	return;
}

void drawCar(){
    glColor3f(ColorBoundary.r, ColorBoundary.g, ColorBoundary.b);  //border of Car

    //Rear and Front wheel
    int wheelRadius = 50;
    int rx = 200;
    int fy = 200;
    int ry = fy; //front y
    int fx = 600; //rear x 
	circle_b(fx,fy,wheelRadius);
	circle_b(rx,ry,wheelRadius);


	lineBRE(rx-wheelRadius*3, ry,rx-wheelRadius,ry);  // behind rear wheel
	lineBRE(rx+wheelRadius,ry,fx-wheelRadius,fy); // btw rear and front wheel
	lineBRE(fx+wheelRadius,fy,fx+wheelRadius*3,fy);  // after front wheel 
	lineBRE(rx-wheelRadius*3,ry,rx-wheelRadius*3,ry+100);   // rear verti
	lineBRE(fx+wheelRadius*3,fy,fx+wheelRadius*3,fy+100);  //front verti
	lineBRE(rx-wheelRadius*3,ry+100,fx+wheelRadius*3,fy+100);   // hori window
	lineBRE(rx-wheelRadius,ry+100,rx,ry+200);  //rear slant
	lineBRE_2(fx+wheelRadius,fy+100,fx,fy+ 200); // front slant
	lineBRE(rx,fy+200,fx,ry+200);  //roof 
}
void disp(void){
	glClear(GL_COLOR_BUFFER_BIT);

    queue<pair<double,double>>q;
    
    
    drawCar();
    
    Color floodColor = ColorWheelRear;
	floodFill(200,200,blackColor,floodColor,ColorBoundary,q);
    q = {}; //clearing the queue ...valid for c++ 11 onwards

    floodColor = ColorWheelFront;
    floodFill(600,200,blackColor,floodColor,whiteColor,q);
    q = {};

    floodColor = ColorCarRoof;
    floodFill(600,301,blackColor,floodColor,whiteColor,q);
    q= {};

    floodColor = ColorCarBody;
    floodFill(500,205,blackColor,floodColor,whiteColor,q);
    q = {};


	glFlush();
}



int main(int argc, char **argv){
    int windowHeight = 800;
    int windowWidth = 800;

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(windowHeight,windowWidth); // display window size
	glutInitWindowPosition(100, 100); // display window popping position
	glutCreateWindow("Flood Fill"); // title of the window

    // initialise opengl window
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION); // projection model used
	gluOrtho2D(0, 800, 0, 800); // orthographic window boundary defined
	// glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 0); // specifies values used by glClear to clear the buffer
	glClearColor(0.0,0.0,0.0,1);
	glClear(GL_COLOR_BUFFER_BIT); // clears existing buffer values

	glutDisplayFunc(disp); // calling the display function
	glutMainLoop(); // refreshes the window if there is any change
	return 0;
}