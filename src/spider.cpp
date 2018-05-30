#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

#include "spider.h"

#define PI 3.1415926535f
#define sign(x) (x > 0) ? 1 : ((x < 0) ? -1 : 0)
#define rad_to_deg(radians) ((radians) * 180.0f / PI)
#define deg_to_rad(degrees) ((degrees) * PI / 180.0f)

spider_t* spider_create(GLfloat x, GLfloat y, GLfloat z, GLfloat *color) {
	spider_t* spider = (spider_t*) malloc(sizeof(spider_t));
	spider->rotationSpeed = 200;
	spider->translationSpeed = 1;
	spider->angle = -90;
	spider->angleThreshold = 0.1;
	spider->distanceThreshold = 3;
	spider->posX = x;
	spider->posY = y;
	spider->posZ = z;
	spider->targetX = 0.0;
	spider->targetY = 0.0;
	spider->targetZ = 0.0;
	spider->headRadius = 0.89f;
	spider->abdomenRadius = 1.01f;
	spider->distanceBetweenLegs = 0.4;
	spider->rotating = false;
	spider->color = color;
	spider->modifierX = 0.0;
	spider->modifierZ = 0.0;

	return spider;
}

void spider_draw(spider_t* spider) {
	int num_segments = 20;

	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);

	//definindo as quádricas das pernas da aranha
	GLUquadricObj *pe1, *pe2, *pe3, *pe4, *pd1, *pd2, *pd3, *pd4;
	pe1 = gluNewQuadric();
	pe2 = gluNewQuadric();
	pe3 = gluNewQuadric();
	pe4 = gluNewQuadric();
	pd1 = gluNewQuadric();
	pd2 = gluNewQuadric();
	pd3 = gluNewQuadric();
	pd4 = gluNewQuadric(); 


	//Cefalotórax da aranha
	glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX, spider->posY, spider->posZ);
	    glutSolidSphere(spider->abdomenRadius, num_segments, num_segments);
    glPopMatrix();

    //Abdômen da aranha
    glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX + (spider->headRadius * 2.0) - 0.3, spider->posY, spider->posZ);
	    glutSolidSphere(spider->headRadius, num_segments, num_segments);
    glPopMatrix();

}

void spider_set_target(spider_t *spider, unsigned char key_pressed){
	switch (key_pressed){
		//apertando 'w', a aranha anda para frente
		case 'w':
			spider->modifierX = 0.1;

		break;

		//apertando 's', a aranha anda para trás
		case 's':
			spider->modifierX = -0.1;

		break;

		//apertando 'a', a aranha rotaciona sentido anti-horário
		case 'a':


		break;

		//apertando 'd', a aranha rotaciona sentido horário
		case 'd':


		break;

		default:
			spider->modifierX = 0.0;
			spider->modifierZ = 0.0;
	}
}

void spider_update(spider_t *spider){
	spider->posX += spider->modifierX;
}