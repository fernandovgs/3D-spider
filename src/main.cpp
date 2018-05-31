#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include "checkerboard.h"
#include "spider.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700
#define delta 1000/60

//Variáveis globais
//Cores
GLfloat WHITE[] = {1, 1, 1};
GLfloat RED[] = {1, 0, 0};
GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};


CHECKERBOARD *chao = checkerboard_create();			//chão pelo qual a aranha se locomove
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
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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

	//Janela eixo Z
	glViewport(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(spider_getX(spider) - 1.0, 1.0, -7.0, spider_getX(spider), 1.0, spider_getZ(spider), 0.0, 1.0, 0.0);
	checkerboard_draw(chao);	//desenha o chão
	spider_draw(spider);		//desenha a aranha

	//janela "livre"
	glViewport(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(spider_getX(spider), 8.0, -spider_getZ(spider), spider_getX(spider), spider_getY(spider), spider_getZ(spider), 0.0, 1.0, 0.0);
	checkerboard_draw(chao);	//desenha o chão
	spider_draw(spider);		//desenha a aranha

	// janela eixo X
	glViewport(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(8.0, 3.0, spider_getZ(spider), spider_getX(spider), 0.0, spider_getZ(spider), 0.0, 1.0, 0.0);
	checkerboard_draw(chao);	//desenha o chão
	spider_draw(spider);		//desenha a aranha

	// janela Y
	glViewport(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	glLoadIdentity();
	gluLookAt(spider_getX(spider), 10.0, 0.0, spider_getX(spider), 0.0, spider_getZ(spider), 0.0, 1.0, 0.0);
	checkerboard_draw(chao);	//desenha o chão
	spider_draw(spider);		//desenha a aranha

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

	//A tecla espaço muda somente a câmera
	if (key != ' ') spider_set_target(spider, ' ');
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