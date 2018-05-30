#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include "checkerboard.h"
#include "spider.h"

//#include "spider.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define delta 1000/60

//Variáveis globais
// Colors
GLfloat WHITE[] = {1, 1, 1};
GLfloat RED[] = {1, 0, 0};
GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};


CHECKERBOARD *chao = createCheckerboard();			//chão pelo qual a aranha se locomove
spider_t *spider = spider_create(1.0, 1.0, 3.0, GREEN);	//inicialização da aranha	

void display();

void reshape(int w, int h);

void keyboard(unsigned char key, int x, int y);

void keyboardUp(unsigned char key, int x, int y);

void init();

void timer(int v);

int main (int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Aranha 3D");

	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);

	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, -7.0, 0.0, 0.0, centerz(chao), 0.0, 1.0, 0.0);

	drawCheckerboard(chao);
	spider_draw(spider);

	glFlush();
	glutSwapBuffers();
}


void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y){
	std::cout << "Key pressed: " << key << ".\n";
	switch(key){
		case 'w': 
			spider_set_target(spider, 'w'); break;
		
		case 'a': 
			spider_set_target(spider, 'a'); break;
		
		case 's': 
			spider_set_target(spider, 's'); break;
		
		case 'd': 
			spider_set_target(spider, 'd'); break;

		case ' ':  break;
	}
}

void keyboardUp(unsigned char key, int x, int y){
	std::cout << "Key released: " << key << ".\n";
	spider_set_target(spider, ' ');
}

//função tratadora de eventos para o redesenho da tela
void init(){
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
	glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void timer(int v) {
	spider_update(spider);
	glutPostRedisplay();
	glutTimerFunc(delta, timer, v);
}