#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

GLfloat vertex[][3] = {{0,0}, {0, 10},{10, 0}};
GLfloat PI_ = 3.14159 ;
int n = 3; // Number of vertex in the polygon

void drawPolygon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2fv(vertex[i]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Red color for the polygon
    drawPolygon();
    glFlush();
}

void translate(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] += dx;
        vertex[i][1] += dy;
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }
    glutPostRedisplay();
}

void rotate(float angle) {
    float theta = angle * (PI_ / 180.0);
    float tempX, tempY;
    for (int i = 0; i < n; i++) {
        tempX = vertex[i][0];
        tempY = vertex[i][1];
        vertex[i][0] = tempX * cos(theta) - tempY * sin(theta);
        vertex[i][1] = tempX * sin(theta) + tempY * cos(theta);
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }
    glutPostRedisplay();  //https://www.opengl.org/resources/libraries/glut/spec3/node20.html  ,. 
    // The next iteration through glutMainLoop, the window's display callback will be called to redisplay the window's normal plane. 
}

void scale(float sx, float sy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] *= sx;
        vertex[i][1] *= sy;
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }
    glutPostRedisplay();
}

void shear(float shx, float shy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] += shx * vertex[i][1];
        vertex[i][1] += shy * vertex[i][0];
        cout<<vertex[i][0]<<" "<<vertex[i][1]<<endl;
    }
    glutPostRedisplay();
}

void reflect(char dir) {
    if (dir == 'y'){
        for (int i = 0; i < n; i++)
        vertex[i][0] = -vertex[i][0];// y axis
    }
    else if (dir == 'x'){
        for (int i = 0; i < n; i++)
        vertex[i][1] = -vertex[i][1];// x axis
    }
    
        
    glutPostRedisplay();
}

void menu(int choice) {
    switch (choice) {
        case 1:
            translate(20, 20);
            break;
        case 2:
            rotate(120);
            break;
        case 3:
            scale(1.5, 1.5);
            break;
        case 4:
            shear(0.5, 0);
            break;
        case 5:
            reflect('x');
            break;
        case 6:
            drawPolygon();
            break;
        case 7:
            exit(0);
            break;

        
    }
}


void kf(unsigned char key,int x,int y){
    cout<<key<<endl;

    switch (key) {
        
        case 'y' :
            cout<<"reflect along x"<<endl;
            reflect('y');
            break;
        case 'x' :
            cout<<"reflect along x"<<endl;
            reflect('x');
            break;

        case 'r':
            rotate(10);
            break;
        case 's':
            scale(1.5, 1.5);
            break;
        case 'h':
            shear(0.5, 0);
            break;
        case 't':
            translate(2, 2);
            break;
        case 6:
            drawPolygon();
            break;
        case 7:
            exit(0);
            break;

        
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutCreateWindow("2D Transformations");
    gluOrtho2D(-50, 50, -50, 50);
    glutDisplayFunc(display);

    int submenu = glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Shear", 4);
    glutAddMenuEntry("Reset", 5);
    glutAddMenuEntry("Reflect", 6);
    

    glutCreateMenu(menu);
    glutAddSubMenu("Transformations", submenu);
    glutKeyboardFunc(kf);
    // glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    
    return 0;
}