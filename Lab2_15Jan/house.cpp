#include<GL/glut.h>
#include<iostream>
#include<tuple>
using namespace std;

#define ll long long int


void polygon(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,tuple<float,float,float> color)
{
    float r = get<0>(color);
    float g = get<1>(color);
    float b = get<2>(color);

    glColor3f(r/255,g/255,b/255);
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        // glVertex2f(x1,y1);
    glEnd();
    
    

}
void triangle(float x1,float y1,float x2,float y2, float x3,float y3,tuple<float,float,float> color)
{
    float r = get<0>(color);
    float g = get<1>(color);
    float b = get<2>(color);


    glColor3f(r/255,g/255,b/255);
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        // glVertex2f(x1,y1);
    glEnd();
    
}
void draw(void){

std::tuple <float,float,float> dgreen(0,255,0);   // 0 to 255 , norm 0 to 1 taken care in triangle
std::tuple <float,float,float> mgreen(57, 173 ,72);
std::tuple <float,float,float> lgreen(144,238,144);
std::tuple <float,float,float> lbrown(181,109,29);
std::tuple <float,float,float> dbrown(92,54,61);
std::tuple <float,float,float> lred(150,0,0);


glClear(GL_COLOR_BUFFER_BIT);//set bit plane area of the window
polygon(110,110,230,110,230,225,110,225,lbrown); //,212.0,200.0,190.0);
polygon(155, 130, 185, 130, 185, 190, 155, 190, dbrown);
polygon(115, 155, 145, 155, 145, 190, 115, 190, dbrown);
polygon(195, 155, 225, 155, 225, 190, 195, 190, dbrown);
triangle(90,225,250,225,170,275, lred);
// triangle(75,200,175,200,125,250,1,0,200.0,0);
// triangle(75,225,175,225,125,275,2,0,200.0,0);
glFlush();




}



int main(int argc , char** argv){

    glutInit(&argc,argv); //to initialize the glut library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the initial dislpay node
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500); //set initial window size and position respectively

    glutCreateWindow("Tree");
    gluOrtho2D(0,500, 0,500);
    glutDisplayFunc(draw); //sets the callback for current window
    
    glutMainLoop(); //enters the GLUT event processing loop
    return 0 ;
}