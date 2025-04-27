#include <windows.h>
#include <glut.h>
#include <cmath> 

void init()
{
	glClearColor (1.0, 1.0, 1.0, 1.0);

	glColor3f(1.0, 1.0, 1.0); 

	glMatrixMode (GL_PROJECTION);    
	glLoadIdentity ();    
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  
}


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_LINE_LOOP);        
		glVertex2f(-0.3, -0.5);              
		glVertex2f(0.3, -0.5);        
		glVertex2f(0.6, 0);
		glVertex2f(0.8, 0.9);

		glVertex2f(0.3, 0.5);   

		glVertex2f(0.2, 0.59);
		glVertex2f(-0.2, 0.59);

		glVertex2f(-0.3, 0.5);
		glVertex2f(-0.8, 0.9);        
		glVertex2f(-0.6, 0);    
	glEnd();
	glFlush(); 
}
void mydisplay2(){
    glClear(GL_COLOR_BUFFER_BIT); 
	glPointSize(10.0f);
	glBegin(GL_POINTS);        
		glVertex2f(-0.5, -0.5);        
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);        
		glVertex2f(0.5, -0.5);    
	glEnd();
	glFlush(); 
}
void mydisplay3(){
    glClear(GL_COLOR_BUFFER_BIT); 
	glLineWidth(3.0f);
	glBegin(GL_LINES);        
		glVertex2f(-0.5, -0.5);        
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);        
		glVertex2f(0.25, -0.75);    
	glEnd();
	glFlush(); 
}
void mydisplay4(){
    glClear(GL_COLOR_BUFFER_BIT); 
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);        
		glVertex2f(-0.5, -0.5);        
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);        
		glVertex2f(0.25, -0.75);    
	glEnd();
	glFlush(); 
}
void mydisplay5(){
    glClear(GL_COLOR_BUFFER_BIT); 
    glLineWidth(3.0f);
    
    glBegin(GL_POLYGON);        
        for (float t = 0; t <= 2 * 3.14159; t += 0.05) {
            float x = 0.16 * sin(t) * sin(t) * sin(t); // Heart shape formula
            float y = 0.13 * cos(t) - 0.05 * cos(2 * t) - 0.02 * cos(3 * t) - 0.01 * cos(4 * t);
            glVertex2f(x, y);
        }
    glEnd();
    
    glFlush(); 
}
//20250314
void mydisplay6(){
	 glClear(GL_COLOR_BUFFER_BIT); 
	  glLineWidth(3.0f);
	 glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(0.1f, -0.6f);
      glVertex2f(0.7f, -0.6f);
      glVertex2f(0.4f, -0.1f);
 
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(0.3f, -0.4f);
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f(0.9f, -0.4f);
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(0.6f, -0.9f);

	 
   glEnd();
    glFlush(); 
}

//FOUR TRIANGLE
void mydisplay7(){
	 glClear(GL_COLOR_BUFFER_BIT); 
	  glLineWidth(3.0f);

	  glBegin(GL_POLYGON);
	    glColor3f(0.0f, 0.0f, 0.0f); // Blue
      glVertex2f(-0.9f, 0.9f);
      glVertex2f(0.9f, 0.9f);
      glVertex2f(0.9f, -0.9f);
      glVertex2f(-0.9f, -0.9f);
	  
	  glEnd();


	 glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
		//upper triangle
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(-0.6f, 0.9f);
	  glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.0f, 0.0f);
	  glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(0.6f, 0.9f);
 
	  //RIGHT TRIANGLE
      glColor3f(1.0f, 0.7f, 0.7f); // Red
      glVertex2f(0.9f, 0.6f);
      glColor3f(1.0f, 1.0f, 1.0f); // Green
      glVertex2f(0.0f, 0.0f);
      glColor3f(1.0f, 0.7f, 0.7f); // Blue
      glVertex2f(0.9f, -0.6f);

	  //BOTTOM
	   glColor3f(1.0f, 1.0f, 1.0f); // Red
      glVertex2f(0.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 1.0f); // Green
      glVertex2f(-0.6f, -0.9f);
      glColor3f(0.0f, 1.0f, 1.0f); // Blue
      glVertex2f(0.6f, -0.9f);

	  //lEFT TRIANGLE
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex2f(-0.9f, 0.6f);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.0f, 0.0f);
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex2f(-0.9f, -0.6f);
   glEnd();
    glFlush(); 
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  //decide which display we are going to use
	//single-->for single frame(single buffer,not suitable for animation bcz of taking too much time to load), double-->for multiple frames like in animation(2nd frame saved in memory)
	glutInitWindowSize(500,500);//initial window size
	glutInitWindowPosition(500,200);//where it should open
	glutCreateWindow("image"); // the name displayed in the window
	glutDisplayFunc(mydisplay);  
	init();  
	glutMainLoop();
}