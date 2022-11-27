// cd ../ && cd 006 && g++ 006.cpp -lGL -lGLU -lGLEW -lglut -o 006 && ./006

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

/* globals */
GLsizei wh = 500,               // initial window size
        ww = 500; 

int points = 100000;

/* reshaping routine called whenever window is resized or moved */
void myReshape(GLsizei w, GLsizei h)
{
    /* adjust clipping box */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* adjust viewport and clear */
    glViewport(0,0,w,h);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    /* set global size for use by drawing routine */
    ww = w;
    wh = h;
}

void myinit()
{
      glClearColor(0.0, 0.0, 0.0, 0.0);         // background
      glColor3f(0.0,1.0,1.0);                   // cyan

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, 500.0, 0.0, 500.0);
      glMatrixMode(GL_MODELVIEW);
}

void barnsleyFern()
{
	typedef GLfloat point2[2];
	point2 p = {0.0,50.0},newPoint;

	/*Probability table of the 3 transformations*/
	double probability[3] = {85, 92, 99};

	glClear ( GL_COLOR_BUFFER_BIT );

	/*main drawing loop*/
    for(int i=0; i<points; i++)
	{
	   GLfloat prevx=p[0];
	   GLfloat randnum=rand()%100 +1;
	   if (randnum<probability[0])
       {
            p[0]=p[0]*0.85+0.04*p[1];
            p[1]=prevx*(-0.04)+0.85*p[1]+1.6;
	   }
	   else if(randnum<probability[1])
	   {
            p[0]=0.2*p[0]-0.26*p[1];
            p[1]=0.23*prevx+0.22*p[1]+1.6;
	   }
	   else if(randnum<probability[2])
	   {
            p[0]=-0.15*p[0]+0.28*p[1];
            p[1]=0.26*prevx+0.24*p[1]+0.44;
	   }
	   else
	   {
            p[0]=0.0;
            p[1]=0.16*p[1];
	   }

	   newPoint[0]=p[0]*50+250;
	   newPoint[1]=p[1]*50;
	   if(i>100)
	   {
		  /*Plot new point*/
		  glBegin(GL_POINTS);
               glVertex2fv(newPoint);
          glEnd();
	   }
  }
	//  Clear all buffers.
	glFlush ( );
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
    /* Standard GLUT initialization */
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );                  // double buffering
    glutInitWindowSize( ww, wh );                                   // 500 x 500 pixel window
    glutInitWindowPosition( 0, 0 );                                 // place window top left on display
    glutCreateWindow( "Fractal barnsley fern" );                    // window title

    glutDisplayFunc( barnsleyFern );

    myinit();                                                       // set attributes
    glutReshapeFunc (myReshape);
    glutMainLoop();                                                 // enter event loop

    return 0;
}