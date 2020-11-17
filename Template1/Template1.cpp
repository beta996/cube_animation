// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>


double y_cord = 0;
double x_cord = 0;


void MyDisplay() {


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen and Z buffer

    // Reset transformations
    glLoadIdentity();


    // Rotate when user changes x_cord and y_cord
    glRotated(x_cord, 1.0, 0.0, 0.0);
    glRotated(y_cord, 0.0, 1.0, 0.0);

   

    //Yellow side - FRONT
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.78, 0.0);     
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(0.25, 0.25, -0.25);      
    glVertex3f(-0.25, 0.25, -0.25);      
    glVertex3f(-0.25, -0.25, -0.25);      
    glEnd();

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();

    glFlush();

}


void specialKeys(int key, int x, int y) {

    
    if (key == GLUT_KEY_RIGHT)
        y_cord += 4;

    else if (key == GLUT_KEY_LEFT)
        y_cord -= 4;

    else if (key == GLUT_KEY_UP)
        x_cord += 4;

    else if (key == GLUT_KEY_DOWN)
        x_cord -= 4;


    glutPostRedisplay();

}


// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {

    //  Initialize GLUT and process user parameters
    glutInit(&argc, argv);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);

    
    glutCreateWindow("my cube");

    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

   
    return 0;

}