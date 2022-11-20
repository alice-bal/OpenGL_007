#include "star.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		// Очистить буфер цвета
	glPushMatrix(); 					//резервная копия матрицы

	background();
	//
	//-----------------------------------------------------------------------
	//
	// static GLfloat x = 0.7, y = 0.2;  		//координаты для движения
	// static short int state_x = 1, state_y = 1;  //статус - в какую сторону двигать
	// float dx = 0.02, dy = 0.01;
	// float board = 0.75;
	//
	// switch (state_x)
	// {
	// case 1:
	// 	if (x <= board) x += dx;
	// 	else state_x = -1;
	// 	break;
	// case -1:
	// 	if (x >= -board) x -= dx;
	// 	else state_x = 1;
	// 	break;
	// }
	// switch (state_y)
	// {
	// case 1:
	// 	if (y <= board) y += dy;
	// 	else state_y = -1;
	// 	break;
	// case -1:
	// 	if (y >= -board) y -= dy;
	// 	else state_y = 1;
	// 	break;
	// }
	//
   
	C = star( 0.05, 0.08, 0.1, 0.1, 1, 1, 3 );
	glTranslated( C.x, C.y, 0 );
	// cout << C.x << " " << C.y << endl;

	//-----------------------------------------------------------------------

	// C = star( -0.3, 0.8, 0.02, 0.02, -1, -1, 2);
	// glTranslated( C.x, C.y, 0 );

	//-----------------------------------------------------------------------

	// C = star( 0.7, 0.1, 0.02, 0.02, 1, -1, 4);
	// glTranslated( C.x, C.y, 0 );

	//-----------------------------------------------------------------------

	glPopMatrix(); //восстановление копии
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0); //вызывать функцию timer через 20 миллисекунд
}

int main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //два буфера для анимации

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("hello, animation");

	init();
    // display();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);  

	glutMainLoop();

	return 0;
}