#include<GL/glut.h>
#include<iostream>
#include<tuple>
using namespace std;


/*
Sairaj R. Loke 210001035
CS352 Lab2 Q1 Event Based polygon control
- events are :
    - particular keyboard key press
    - mouse clicks

Note:
*/



int xpolycentre  = 0 ;
int ypolycentre = 0;
float r = 0.0 ; 
float g = 100.0;
float b= 0.0;



void polygon(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

    glColor3f(r/255,g/255,b/255);
    glBegin(GL_POLYGON);
        glVertex2f(xpolycentre+x1,ypolycentre+ y1);
        glVertex2f(xpolycentre+x2,ypolycentre+ y2);
        glVertex2f(xpolycentre+x3,ypolycentre+ y3);
        glVertex2f(xpolycentre+x4,ypolycentre+ y4);
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
polygon(155, 130, 185, 130, 185, 190, 155, 190);
// triangle(75,200,175,200,125,250,1,0,200.0,0);
// triangle(75,225,175,225,125,275,2,0,200.0,0);
glFlush();




}

void processMouse(int button, int state , int x , int y){

    cout<<"inside on mouse press"<<endl;
    switch(button) {
        case 'q': case 'Q': case 27:
            exit (0);
            break;
        case GLUT_LEFT_BUTTON:
            // ypolycentre += 5;
            r = float(int(r+20)% 255);
            g = float(int(g+15)% 255);
            b = float(int(b+10)% 255);
            cout<<"left click"<<r<<" "<<g<<" "<<b<<endl;
            draw();
            break;

        case GLUT_MIDDLE_BUTTON:
            cout<<"middle button"<<endl;
            break;
        
    }

}


void processSpecialKeys(int key,int x, int y){
    cout<<"inside on keyboard press"<<endl;
    switch(key) {
        case 'q': case 'Q': case 27:
            exit (0);
            break;
        case GLUT_KEY_UP:
            ypolycentre += 5;
            cout<<"up"<<ypolycentre<<endl;
            draw();
            break;

        case GLUT_KEY_DOWN:
            ypolycentre -= 5;
            cout<<"down"<<ypolycentre<<endl;
            draw();
            break;

        case GLUT_KEY_RIGHT:
            xpolycentre += 5;
            cout<<"right"<<xpolycentre<<endl;
            draw();
            break;

        case GLUT_KEY_LEFT:
            xpolycentre -= 5;
            cout<<"left"<<xpolycentre<<endl;
            draw();
            

        // case 'p': case 'P':
        //     paused = 1;
        //     break;
 } 
}


int main(int argc , char** argv){

    glutInit(&argc,argv); //to initialize the glut library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the initial dislpay node
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500); //set initial window size and position respectively

    glutCreateWindow("SAIRAJ's Event Polygon");
    gluOrtho2D(0,500, 0,500);
    glutDisplayFunc(draw); //sets the callback for current window

    // here are the new entries
	// glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(processMouse);
    glutMainLoop(); //enters the GLUT event processing loop
    return 0 ;
}