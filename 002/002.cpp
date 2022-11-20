#include "init.h"
#include "background.h"
#include "star.h"

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);		// очистка буфера цвета
	glPushMatrix(); 					// резервная копия матрицы

	background();						// отрисовка фона

	float board = 0.75;						// границы для звезд

	static GLfloat x_1 =  0.5,				// начало движения
				   y_1 = -0.4;  				 
	static int state_x_1 =-1,				// направление движения 
			   state_y_1 = 1;
	static float dx_1 = 0.02,				// прирост движения
				 dy_1 = 0.01;
	
	switch ( state_x_1 )
	{
	case 1:
		if ( x_1 <= board ) x_1 += dx_1;		// двигаем по оси x, пока не достигнет границы 
		else state_x_1 = -1;					// затем меняем направление 
		break;
	case -1:
		if ( x_1 >= -board)  x_1 -= dx_1;
		else state_x_1 = 1;
		break;
	}
	switch ( state_y_1 )						// аналогично по оси y
	{
	case 1:
		if ( y_1 <= board ) y_1 += dy_1;
		else state_y_1 = -1;
		break;
	case -1:
		if ( y_1 >= -board) y_1 -= dy_1;
		else state_y_1 = 1;
		break;
	}

	glTranslated( x_1, y_1, 0 );		// сдвиг на новые координаты x, y
	star( 3 );							// отрисовка звезды с масштабом 0.003

	// cout << x << " " << y << endl;

	//-----------------------------------------------------------------------

	board = 0.7;

	static GLfloat x_2 = -0.6,
				   y_2 = -0.3;  				 
	static int state_x_2 = 1,
			   state_y_2 = 1;
	static float dx_2 = 0.01, 
				 dy_2 = 0.02;
	
	switch ( state_x_2 )
	{
	case 1:
		if ( x_2 <= board ) x_2 += dx_2;
		else state_x_2 = -1;
		break;
	case -1:
		if ( x_2 >= -board) x_2 -= dx_2;
		else state_x_2 = 1;
		break;
	}
	switch ( state_y_2 )
	{
	case 1:
		if ( y_2 <= board ) y_2 += dy_2;
		else state_y_2 = -1;
		break;
	case -1:
		if ( y_2 >= -board) y_2 -= dy_2;
		else state_y_2 = 1;
		break;
	}

	glTranslated( x_2, y_2, 0 );
	star( 4 );

	//-----------------------------------------------------------------------

	board = 0.85;

	static GLfloat x_3 = -0.2,			
				   y_3 =  0.7;				 
	static int state_x_3 = 1,
			   state_y_3 =-1;
	static float dx_3 = 0.005, 
				 dy_3 = 0.002;
	
	switch ( state_x_3 )
	{
	case 1:
		if ( x_3 <= board ) x_3 += dx_3;
		else state_x_3 = -1;
		break;
	case -1:
		if ( x_3 >= -board) x_3 -= dx_3;
		else state_x_3 = 1;
		break;
	}
	switch ( state_y_3 )
	{
	case 1:
		if ( y_3 <= board ) y_3 += dy_3;
		else state_y_3 = -1;
		break;
	case -1:
		if ( y_3 >= -board) y_3 -= dy_3;
		else state_y_3 = 1;
		break;
	}

	glTranslated( x_3, y_3, 0 );
	star( 2 );

	//-----------------------------------------------------------------------

	glPopMatrix(); 						// восстановление матрицы
	glutSwapBuffers();					// перерисовка буфера
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc( 20, timer, 0 ); 		// вызов функции timer через 20 мс
}

int main(int argc, char** argv)
{	
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );		// два буфера для анимации

	glutInitWindowSize( 700, 700 );
	glutInitWindowPosition( 400, 100 );
	glutCreateWindow( "hello, animation" );

	init();
	glutDisplayFunc( display );
	glutTimerFunc( 0, timer, 0 );  

	glutMainLoop();

	return 0;
}