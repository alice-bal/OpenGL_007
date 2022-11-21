#include "GL/glut.h"
#include <math.h>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

GLfloat  x1 = -1,       // границы отрезка (задает пользователь)
         x2 = -1,
        _x1, _x2,       // границы графика (границы экрана)
           min_x,       // минимальная и максимальная точка функции (x) 
           max_x;       

list <GLfloat> extr;    // список локальных экстремумов

void init(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize( 1000, 500 );
    glutInitWindowPosition( 200, 100 );
    glutCreateWindow( "Func" );
    
    glClearColor( 1, 1, 1, 0 );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho( _x1, _x2, -3, 3, -1, 1 );      // определяем координатную систему конечного изображения
}