#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include<time.h>
#include"Angel.h"
#include"vec.h"
#include<vector>

const int WIDTH = 500, HEIGHT = 500;

vec2 points[2] = { {1.0f,1.0f},{-1.0f,-1.0f} };

void init()
{
	//gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,0.0f);

	glLineStipple(5, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex2fv(points[0]);
	glVertex2fv(points[1]);
	glEnd();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	
	}


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitContextVersion(2, 0);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGLTut");

	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return 1;
	}

	init();

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}