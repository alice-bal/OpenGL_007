#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <math.h>

using namespace std;

const int n = 1000;   // количество вершин полигона

void init(void)
{
    glClearColor(252.0 / 255.0, 184.0 / 255.0, 235.0 / 255.0, 0.0); // RGBA
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}