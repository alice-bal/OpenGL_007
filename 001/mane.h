void mane()
{
    glColor3ub(242, 124, 124);
    
    // 1
    glTranslated(0.0, 0.37, 0.0); 
    glBegin(GL_POLYGON);          
        for (int i = 0; i < n; ++i){
            glVertex2f(0.06 * cos(2 * M_PI / n * i), 0.03 * sin(2 * M_PI / n * i));
            glColor3ub(235, 194, 113);
        }
    glEnd();

    // 2
    glTranslated(-0.03, -0.01, 0.0);        
    glScaled(0.03, 0.04, 0.0);
    glBegin(GL_POLYGON);                 
        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(235, 218, 113);
        }
    glEnd();
    glLoadIdentity();

    // 3
    glTranslated(0.06, 0.35, 0.0);        
    glScaled(0.03, 0.035 , 0.0);
    glBegin(GL_POLYGON);                 

        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(113, 235, 119);
        }
    glEnd();
    glLoadIdentity();
    // 4
    glTranslated(0.08, 0.33, 0.0);         
    glScaled(0.03, 0.02 , 0.0);
    glRotated(15, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);                 

        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(113, 161, 235);
        }
    glEnd();
    glLoadIdentity();
    // 5
    glTranslated(0.1, 0.29, 0.0);        
    glScaled(0.03, 0.04 , 0.0);
    glRotated(30, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);                 

        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(157, 113, 235);
        }
    glEnd();
    glLoadIdentity();
    // 6
    glTranslated(-0.06, 0.35, 0.0);       
    glScaled(0.03, 0.04 , 0.0);
    glRotated(30, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);                 

        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(240, 14, 202);
        }
    glEnd();
    glLoadIdentity();
    // 7
    glTranslated(-0.08, 0.33, 0.0);      
    glScaled(0.03, 0.02 , 0.0);
    glRotated(15, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);                 

        for (int i = 0; i < n; ++i){
            glVertex2f(1.0 * cos(2 * M_PI / n * i), 1.0 * sin(2 * M_PI / n * i));
            glColor3ub(118, 19, 145);
        }
    glEnd();
    glLoadIdentity();
}