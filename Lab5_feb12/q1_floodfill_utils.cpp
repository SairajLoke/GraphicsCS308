#include <GL/glut.h>
#include<vector>
#include<utility>


std::vector<std::pair<double,double>>dir8 = {{1.0,0.0},{0.0,1.0},{-1.0,0.0},{0.0,-1.0} , {1.0,-1.0},{-1.0,-1.0},{-1.0,1.0},{1.0,1.0}};
std::vector<std::pair<double,double>>dir4 = {{1.0,0.0},{0.0,1.0},{-1.0,0.0},{0.0,-1.0}};


struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

Color whiteColor = {1.0, 1.0, 1.0}; // black background
Color blackColor = {0.0, 0.0, 0.0}; // fill inside with white color
Color ColorBoundary = whiteColor; 

Color ColorWheelFront = {1.0, 0.0, 0.0};
Color ColorWheelRear = {1.0, 0.0, 0.0};
Color ColorCarBody = {1.0, 1.0, 1.0};
Color ColorCarRoof ={0.0, 0.0, 1.0};

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


bool isBoundaryORAlreadyFilled(Color Boundary, Color newColor, Color color ){
    return (Boundary.r==color.r&&Boundary.g==color.g&&Boundary.b==color.b)||(newColor.r==color.r&&newColor.g==color.g&&newColor.b==color.b);
}

bool is4NeighBdry(Color Boundary, GLint x , GLint y){
    
    for(auto n: dir4){
        Color color = getPixelColor(x+n.first, y + n.second);
        if(Boundary.r==color.r&&Boundary.g==color.g&&Boundary.b==color.b){ return true; }
    }

    return false;// none of 4 directions is a boundary cell

}