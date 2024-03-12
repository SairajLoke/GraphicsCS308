#include<GL/glut.h>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void point(float x,float y){
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    
}

// GLfloat carX = 200.0;
// GLfloat carY = 200.0;
// GLfloat length = 100.0;

void bresenham(float xStart, float yStart,float xEnd ,float yEnd){

    // if (xStart > xEnd || yStart > yEnd){
    //     float temp = xEnd;
    //     float xEnd = xStart;
    //     float xStart = temp;

    //     temp = yEnd;
    //     float yEnd = yStart;
    //     float yStart = temp;

    // }
    float slope = (yEnd - yStart) / (xEnd - xStart);
    float deltaY = yEnd - yStart;
    float deltaX = xEnd - xStart;
    int steps;

    // First case m < 1
    if (slope < 1.0) {
        steps = xEnd - xStart;
        float x = xStart;
        float y = yStart;
        float decisionParam = 2 * deltaY - deltaX;

        point(x, y);

        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaY;
                x += 1;
            } else {
                decisionParam += 2 * deltaY - 2 * deltaX;
                x += 1;
                y += 1;
            }

            point(x, y);
        }
    }
    // Second case m = 1
    if (slope == 1.0) {
        float x = xStart, y = yStart;

        point(x, y);

        steps = xEnd - xStart;
        for (int add = 1; add <= steps; add++) {
            x += 1;
            y += 1;

            point(x, y);
        }
    }
    // Third case m > 1
    if (slope > 1) {
        float x = xStart, y = yStart;
        point(x, y);

        steps = yEnd - yStart;
        float decisionParam = 2 * deltaX - deltaY;
        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaX;
                y += 1;
            } else {
                decisionParam += 2 * deltaX - 2 * deltaY;
                x += 1;
                y += 1;
            }

            point(x, y);
        }
    }

    


}
// void draw(void){

// glClear(GL_COLOR_BUFFER_BIT);//set bit plane area of the window
//     bresenham(100,150,200, 150);
//     bresenham(200,150,200, 200);
//     bresenham(200,200,100, 200);
//     bresenham(100,200,100, 150);
// glFlush();

// }



// struct Point {
// 	GLfloat x;
// 	GLfloat y;
// };

// struct Color {
// 	GLfloat r;
// 	GLfloat g;
// 	GLfloat b;
// };


// // void init(Color BorderColor) {
// // 	// glClearColor(1.0, 1.0, 1.0, 0.0);  
// // 	// glColor3f(BorderColor.r, BorderColor.g, BorderColor.b);
// // 	// glPointSize(1.0);
// // 	glMatrixMode(GL_PROJECTION);
// // 	glLoadIdentity();
// // 	gluOrtho2D(0, 1000, 0, 1000);
// // }

// Color getPixelColor(GLint x, GLint y) {
// 	Color color;
// 	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
// 	return color;
// }

// void setPixelColor(GLint x, GLint y, Color color) {
// 	glColor3f(color.r, color.g, color.b);
// 	glBegin(GL_POINTS);
// 		glVertex2i(x, y);
// 	glEnd();
// 	glFlush();
// }

// void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
// 	Color color;
// 	color = getPixelColor(x, y);
//     if(color.r == 1.0){cout<<"reached red"<<endl;}

// 	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
// 	{
// 		setPixelColor(x, y, newColor);
// 		floodFill(x+1, y, oldColor, newColor);
// 		floodFill(x, y+1, oldColor, newColor);
// 		floodFill(x-1, y, oldColor, newColor);
// 		floodFill(x, y-1, oldColor, newColor);

//         floodFill(x+1, y+1, oldColor, newColor);
// 		floodFill(x-1, y-1, oldColor, newColor);
// 		floodFill(x-1, y+1, oldColor, newColor);
// 		floodFill(x+1, y-1, oldColor, newColor);
// 	}
// 	return;
// }

// void onMouseClick(int button, int state, int x, int y)
// {
// 	Color newColor = {0.0f, 0.0f, 1.0f};
// 	Color oldColor = {0.0f, 0.0f, 0.0f};

//     std::cout<<x<<" "<<y<<std::endl;
// 	floodFill(carX + 10, carY + 50, oldColor, newColor);
// }


// // int main(int argc, char** argv)
// // {
// // 	glutInit(&argc, argv);
// // 	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
// // 	glutInitWindowSize(500, 500);
// // 	glutInitWindowPosition(100, 100);
// // 	glutCreateWindow("Open GL");
// //     Color BorderColor = {1.0,1.0,1.0};
// // 	init(BorderColor);
// // }



void circleBresh(float centerx,float centery, float radius){
 

    glColor3f(1.0,0.0,0.0);
    // glBegin(GL_POLYGON);
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
    while( x <= y){//consider center 0 while calcula


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


// void draw_square(Point a, GLint length) {
// 	Point b = {a.x + 2*length, a.y},
// 		c = {b.x,	b.y+length},
// 		d = {c.x-2*length, c.y};

// 	bresenham(a.x,a.y , b.x, b.y);
// 	bresenham(b.x,b.y,c.x, c.y);
// 	bresenham(d.x,d.y,c.x, c.y );
// 	bresenham(a.x,a.y,d.x,d.y);	

//     cout<<a.x<<" "<<a.y<<endl;
//     cout<<b.x<<" "<<b.y<<endl;
//     cout<<c.x<<" "<<c.y<<endl;
//     cout<<d.x<<" "<<d.y<<endl;
// }

// void display(void) {
// 	Point pt = {carX, carY};

// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glBegin(GL_POINTS);
//         draw_square(pt, length);
//         // circleBresh(320,320,100);
//         // circleBresh(200,200,100);
//         // draw_trape();
// 	glEnd();
// 	glFlush();
// }

// void init(Color BorderColor) {
// 	glClearColor(1.0, 1.0, 1.0, 0.0);  
// 	glColor3f(BorderColor.r, BorderColor.g, BorderColor.b);
// 	// glPointSize(1.0);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluOrtho2D(0, 500, 0, 500);
// }

// int main(int argc , char** argv){

// 	// glutCreateWindow("Open GL");
//     Color BorderColor = {1.0,1.0,1.0};
// 	// init(BorderColor);
// 	// glutDisplayFunc(display);
// 	// glutMouseFunc(onMouseClick);
// 	// glutMainLoop();
// 	// return 0;


//     glutInit(&argc,argv); //to initialize the glut library
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the initial dislpay node
//     glutInitWindowSize(1000,1000);
//     glutInitWindowPosition(500,500); //set initial window size and position respectively
//     glutCreateWindow("Bresenhem");
//     gluOrtho2D(0,500, 0,500);

//     init(BorderColor);
    
//     glutDisplayFunc(display); //sets the callback for current window
//     glutMouseFunc(onMouseClick);
//     glutMainLoop(); //enters the GLUT event processing loop
    
//     return 0 ;
// }

struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
}

void init(Color BorderColor) {
	// glClearColor(1.0, 1.0, 1.0, 0.0);  
	glColor3f(BorderColor.r, BorderColor.g, BorderColor.b);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {0.0f, 0.0f, 1.0f};
	Color oldColor = {0.0f, 0.0f, 0.0f};

    std::cout<<x<<" "<<y<<std::endl;
	floodFill(x, y, oldColor, newColor);
}

void display(void) {
	Point p1 = {100, 100}, // bottom-right
		p2 = {350, 100}, // bottom-left
		p3 = {350, 200}, // top-right
		p4 = {100, 200}; // top-left
        
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
        circleBresh(100,100,100);
        circleBresh(350,100,100);
        // draw_trape();
	glEnd();
    float yshift = 150;

	glBegin(GL_POINTS);
        bresenham(p1.x, p1.y+yshift, p2.x, p2.y);
        bresenham(p2.x, p2.y+yshift, p3.x, p3.y);
        bresenham(p4.x, p4.y, p3.x, p3.y );
        bresenham( p1.x, p1.y, p4.x, p4.y);
	// glEnd();
    // glBegin(GL_POINTS);
        bresenham(p1.x +50 , p1.y+300, p1.x + 300, p2.y+300);
        bresenham(p1.x +25 , p1.y+200 , p1.x + 350, p2.y+200);
        // bresenham(p1.x +50, p1.y+300 , p1.x + 25, p2.y+200);

	glEnd();

    
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Open GL");
    Color BorderColor = {1.0,1.0,1.0};
	init(BorderColor);
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}