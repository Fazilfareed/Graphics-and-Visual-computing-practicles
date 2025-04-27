#include <glut.h>

float red = 1.0, green = 0.0, blue = 0.0; // Initial color
bool rPressed = false, gPressed = false;bPressed = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 

    glColor3f(red, green, blue); 
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
        glVertex2f( 0.5,  0.5);
        glVertex2f(-0.5,  0.5);
    glEnd();

    glFlush();
}

void updateColor() {
    if (rPressed && gPressed) {
        red = 1.0; green = 1.0; blue = 0.0; // Yellow
    } else if (rPressed) {
        red = 1.0; green = 0.0; blue = 0.0; // Red
    } else if (gPressed) {
        red = 0.0; green = 1.0; blue = 0.0; // Green
    } else if (gPressed){
        red = 0.0; green = 0.0; blue = 1.0; // Blue (default if no key pressed)
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r') rPressed = true;
    if (key == 'g') gPressed = true;
	if (key == 'b') bPressed = true;

    updateColor();
    glutPostRedisplay(); // Request to redraw the window
}

void keyboardUp(unsigned char key, int x, int y) {
    if (key == 'r') rPressed = false;
    if (key == 'g') gPressed = false;

    updateColor();
    glutPostRedisplay(); // Request to redraw the window
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLUT PostRedisplay Example");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);    // Register keyboard press callback
    glutKeyboardUpFunc(keyboardUp); // Register keyboard release callback

    glutMainLoop();
    return 0;
}
