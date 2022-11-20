void head()
{
    glColor3ub(255, 255, 255);          // цвет объекта 

    // МАЛЫЙ ЭЛЛИПС
    glTranslated(0.0, 0.27, 0.0);       // сдвиг: x, y, z 
    glBegin(GL_POLYGON);                // эллипс

        for (int i = 0; i < n; ++i)
            // 0.1 - растяжение по оси OX
            // 0.12- растяжение по оси OY
            glVertex2f(0.1 * cos(2 * M_PI / n * i), 0.12 * sin(2 * M_PI / n * i));

    glEnd();
    glLoadIdentity(); 

    // УШИ И РОГ
    glBegin(GL_TRIANGLES);

        glVertex2f(-0.12, 0.4);
        glVertex2f(-0.09, 0.3);
        glVertex2f(-0.03, 0.37);

        glVertex2f(0.12, 0.4);
        glVertex2f(0.09, 0.3);
        glVertex2f(0.03, 0.37);

        glColor3ub(240, 14, 202);
        glVertex2f(0.00, 0.6);
        glColor3ub(118, 19, 145);
        glVertex2f(-0.02, 0.39);
        glVertex2f(0.02, 0.39);

    glEnd();
    glLoadIdentity(); 
}

void face()
{
    glColor3ub(0, 0, 0);
    // НОС
    glTranslated(-0.01, 0.22, 0.0);    
    glBegin(GL_POLYGON);          
        for (int i = 0; i < n; ++i)
            glVertex2f(0.005 * cos(2 * M_PI / n * i), 0.01 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity(); 

    glTranslated(0.01, 0.22, 0.0);
    glBegin(GL_POLYGON);              
        for (int i = 0; i < n; ++i)
            glVertex2f(0.005 * cos(2 * M_PI / n * i), 0.01 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity();
    
    // ГЛАЗА
    glColor3ub(0, 0, 0); 

    // левый круг
    glTranslated(-0.032, 0.3, 0.0);    
    glBegin(GL_POLYGON);           
        for (int i = 0; i < n; ++i)
            glVertex2f(0.03 * cos(2 * M_PI / n * i), 0.03 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity(); 

    // правый круг
    glTranslated(0.032, 0.3, 0.0); 
    glBegin(GL_POLYGON);          
        for (int i = 0; i < n; ++i)
            glVertex2f(0.03 * cos(2 * M_PI / n * i), 0.03 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity(); 

    glColor3ub(255, 255, 255); 

    // левый слой
    glTranslated(-0.032, 0.31, 0.0);  
    glBegin(GL_POLYGON);     
        for (int i = 0; i < n; ++i)
            glVertex2f(0.03 * cos(2 * M_PI / n * i), 0.03 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity();
 
    // правый слой
    glTranslated(0.032, 0.31, 0.0); 
    glBegin(GL_POLYGON);       
        for (int i = 0; i < n; ++i)
            glVertex2f(0.03 * cos(2 * M_PI / n * i), 0.03 * sin(2 * M_PI / n * i));
    glEnd();
    glLoadIdentity(); 
}