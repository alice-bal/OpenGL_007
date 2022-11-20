void star( int scaled )
{
    static GLfloat angle = 0;
	++angle;
	if ( angle == 360 ) angle = 0;

	glRotated(angle, 0, 0, 1);                          // вращение
    
    glScaled( 0.001 * scaled, 0.001 * scaled, 0.0);     // масштаб

    glColor3ub( 235, 208, 75 );                         // желтый цвет 

    glBegin(GL_TRIANGLES);                              // звезда: три примитива-треугольника
		
		glVertex2s( -50, -68 );
		glVertex2s(   0,  80 );
        glVertex2s(  30, -10 );

        glVertex2s( -80,  26 );
        glVertex2s(  80,  26 );
        glVertex2s(   0, -32 );

        glVertex2s( -30, -10 );
        glVertex2s(   0,  80 );
        glVertex2s(  50, -68 );

	glEnd();

    glLoadIdentity(); 
}