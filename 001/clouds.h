void clouds_left()
{
    // ЛЕВАЯ ЧАСТЬ
    glColor3ub(255, 255, 255);   

    glTranslated(-0.67, -0.5, 0.0);      // сдвиг: x, y, z 
    glBegin(GL_POLYGON);                 // эллипс

        for (int i = 0; i < n; ++i)
            glVertex2f(0.1 * cos(2 * M_PI / n * i), 0.2 * sin(2 * M_PI / n * i));

    glEnd();
    
    glTranslated(0.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);

        for (int i = 0; i < n; ++i)
            glVertex2f(0.3 * cos(2 * M_PI / n * i), 0.1 * sin(2 * M_PI / n * i));

    glEnd();
   
    glTranslated(-0.1, 0.0, 0.0); 
    glBegin(GL_POLYGON); 

        for (int i = 0; i < n; ++i)
            glVertex2f(0.12 * cos(2 * M_PI / n * i), 0.13 * sin(2 * M_PI / n * i));

    glEnd();

    glTranslated(0.2, 0.0, 0.0); 
    glBegin(GL_POLYGON);  

        for (int i = 0; i < n; ++i)
            glVertex2f(0.15 * cos(2 * M_PI / n * i), 0.16 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();
}

void clouds_right()
{
    // ПРАВАЯ ЧАСТЬ
    glColor3ub(255, 255, 255);   

    glTranslated(0.65, -0.5, 0.0);        // сдвиг: x, y, z 
    glBegin(GL_POLYGON);                  // эллипс

        for (int i = 0; i < n; ++i)
            glVertex2f(0.15 * cos(2 * M_PI / n * i), 0.2 * sin(2 * M_PI / n * i));

    glEnd();
    
    glTranslated(0.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);            

        for (int i = 0; i < n; ++i)
            glVertex2f(0.3 * cos(2 * M_PI / n * i), 0.1 * sin(2 * M_PI / n * i));

    glEnd();
   
    glTranslated(-0.1, 0.0, 0.0); 
    glBegin(GL_POLYGON);        

        for (int i = 0; i < n; ++i)
            glVertex2f(0.11 * cos(2 * M_PI / n * i), 0.12 * sin(2 * M_PI / n * i));

    glEnd();

    glTranslated(0.2, 0.0, 0.0);    
    glBegin(GL_POLYGON);            

        for (int i = 0; i < n; ++i)
            glVertex2f(0.17 * cos(2 * M_PI / n * i), 0.12 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity(); 
}