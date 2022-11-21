#include "init.h"
#include "f.h"

void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT);

    coordinates();

    // линия производной -------------------------------------------------------

    glColor3ub( 0, 225, 0 );            // зеленый
    glLineWidth( 2 );

    glBegin(GL_LINE_STRIP);             // производная функции

        for ( GLfloat i = _x1; i <= _x2; i += 0.1 )
            glVertex2f( i, _f(i) );

    glEnd();

    // функция -----------------------------------------------------------------

    glLineWidth( 3 );

    // if (_f(_x1) <= 0)                       
    //     glColor3ub( 122, 139, 250 );
    //     else 
    //         glColor3ub( 250, 122, 139 );    

    glBegin(GL_LINE_STRIP);                       // сама линия
        for (GLfloat i = _x1; i <= _x2; i += 0.01 )
        {
            if ( _f(i) < 0 )                      // функция убывает - синий
                glColor3ub( 122, 139, 250 );
            else if ( _f(i) > 0 )                 // возрастает - красный
                glColor3ub( 250, 122, 139 );

            glVertex2f( i, f(i) );
        }
    glEnd();

    // экстремумы ---------------------------------------------------------------

    glPointSize( 4 );                   // размер точек  
    glEnable(GL_POINT_SMOOTH);          // сглаживание

    glBegin(GL_POINTS);

        glColor3ub( 0, 0, 0 );

        for ( GLfloat i : extr )        // локальные экстремумы (в заданной области)
            glVertex2f( i, f(i));

        glColor3ub( 255, 0, 0 );

        glVertex2f(min_x, f(min_x));    // функция от минимального x 
        glVertex2f(max_x, f(max_x));    // функция от максимального x

    glEnd();

    glFlush();
}

int main( int argc, char** argv )
{
    // начальные данные ---------------------------------------------------------
    
    while ( x1 == -1 && x2 == -1 )          // пока пользователь не введет x1, x2
    {
        cout << "Границы заданного отрезка:" << endl;
        // cin >> x1 >> x2;
        x1 = -10; x2 = 20;

        if ( abs(x2 - x1) <= 2 )
        {
            cout << "Слишком короткий отрезок" << endl << endl;
            x1 = -1; x2 = -1;
        }
        else
            if ( x2 < x1 ) swap( x1, x2 );
    }

    _x1 = x1 - 10;
    _x2 = x2 + 10;
    min_x = x1; 
    max_x = x1;

    // поиск экстремумов --------------------------------------------------------

    extr = findextr();
    cout << endl << extr.size() << " локальных экстремумов: " << endl << endl;

    for ( GLfloat i : extr )
        cout << "\t" << setprecision(3) << setw(5) << i 
             << "\t" << setprecision(3) << setw(5) << f(i) 
             << endl;

    // поиск max_x и min_x ------------------------------------------------------

    for ( GLfloat i = x1; i <= x2; i += 0.0001 )       // в заданных границах
    {
        if ( f(i) > f(max_x) ) max_x = i;               // максимальная точка функции
        if ( f(i) < f(min_x) ) min_x = i;               // минимальная 
    }

    cout << endl;

    cout << "min:\t" << setprecision(3) << setw(5) << min_x 
             << "\t" << setprecision(3) << setw(5) << f(min_x) << endl;
    cout << "max:\t" << setprecision(3) << setw(5) << max_x 
             << "\t" << setprecision(3) << setw(5) << f(max_x) << endl;
        
    glutInit( &argc, argv );
    init();
    glutDisplayFunc( display );

    glutMainLoop();

    return 0;
}