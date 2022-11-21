GLdouble f( GLdouble x )            // функция
{
    return sin(x);
}

GLdouble _f( GLdouble x)            // производная функции 
{
    return cos(x);
}

list <GLfloat> findextr()                   // создаем список экстремумов
{
    for ( GLfloat i = x1; i <= x2; i += 0.00001 )
    {
        if ( fabs( _f(i) ) < 0.00001 )      // производная -> 0 => экстремум
            extr.push_back(i);
    }

    return extr;
}

void coordinates()                  // оформление координатной плоскости
{
    glColor3ub( 237, 231, 140 );      // желтый              

    glBegin( GL_POLYGON );          // заданная область от x1 до x2

        glVertex2f( x1, 3 );
        glVertex2f( x2, 3 );
        glVertex2f( x2,-3 );
        glVertex2f( x1,-3 );

    glEnd();

    glColor3ub( 84, 81, 81 );             // серый
    glLineWidth(1);

    glBegin( GL_LINES );                // координатные оси от _x1 до _x2

        glVertex2f(_x1, 0);                 // ось x
        glVertex2f(_x2, 0);

        glVertex2f(0,  3 );                 // ось y
        glVertex2f(0, -3 );

        for ( int i = _x1; i < _x2; i++ )   // черточки по x
        {
            glVertex2f( i, 0.1 );
            glVertex2f( i,-0.1 );
        }

        for ( int i = -2; i < 3; i++ )    // черточки по y
        {
            glVertex2f( 0.1, i );
            glVertex2f(-0.1, i );
        }

    glEnd();
}