#include "init.h"
#include "myReshape.h"

void barnsleyFern()
{
	// typedef существующий_тип новое_имя;
	typedef GLfloat point2[2];

	point2 p = {0.0, 50.0}; 
	point2 newPoint;

	double probability[3] = { 85, 92, 99 }; 			// вектор вероятностей

	glClear(GL_COLOR_BUFFER_BIT);

	for ( int i = 0; i < points; i++ ) 					// рисуем
	{
		GLfloat prevx = p[0],
				randnum = rand() % 100 + 1;
		if ( randnum < probability[0] )
		{
			p[0] = p[0] * 0.85 + 0.04 * p[1];
			p[1] = prevx * (-0.04) + 0.85 * p[1] + 1.6;
		}
		else if ( randnum < probability[1] )
		{
			p[0] = 0.2 * p[0] - 0.26 * p[1];
			p[1] = 0.23 * prevx + 0.22 * p[1] + 1.6;
		}
		else if ( randnum < probability[2] )
		{
			p[0] = -0.15 * p[0] + 0.28 * p[1];
			p[1] = 0.26 * prevx + 0.24 * p[1] + 0.44;
		}
		else
		{
			p[0] = 0.0;
			p[1] = 0.16 * p[1];
		}

		newPoint[0] = p[0] * 50 + 250;
		newPoint[1] = p[1] * 50;
		
		if ( i > 100 )									// рисуем точку
		{
			glBegin(GL_POINTS);
			glVertex2fv(newPoint);
			glEnd();
		}
	}

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	myinit();

	glutDisplayFunc(barnsleyFern);

	glutReshapeFunc(myReshape);
	glutMainLoop();

	return 0;
}