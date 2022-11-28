#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

GLsizei wh = 550,               // размеры окна
        ww = 550; 

int points = 100000;

void myinit()
{
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );                  // двойная буферизация
    glutInitWindowSize( ww, wh );                                   // размер окна
    glutInitWindowPosition( 0, -150 );                              // расположение окна
    glutCreateWindow( "Fractal Barnsley Fern" );                    

    glClearColor( 0.0, 0.0, 0.0, 0.0 );                             // фон
    glColor3ub( 0, 255, 255 );                                      // цвет фрактала

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D( 0.0, 500.0, 0.0, 500.0 );
    glMatrixMode(GL_MODELVIEW);
}