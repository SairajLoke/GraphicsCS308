#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;



void circleDirect(float centerx,float centery, float radius){
    
    glColor3f(0.0,0.0,1.0);
    // glBegin(GL_POLYGON);
    GLfloat angle , x ,y ;
    GLfloat centerX = centerx;
    GLfloat centerY = centery;

    glBegin(GL_POINTS);
    for(angle = 0.0f ; angle <= ( M_PI/ 2 ) ; angle += 0.01f){
        x = radius*sin(angle) + centerX;
        y = radius*cos(angle) + centerY;
        glVertex2i(x,y);
    }
    glEnd();    

    //reflection across x and y axis 
            //
}

void circleDDA(float centerx,float centery, float radius){
    
    glColor3f(0.0,1.0,0.0);
    // glBegin(GL_POLYGON);
    GLfloat angle ;
    GLfloat centerX = centerx;
    GLfloat centerY = centery;

    //draw wrt origin then shift to cx cy
    GLfloat x = radius;
    GLfloat y = 0.0;

    float incre_angle = 1/radius ;

    glBegin(GL_POINTS);
    while(x >= y ){
    // for(angle = 0.0f ; angle <= ( M_PI /2) ; angle += incre_angle){
        float x0 = x;
        float y0 = y; //to store prev vals else....below issue

        x = x0 - y0*incre_angle;
        y = x0*incre_angle + y0;

        glVertex2i( x+centerX, y+centerY);   // whats 2i
        glVertex2i( y+centerX, x+centerY); 
        glVertex2i(-x+centerX, y+centerY);  //image accross y axis
        glVertex2i( y+centerX,-x+centerY);   //a
        glVertex2i(-x+centerX,-y+centerY); 
        glVertex2i(-y+centerX, -x+centerY);  //image accross y axis
        glVertex2i( x+centerX,-y+centerY);   //a
        glVertex2i(-y+centerX,x+centerY); 
    }
    glEnd();    

    //reflection across x and y axis 
            //
}



void display(void)
{
    // glClear(GL_ARB_color_buffer_float);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

    //currently for l to right
    circleDDA(100, 200, 20);
    // line_DDA(0,500, 300, 300); //up slope
    // line_DDA(0,500, 500, 300); //up slope    
    // line_DDA(300,300, 500, 300); //up slope    


    // line_DDA(0,33.0, 800, 500);// down slope 
    // line_DDA(0,400, 800, 400); //hori 
    // line_DDA(400,200, 400, 400); //verti
    // line_DDA(800,400,0,200);
 
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Line DDA");
    glutDisplayFunc(display);
    glutMainLoop();

    // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);


    return 0;
}




// glLoadIdentity();

