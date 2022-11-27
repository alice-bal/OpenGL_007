// cd ../ && cd 006 && g++ 006_0.cpp -lGL -lGLU -lGLEW -lglut -o 006_0 && ./006_0

#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

float w = 20, h = 20;

void Draw(float dx, float dy);
void Hilbert(int dep, float dx, float dy);


void init(void) 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
}


float LastX, LastY;  // координаты последнего положения точки

void display(void) 
{
    float start_length;  // длина стороны фрагмента
    int dep;  // глубина

    cout << "depth = ";
    cin >> dep;

    float start_x, start_y, /*координаты старта - левый нижний угол*/
    total_length; // длина всего рисунка на экране 

    if (h < w)
        total_length = (float)(0.9 * h);
    else
        total_length = (float)(0.9 * w);

    start_x = (w - total_length) / 2.0;
    start_y = (h - total_length) / 2.0;
    start_length = (float)(total_length / (pow(2, dep) - 1));

    LastX = (int)start_x;
    LastY = (int)start_y;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    {
        Hilbert(dep, start_length, 0);
    }
    glEnd();

    glFlush();
}


void Draw(float dx, float dy) // рисование линии
{
    glVertex2d(LastX, LastY);
    glVertex2d(LastX + dx, LastY + dy);
    LastX += dx;
    LastY += dy;
}

void Hilbert(int dep, float dx, float dy) // рекурсивная функция
{
    if (dep > 1) Hilbert(dep - 1, dy, dx); // начало "П"
    Draw(dx, dy);  // сторона 1

    if (dep > 1) Hilbert(dep - 1, dx, dy); // первый угол "П"
    Draw(dy, dx);  // сторона 2

    if (dep > 1) Hilbert(dep - 1, dx, dy); // второй угол "П"
    Draw(-dx, -dy);  // сторона 3

    if (dep > 1) Hilbert(dep - 1, -dy, -dx); // конец "П"
}


void processNormalKeys(unsigned char key, int x, int y) 
{
    if (key == 27) exit(0);
}


int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Fractal");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(processNormalKeys);

    glutMainLoop();
    return 0;
}