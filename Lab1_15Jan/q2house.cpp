#include<GL/glut.h>
#include<iostream>
#include<tuple>
using namespace std;

#define ll long long int


/*
Sairaj R. Loke 210001035
CS352 Lab1 Q1 House

Note:
*/



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

std::cout<<"hello"<<std::endl;

glClear(GL_COLOR_BUFFER_BIT);//set bit plane area of the window

int basex= 100;
int basey= 100;
polygon(basex+10,basey+10,  basex+130,basey+10,  basex+130,basey+120,  basex+10,basey+120,  lbrown); //,212.0,200.0,190.0);
polygon(basex+50,basey+30,  basex+80, basey+30,  basex+80, basey+100,  basex+50,basey+100, dbrown);
polygon(basex+20,basey+50,  basex+40, basey+50,  basex+40, basey+100, basex+20, basey+100, dbrown);
polygon(basex+100, basey+50, basex+120,basey+50, basex+120,basey+100, basex+100,basey+100, dbrown);
triangle(basex-10,basey+120,basex+150,basey+120,basex+70,basey+170, lred);
// triangle(75,200,175,200,125,250,1,0,200.0,0);
// triangle(75,225,175,225,125,275,2,0,200.0,0);
glFlush();



}



int main(int argc , char** argv){

    glutInit(&argc,argv); //to initialize the glut library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the initial dislpay node
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500); //set initial window size and position respectively

    glutCreateWindow("Sairaj's House");
    gluOrtho2D(0,500, 0,500);
    glutDisplayFunc(draw); //sets the callback for current window
    
    glutMainLoop(); //enters the GLUT event processing loop
    return 0 ;
}