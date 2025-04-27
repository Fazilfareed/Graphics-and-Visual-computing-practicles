#include <glut.h>

float x = 0;
bool run=true;
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x - 0.5, -0.5);
    glVertex2f(x - 0.5, 0.5);
    glVertex2f(x + 0.5, 0.5);
    glVertex2f(x + 0.5, -0.5);
  glEnd();
  glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON)

		if (state == GLUT_DOWN)
		{
			run=false;
		}
		if (state == GLUT_UP)
		{
			run=true;
		}

	if (btn == GLUT_RIGHT_BUTTON)

		if (state == GLUT_DOWN)
		{
			run=true;
		}
	
}

void animate(int value) {
  x += 0.01;
  if (x > 1.5) x = -1.5;
  glutPostRedisplay();
  
  glutMouseFunc(mouse);  
  
  if(run){glutTimerFunc(2, animate, value);}
 
  

}
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Translation Animation");
  glutDisplayFunc(display);
  glutTimerFunc(25, animate, 0);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.5, 1.5, -1.0, 1.0, -1.0, 1.0);
  glutMouseFunc(mouse);  
  glutMainLoop();
  return 0;
}