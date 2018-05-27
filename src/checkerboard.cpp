#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include "checkerboard.h"

// Colors
GLfloat white[] = {1, 1, 1};
GLfloat red[] = {1, 0, 0};
GLfloat green[] = {1, 0, 0};
GLfloat magenta[] = {1, 0, 1};

struct checkerboard{
	int displayListId;
	int width;
	int depth;
};


double centerx(CHECKERBOARD *c){
	return c->width/2.0;
}


double centerz(CHECKERBOARD *c){
	return c->depth/2.0;
}

/**/
CHECKERBOARD *createCheckerboard(){
	CHECKERBOARD *c = (CHECKERBOARD*) malloc(sizeof(CHECKERBOARD));

	c->displayListId = 0;
	c->width = 80;
	c->depth = 80;

	return c;
}

/**/
void drawCheckerboard(CHECKERBOARD *c){
	c->displayListId = glGenLists(1);
	glNewList(c->displayListId, GL_COMPILE);

	glBegin(GL_QUADS);

	glNormal3d(0, 1, 0);

	for (int i = 0; i < c->width - 1; i++){
		for (int j = 0; j < c->depth - 1; j++){
			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
				(i + j) % 2 == 0 ? red : white);
			glVertex3d(i, 0, j);
			glVertex3d(i+1, 0, j);
			glVertex3d(i+1, 0, j+1);
			glVertex3d(i, 0, j+1);
		}
	}

	glEnd();
	glEndList();

	glCallList(c->displayListId);
}

