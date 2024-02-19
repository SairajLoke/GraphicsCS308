#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
//reference : https://github.com/sprintr/opengl-examples/blob/master/OpenGL-FloodFill-Circle.cpp
//reference : previous assignments for bresenham algorithms.
//  Bur since earlier bresenham's code was not arranged for slope negative slopes.

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

// Function for line generation
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
struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};
Color floodColor = {1.0, 0.0, 0.0}; // red boundary
Color whiteColor = {1.0, 1.0, 1.0}; // black background
Color blackColor = {0.0, 0.0, 0.0}; // fill inside with white color
void setPixelColor(double x, double y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
Color getPixelColor(double x, double y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}
// queue<pair<double,double>> q;
vector<pair<double,double>>fd = {{1.0,0.0},{0.0,1.0},{-1.0,0.0},{0.0,-1.0}};
void floodFill(GLint x, GLint y, Color oldColor, Color newColor,Color Boundary, queue<pair<double,double>>&q) {
	Color color;
	
    q.push({x,y});
    int count=0;
    setPixelColor(x, y, newColor);
    while (!q.empty())
    {
        
        // if(count==20){
        //     break;
        // }
        count++;
        auto pr = q.front();
        x = pr.first;
        y= pr.second;
        
        q.pop();
        std::cout<<q.size()<<std::endl;
        // printf("%d %d \n",x,y);
        // color = getPixelColor(x, y);
        for(auto adt:fd){
            
            double tempX=adt.first+x;
            double tempY=adt.second+y;
            // printf("%d %d \n")
            std::cout<<tempX<<" "<<tempY<<std::endl;
            color = getPixelColor(tempX, tempY);
            if((Boundary.r==color.r&&Boundary.g==color.g&&Boundary.b==color.b)||(newColor.r==color.r&&newColor.g==color.g&&newColor.b==color.b)){
                // printf("Condition works %d %d \n",tempX,tempY);
                std::cout<<"condition works "<<tempX<<" "<<tempY<<std::endl;
                continue;
            }else{
                // printf("In the else ");
                // printf("%d %d \n",tempX,tempY);
                setPixelColor(tempX, tempY, newColor);
                q.push({tempX,tempY});
            }
        }
        
        // else{
            
        //     q.push({x+1,y});
        //     q.push({x,y+1});
        //     q.push({x-1,y});
        //     q.push({x,y-1});
        // }  
        
        
        
        
    }
    
	// if((Boundary.r==color.r&&Boundary.g==color.g&&Boundary.b==color.b)||(newColor.r==color.r&&newColor.g==color.g&&newColor.b==color.b)){
	// 	return;
	// }else if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	// {

    //     printf("%d %d \n",x,y);
		
	// 	floodFill(x+1, y, oldColor, newColor,Boundary,q);
	// 	floodFill(x, y+1, oldColor, newColor,Boundary,q);
	// 	// floodFill(x-1, y, oldColor, newColor,Boundary);
	// 	// floodFill(x, y-1, oldColor, newColor,Boundary);
	// }
	return;
}
void disp(void){
	glClear(GL_COLOR_BUFFER_BIT);
    // float xc,yc,r;
    // cout<<"Input the coordinates of centre and radius as xc yc r  : ";
    // cin>>xc>>yc>>r;
    glColor3f(1.0,1.0,1.0);
	circle_b(200,200,50);
	circle_b(600,200,50);
	lineBRE(50,200,150,200);
	lineBRE(250,200,550,200);
	lineBRE(650,200,750,200);
	lineBRE(50,200,50,300);
	lineBRE(750,200,750,300);
	lineBRE(50,300,750,300);
	lineBRE(150,300,200,400);
	lineBRE_2(650,300,600,400);
	lineBRE(200,400,600,200);
	// while (!q.empty())
	// {
	// 	q.pop();
	// }
    queue<pair<double,double>>q;
	// glClear(GL_COLOR_BUFFER_BIT);
    
	floodFill(200,200,blackColor,floodColor,whiteColor,q);
    floodColor.g = 1.0;
    floodFill(600,200,blackColor,floodColor,whiteColor,q);

    floodColor.b = 1.0;
    floodFill(600,301,blackColor,floodColor,whiteColor,q);

    floodColor.g = 0.0;
    floodFill(500,205,blackColor,floodColor,whiteColor,q);
    // floodColor.g = 1.0;
    // floodFill(600,200,blackColor,floodColor,whiteColor,q);

	glFlush();
}

int main(int argc, char **argv){

    // cout<<"Enter the number of vertices of the regular polygon.\n";
    // cin>>vertex;
    // generatePolygonPoints(); // center of screen

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,800); // display window size
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