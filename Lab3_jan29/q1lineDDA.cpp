#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;


/*
Sairaj R. Loke 210001035
CS352 Lab3 Q1 DDA for line drawing

Note:
*/



void line_DDA(float x0 , float y0, float xn, float yn ){
    glColor3f(0.0f, 1.0f, 1.0f); // green color

    float delx = xn-x0;
    float dely = yn-y0; //assume ints 
    int num_steps = max(abs(delx),abs(dely) );
    cout<<"Num steps: "<<num_steps<<endl;
    float increx = 0;
    float increy = 0;
    float xtemp = x0 ;
    float ytemp = y0 ;
    float x = x0 ;
    float y = y0 ;

    if( abs(dely)> abs(delx) ){//m > 1
        if (dely !=  0){
            increx = delx/dely;
            increy = 1;
        }
    } 
    else if (abs(dely) == abs(delx)){
        increx = 1;
        increy = 1;
    }
    else if(abs(dely)< abs(delx)){
        if (delx !=  0){
            increx = 1;
            increy = dely/delx;
        }
    }
    if(delx == 0){ increx = 0; increy =1; }
    if(dely == 0){ increy = 0; increx =1; }

    glBegin(GL_POINTS);
        glColor3f(0,1,0);
        for(int i = 0 ; i< num_steps ; ++i)
        {            
            xtemp += increx;
            ytemp += increy;
            x = ceil(xtemp);
            y = ceil(ytemp);
            cout<<x<<" "<<y<<"-----------------------"<<xtemp<<" "<<ytemp<<endl;
            glVertex2i(x,y);
        }
    glEnd();


}
void display(void)
{
    // glClear(GL_ARB_color_buffer_float);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

    //currently for l to right
    line_DDA(0,0, 100, 100); //up slope
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
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Sairaj Line DDA");
    glutDisplayFunc(display);
    glutMainLoop();

    // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);


    return 0;
}

