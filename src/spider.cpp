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
	spider->distanceBetweenLegs = 5;
	spider->rotating = false;
	spider->color = color;

	return spider;
}

void spider_draw(spider_t* spider) {
	int num_segments = 20;

	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);

	//Abdomen da aranha
	glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX, spider->posY, spider->posZ);
	    glutSolidSphere(spider->headRadius, num_segments, num_segments);
    glPopMatrix();

    //Cefalotórax da aranha
	glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX, spider->posY, spider->posZ);
	    glutSolidSphere(spider->headRadius, num_segments, num_segments);
    glPopMatrix();

    glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX + spider->headRadius, spider->posY, spider->posZ + spider->headRadius);
	    glutSolidSphere(spider->abdomenRadius, num_segments, num_segments);
    glPopMatrix();

}