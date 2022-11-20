#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <math.h>

using namespace std;

void init(void)
{
	glClearColor(49.0 / 255.0, 21.0 / 255.0, 43.0 / 255.0, 0.0); //RGBA
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
