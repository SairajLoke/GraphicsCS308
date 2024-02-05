#include<GL/glut.h>
#include<math.h>
#include<iostream>


void circle(float centerx,float centery, float radius){
    
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    GLfloat angle , x ,y ;
    GLfloat centerX = centerx;
    GLfloat centerY = centery;

    for(angle = 0.0f ; angle <= (2.0f * M_PI) ; angle += 0.01f){
        x = radius*sin(angle) + centerX;
        y = radius*cos(angle) + centerY;
        glVertex2f(x,y);
    }
    glEnd();    


            //
}

void BicycleFrame(float Frontx , float Fronty , float Rearx, float Reary , float Handlex , float Handley, float seatsz){
     //set bit plane area of the window
// glColor3f(1.0, 0.0, 0.0);
// glBegin(GL_POINTS);
//     glVertex2f(100,100);
//     glVertex2f(250,250);
//     // glVertex2f(250,100);
// glEnd();

glColor3f(0.0, 1.0 , 0.0);
//glLineWidth(10.0);
glBegin(GL_LINES);   // straight
    glVertex2f(Handlex,Handley);
    glVertex2f(Frontx,Fronty);
glEnd();


glBegin(GL_LINES);  //lines
    glVertex2f(Handlex,Handley);
    glVertex2f(Handlex + 20,Handley - 20);

    glVertex2f(Handlex,Handley);
    glVertex2f(Handlex - 20,Handley + 20);

    glVertex2f(Handlex - 20,Handley + 20);
    glVertex2f(Handlex ,Handley + 40);

    glVertex2f(Handlex + 20,Handley - 20);
    glVertex2f(Handlex +40,Handley);
glEnd();

glBegin(GL_POLYGON);
        // glColor3f(1, 0, 0);
        glColor4d(0, 0.5, 0.5,0.8); 
        glVertex2f(Handlex, Handley );  
        glVertex2f((Frontx + Rearx) / 2,Fronty); 
        glVertex2f((Frontx + Rearx) / 2,Handley  ); 
glEnd();

glBegin(GL_POLYGON);
        // glColor3f(1, 0, 0);
        glColor4d(0.4, 0.5, 0.6,0.8); 
        glVertex3f(Rearx, Reary, 0.0);  
        glVertex3f((Frontx + Rearx) / 2,Fronty, 0.0); 
        glVertex3f((Frontx + Rearx) / 2,Handley , 0.0); 
glEnd();

glBegin(GL_POLYGON);   //seat 
        // glColor3f(1, 0, 0);
        glColor3f(1.0, 0.5, 0.5); 
        glVertex2f((Frontx + Rearx) / 2 + seatsz,Handley +seatsz ); 
        glVertex2f((Frontx + Rearx) / 2 + seatsz,Handley ); 
        glVertex2f((Frontx + Rearx) / 2 - seatsz,Handley ); 
        glVertex2f((Frontx + Rearx) / 2 - seatsz,Handley + seatsz); 
glEnd();

// glBegin(GL_TRIANGLES);
//     glVertex2f((Frontx + Fronty) / 2,Reary);
//     glVertex2f((Frontx + Fronty) / 2,Handley);
//     glVertex2f((Frontx + Fronty) / 2,Fronty);
// glEnd();

}

void draw(void){

    circle(100.0, 100.0, 100.0);
    circle(400.0, 100.0, 100.0);
    BicycleFrame(400, 100, 100, 100, 400, 300, 30);

    glFlush();
}



int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // no frame change so glut single works..
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500);

    glutCreateWindow("circle");
    gluOrtho2D(0,500, 0,500);  // ? some coordinate axis

    glutDisplayFunc(draw);

    glutMainLoop();
    return 0 ;
}




void drawXmassTree(void){

float treeRootx = 250;
float treeRooty = 400;

glClear(GL_COLOR_BUFFER_BIT);//set bit plane area of the window
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POINTS);
    glVertex2f(100,100);
    glVertex2f(250,250);
    // glVertex2f(250,100);
glEnd();

glColor3f(0.0, 1.0 , 0.0);
//glLineWidth(10.0);
glBegin(GL_LINES);
    glVertex2f(treeRootx,treeRooty-100);
    glVertex2f(treeRootx + 100,treeRooty-200);

    glVertex2f(treeRootx,treeRooty-200);
    glVertex2f(treeRootx + 100,treeRooty-300);

glEnd();
glFlush();

}
