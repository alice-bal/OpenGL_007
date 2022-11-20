void background()
{
	glColor3ub(104, 139, 227);    		// синий цвет

	glBegin(GL_POLYGON);
		
		glVertex2f(-1, 1);
		glVertex2f(1, 1);

		glColor3ub(182, 104, 227);	    // розовый цвет 

		glVertex2f(1, -1);
		glVertex2f(-1, -1);

	glEnd();
}
