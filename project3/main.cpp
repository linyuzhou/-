#include<bits/stdc++.h>
#include<GL/glut.h>
#include<windows.h>
using namespace std;

void Initiation(void){
	GLfloat Specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat Shininess[] = {100.0};
	GLfloat Position[] = {5.0, 5.0, 5.0, 1.0};

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, Position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 300, 16);
	glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(400,400);
	glutCreateWindow( "A Ball" );
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.5, 1.5, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	Initiation();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
