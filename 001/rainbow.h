void rainbow()
{
    // КРАСНЫЙ
    glColor3ub(242, 124, 124); 
    glTranslated(0.0, -1.2, 0.0);        // сдвиг: x, y, z 
    glBegin(GL_POLYGON);                 // эллипс

        for (int i = 0; i < n; ++i)
            // 0.1 - растяжение по оси OX
            // 0.12- растяжение по оси OY
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();                    // сброс координат

    // ОРАНЖЕВЫЙ
    glColor3ub(235, 194, 113); 
    glTranslated(0.0, -1.25, 0.0); 
    glBegin(GL_POLYGON);         

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();

    // ЖЕЛТЫЙ
    glColor3ub(235, 218, 113);
    glTranslated(0.0, -1.3, 0.0);
    glBegin(GL_POLYGON);

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();

    // ЗЕЛЕНЫЙ
    glColor3ub(113, 235, 119);
    glTranslated(0.0, -1.35, 0.0);
    glBegin(GL_POLYGON);

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();

    // ГОЛУБОЙ
    glColor3ub(113, 161, 235);
    glTranslated(0.0, -1.4, 0.0);  
    glBegin(GL_POLYGON);

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();

    // ФИОЛЕТОВЫЙ
    glColor3ub(157, 113, 235);
    glTranslated(0.0, -1.45, 0.0);    
    glBegin(GL_POLYGON);              

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity();

    // ВЕРХНИЙ СЛОЙ
    glColor3ub(252, 184, 235);
    glTranslated(0.0, -1.5, 0.0);
    glBegin(GL_POLYGON);

        for (int i = 0; i < n; ++i)
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.25 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity(); 
   
}