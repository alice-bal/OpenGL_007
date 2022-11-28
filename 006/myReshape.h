
// изменение формы при перемещении или изменении размеров окна

void myReshape(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( 0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport( 0, 0, w, h );               // отсечение графического вывода по новым размерам окна
    glClear(GL_COLOR_BUFFER_BIT);           // очищение
    glFlush();
    
    ww = w;                                 // указываем новые размеры
    wh = h;
}