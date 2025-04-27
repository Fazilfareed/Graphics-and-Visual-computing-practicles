#include <glut.h>
#include <math.h> 

#include <iostream>
using namespace std;

int ww = 800, wh = 600;
int xi, yi, xf, yf; 

void putPixel (int x, int y)  
{  
   glColor3f (0.3, 0.2, 0.0); // activate the pixel by setting the point color to white  
   glBegin (GL_POINTS);  
	glVertex2i (x, y); // set the point  
   glEnd ();  
   glFlush (); // process all openGL routines as quickly as possible  
} 

void plotCircle(int h, int k, int x, int y)
{
	putPixel((x+h), (y+k)); //x,y
	putPixel((y+h), (x+k));//y, x
	putPixel((-y+h), (x+k));//-y, x
	putPixel((-x+h), (y+k));//-x, y
	putPixel((-x+h), (-y+k));//-x,-y
	putPixel((-y+h), (-x+k));//-y,-x
	putPixel((y+h), (-x+k));//y,-x
	putPixel((x+h), (-y+k));//x,-y

}


void display()  
{  
   glClearColor(0.4, 0.7, 0.5, 1.0);  
   glColor3f(0.2, 0.3, 0.3);  
   glClear(GL_COLOR_BUFFER_BIT);  
   glFlush();  
} 

int round(float x){
	return floor(x+0.5);
}
void line_dda(int xa,int ya,int xb,int yb){ 
	int dx = xb-xa, dy = yb-ya, steps, k; 
	float xincrement, yincrement, x = xa, y = ya; 
	if(abs(dx) > abs(dy)) {
		steps = abs(dx); }
	else {steps = abs(dy);}
 
	xincrement = dx/(float)steps; 
	yincrement = dy/(float)steps; 
	//cout << "xa: " << xa << ", ya: " << ya << "\txb: " << xb << ", yb: " << yb << "\txincrement: " << xincrement << ", yincrement: " << yincrement<< "\tdy: " << dy << ", dx: " << dx<< ", steps: " << steps <<endl;
	putPixel(round(x), round(y)) ;
	for(k=0; k<steps; k++){ 
		x += xincrement; 
		y += yincrement; 
		
		putPixel(round(x), round(y)); 
	} 
}
void bresenhamCircle(int h, int k, int r)
{
	int x=0, y=r, d= 3-2*r;
	while(x <= y)
	{
		plotCircle(h, k, x, y);
		if(d<0)
		{
			d = d + 4*x + 6; 
		}
		else
		{
			d = d + 4*(x-y) + 10;
			y--;
		}
		x++;
	}
}

void mouse(int btn, int state, int x, int y)
{
	
	if (btn == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN)
		{
			
		}
		else if (state == GLUT_UP) {
			x=200;
			y=50*sqrt((double)3);
			double arr[6][2]={
				{x-100,200},
				{x-50,200-y},
				{x+50,200-y},
				{x+100,200},
				{x+50,200+y},
				{x-50,200+y},
			};
			for(int k=0;k<5;k++){
				cout<<"x: "<<arr[k][0]<<"\ty; "<<arr[k][1]<<endl;
				line_dda(arr[k][0],arr[k][1],arr[k+1][0],arr[k+1][1]);
				
				bresenhamCircle(arr[k][0], arr[k][1], 100);
			}
			line_dda(arr[5][0],arr[5][1],arr[0][0],arr[0][1]);
			bresenhamCircle(arr[5][0], arr[5][1], 100);
			
		}
	if (btn == GLUT_RIGHT_BUTTON) {
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}




void myinit()  
{        
     glViewport(0,0,ww,wh);  
     glMatrixMode(GL_PROJECTION);  
     glLoadIdentity();  
     gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
     glMatrixMode(GL_MODELVIEW);  
}  
int main(int argc, char** argv)  
{  
     glutInit(&argc,argv);  
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
     glutInitWindowSize(ww,wh);  
     glutCreateWindow("Midpoint Circle Algorithm");  
     glutDisplayFunc(display);  
     myinit();  
     glutMouseFunc(mouse);  
     glutMainLoop();  
     return 0;  
}