#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

GLsizei wh = 500,               // initial window size
        ww = 500; 

int points = 100000;


void myinit()
{
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );                  // double buffering
    glutInitWindowSize( ww, wh );                                   // 500 x 500 pixel window
    glutInitWindowPosition( 0, 0 );                                 // place window top left on display
    glutCreateWindow( "Fractal barnsley fern" );                    // window title

      
    glClearColor(0.0, 0.0, 0.0, 0.0);         // background
    glColor3f(0.0,1.0,1.0);                   // cyan

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}