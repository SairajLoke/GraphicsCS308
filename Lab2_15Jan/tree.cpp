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

int treex = 100;
int treey = 100;

std::tuple <float,float,float> dgreen(0,255,0);   // 0 to 255 , norm 0 to 1 taken care in triangle
std::tuple <float,float,float> mgreen(57, 173 ,72);
std::tuple <float,float,float> lgreen(144,238,144);
std::tuple <float,float,float> brown(165,42,42);



glClear(GL_COLOR_BUFFER_BIT);//set bit plane area of the window
polygon(treex +110,treey + 110,treex +140,treey + 110,treex +140,treey + 175,treex +110,treey + 175,brown );//20,138.0,115.0,98.
// polygon(100, 100, 150, 100, 150, 175, 100, 175, 0, 138.0, 115.0, 98.0);

triangle(treex + 75,treey+175,treex +175,treey+175,treex +125,treey+225,mgreen);
triangle(treex + 75,treey+200,treex +175,treey+200,treex +125,treey+250,dgreen);
triangle(treex + 75,treey+225,treex +175,treey+225,treex +125,treey+275,lgreen);  //top


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