#include "init.h"
#include "rainbow.h"
#include "clouds.h"
#include "head.h"
#include "mane.h"
#include "body.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   // очищение буфера цвета

    rainbow();

    clouds_left();
    clouds_right();
    
    body();
    legs();

    head();
    face();

    mane();
    // center();
    
    glFlush();      // команды принимаются обработчиком отрисовки и сразу выполняются
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // инициализация glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // статическое изображение в режиме rgb

    glutInitWindowSize(700, 700);                   // формат окна
    glutInitWindowPosition(500, 100);               // расположение окна
    glutCreateWindow("Time to be unicorn!!");       // название окна

    init();
    glutDisplayFunc(display);

    glutMainLoop();                                 // ждем закрытия окна

    return 0;
}
