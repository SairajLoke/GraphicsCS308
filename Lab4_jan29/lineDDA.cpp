#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;


void line_DDA(float x0 , float y0, float xn, float yn ){

    // ifstd::swap(y0, yn);


    float del_x = xn-x0;
    float del_y = yn-y0; //assume ints 

    int num_steps = max(abs(del_x),abs(del_y) );
    cout<<"Num steps: "<<num_steps<<endl;
    float incre_x = 0;
    float incre_y = 0;
    float x_temp = x0 ;
    float y_temp = y0 ;

    float x = x0 ;
    float y = y0 ;
    

    if( abs(del_y)> abs(del_x) ){//m > 1
        if (del_y !=  0){
            incre_x = del_x/del_y;
            incre_y = 1;
        }
    } 
    else if (abs(del_y) == abs(del_x)){
        incre_x = 1;
        incre_y = 1;
    }
    else if(abs(del_y)< abs(del_x)){
        if (del_x !=  0){
            incre_x = 1;
            incre_y = del_y/del_x;
        }
    }
    if(del_x == 0){ incre_x = 0; incre_y =1; }
    if(del_y == 0){ incre_y = 0; incre_x =1; }

    cout<<"Incres"<<incre_x<<" "<<incre_y<<endl;
    glBegin(GL_POINTS);
        glColor3f(0,1,0);
        for(int i = 0 ; i< num_steps ; ++i)
        {            
            x_temp += incre_x;
            y_temp += incre_y;
            x = ceil(x_temp);
            y = ceil(y_temp);
            cout<<x<<" "<<y<<"---"<<x_temp<<" "<<y_temp<<endl;;
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
    line_DDA(0,500, 300, 300); //up slope
    line_DDA(0,500, 500, 300); //up slope    
    line_DDA(300,300, 500, 300); //up slope    


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

