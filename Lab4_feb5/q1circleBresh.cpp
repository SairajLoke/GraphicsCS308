#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;

/*
Sairaj R. Loke 210001035
CS352 Lab4 Q1 Bresenhem for circle drawing

Note:
*/


void circleBresh(float centerx,float centery, float radius){
 

    glColor3f(0.0,1.0,0.0);
    GLfloat centerX = centerx;
    GLfloat centerY = centery;

    //draw wrt origin then shift to cx cy
    float x = 0.0;
    float y = radius;

    // float incre_angle = 1/radius ;
    // float f = (x+1)^2 + (y - 1/2)^2 - radius^2 ; //here x is updated
    // float f = 2*x - y + 5/4; s
    float f =  2*pow((x+1),2.0) + pow(y,2) + pow((y-1),2) - 2*pow(radius,2) ;
    cout<<"c"<<endl;

    
    cout<<x<<endl;
    glBegin(GL_POINTS);
    while( x <= y){//consider center 0 while calculating


        if ( f < 0 ){
            f = f + 6 + 4*x;  //impt
            x = x + 1;
            y = y; //closer to NE
            
            
        }
        else {
            f = f + 4*x - 4*y + 10;
            x = x + 1;
            y = y-1; //closer to E
            
        }

        cout<<"c"<<x+centerX<<" "<<y + centerY<<endl;
        glVertex2i( x+centerX, y+centerY);   // add relative to the center
        glVertex2i( y+centerX, x+centerY); 
        glVertex2i(-x+centerX, y+centerY);  //image accross y axis
        glVertex2i( y+centerX,-x+centerY);   //a
        glVertex2i(-x+centerX,-y+centerY); 
        glVertex2i(-y+centerX, -x+centerY);  //image accross y axis
        glVertex2i( x+centerX,-y+centerY);   //a
        glVertex2i(-y+centerX,x+centerY); 
    }
    glEnd(); 
       

}



void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

    //currently for l to right
    circleBresh(100, 100, 20);
 
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Sairaj Circle Bresh");
    glutDisplayFunc(display);
    glutMainLoop();

    // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);


    return 0;
}




// glLoadIdentity();

