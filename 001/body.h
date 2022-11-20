void body()
{
    glColor3ub(255, 255, 255);          // цвет объекта 
    glTranslated(0.0, 0.0, 0.0);        // сдвиг: x, y, z 
    glScaled(1.7, 1.7, 0.0);            // масштабирование
    glBegin(GL_POLYGON);                // эллипс

        for (int i = 0; i < n; ++i)
            // 0.1 - растяжение по оси OX
            // 0.12- растяжение по оси OY
            glVertex2f(0.1 * cos(2 * M_PI / n * i), 0.12 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity(); 
}

void legs()
{
    glColor3ub(255, 255, 255);          // цвет объекта 
    glTranslated(0.0, 0.0, 0.0);
    
    // ЛЕВАЯ НОГА
    glBegin(GL_POLYGON);
        glVertex2f(0.0, -0.13);
        glVertex2f(-0.4, -0.13);
        glVertex2f(-0.4, -0.21);
        glVertex2f(0.0, -0.21);
    glEnd(); 

    // ПРАВАЯ НОГА
    glBegin(GL_POLYGON);
        glVertex2f(0.0, -0.13);
        glVertex2f(0.0, -0.21);
        glVertex2f(0.4, -0.21);
        glVertex2f(0.4, -0.13);
    glEnd();

    // ЛЕВАЯ ЛАПА
    glBegin(GL_POLYGON);
        glVertex2f(-0.02, 0.05);
        glVertex2f(-0.07, 0.05);
        glVertex2f(-0.07, -0.25);
        glVertex2f(-0.02, -0.25);
    glEnd();

    // ПРАВАЯ ЛАПА
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2f(0.07, 0.05);
        glVertex2f(0.02, 0.05);
        glVertex2f(0.02, -0.25);
        glVertex2f(0.07, -0.25);
    glEnd();

    glColor3ub(0, 0, 0);

    // КОНТУР лап: левый, правый
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.07, 0.05);
        glVertex2f(-0.07, -0.25);
        glVertex2f(-0.02, -0.25);
        glVertex2f(-0.02, 0.02);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(0.02, 0.02);
        glVertex2f(0.02, -0.25);
        glVertex2f(0.07, -0.25);
        glVertex2f(0.07, 0.05);
    glEnd();

    // КОПЫТЦА ног: левое, правое
    glBegin(GL_POLYGON);
        glVertex2f(-0.4, -0.13);
        glVertex2f(-0.45, -0.13);
        glVertex2f(-0.45, -0.21);
        glVertex2f(-0.4, -0.21);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.45, -0.13);
        glVertex2f(0.4, -0.13);
        glVertex2f(0.4, -0.21);
        glVertex2f(0.45, -0.21);
    glEnd(); 

    // КОПЫТЦА лап: левое, правое
    glBegin(GL_POLYGON);
        glVertex2f(-0.02, -0.25);
        glVertex2f(-0.07, -0.25);
        glVertex2f(-0.07, -0.3);
        glVertex2f(-0.02, -0.3);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.07, -0.25);
        glVertex2f(0.02, -0.25);
        glVertex2f(0.02, -0.3);
        glVertex2f(0.07, -0.3);
    glEnd();

}