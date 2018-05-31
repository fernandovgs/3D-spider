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
	spider->angle = 0.0;
	spider->angle_variation = 0.0;
	spider->angleThreshold = 0.1;
	spider->distanceThreshold = 3;
	spider->posX = x;
	spider->posY = y;
	spider->posZ = z;
	spider->dX = 0.0;
	spider->dY = 0.0;
	spider->dZ = 0.0;
	spider->headRadius = 0.89f;
	spider->abdomenRadius = 1.01f;
	spider->distanceBetweenLegs = 0.4;
	spider->distanceBetweenSpheres = spider->abdomenRadius + spider->headRadius - 0.5;
	spider->color = color;
	spider->modifierX = 0.0;
	spider->modifierZ = 0.0;

	return spider;
}

void spider_draw(spider_t* spider) {
	int num_segments = 20;

	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);

	// //definindo as quádricas dos membros da aranha
	// GLUquadricObj *pe1, *pe2, *pe3, *pe4, *pd1, *pd2, *pd3, *pd4;
	// pe1 = gluNewQuadric();	//perna esquerda 1
	// pe2 = gluNewQuadric();	//perna esquerda 2
	// pe3 = gluNewQuadric();	//perna esquerda 3
	// pe4 = gluNewQuadric();	//perna esquerda 4
	// pd1 = gluNewQuadric();	//perna direita 1
	// pd2 = gluNewQuadric();	//perna direita 2
	// pd3 = gluNewQuadric();	//perna direita 3
	// pd4 = gluNewQuadric(); 	//perna direita 4


	//Abdomen da aranha
	glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX, spider->posY, spider->posZ);
	    glRotated(spider->angle, 0.0, 1.0, 0.0);		//rotaciona em Y
	    glutSolidSphere(spider->abdomenRadius, num_segments, num_segments);

    glPopMatrix();

    //Cefalotórax da aranha
        glPushMatrix();
	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	    glTranslated(spider->posX + (spider->distanceBetweenSpheres * sin(deg_to_rad(spider->angle))), 
	    	spider->posY, spider->posZ + (spider->distanceBetweenSpheres * cos(deg_to_rad(spider->angle))));
	    glRotated(spider->angle, 0.0, 1.0, 0.0);		//rotaciona em Y
	    glutSolidSphere(spider->headRadius, num_segments, num_segments);
    glPopMatrix();

       /***** Pernas do bicho *****/
   
    //Lado esquerdo

//     //Perna 1
//     glPushMatrix();
// 	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);

//  //		glTranslated(spider->posX + 1.7, spider->posY + 0.102, spider->posZ - (0.5 * spider->abdomenRadius));
   	 
//    	    glRotated(-45.0, cos((45.0 / 180.0)), 0.0, -sin((45.0 / 180.0)));	//Rotaciona em torno do eixo X
//    	    glRotated(90, 0, 1.0, 0);											//Rotaciona em torno do eixo Y
	   
// 	    gluCylinder(pe1, 0.087, 0.087, 1.7, 20, 20);	//desenha o cilindro
//     glPopMatrix();

//     //Perna 2
//     glPushMatrix();
// 	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
// //	    glTranslated(spider->posX + 3.5 - spider->distanceBetweenLegs, spider->posY + 0.6, spider->posZ - (2.0 * spider->abdomenRadius));
	    
// 	    glRotated(45.0, cos((45.0 / 180.0)), 0.0, -sin((45.0 / 180.0)));	//Rotaciona em torno do eixo X
// 		glRotated(-45, 0, 1.0, 0);											//Rotaciona em torno do eixo Y

// 	    gluCylinder(pe2, 0.087, 0.087, 1.7, 20, 20);
//     glPopMatrix();

//     //Perna 3
//     glPushMatrix();
// 	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);
	
// 	//    glTranslated(spider->posX + 1.9 - (2.0 * spider->distanceBetweenLegs), spider->posY + 1.2, spider->posZ - (4.0 * spider->abdomenRadius));

// 		glRotated(35.0, cos((35.0 / 180.0)), 0.0, -sin((35.0 / 180.0)));	//Rotaciona em torno do eixo X    

// 	    gluCylinder(pe3, 0.087, 0.087, 2.0, 20, 20);
//     glPopMatrix();

//     //Perna 4
//     glPushMatrix();
// 	    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, spider->color);

// 	   // glTranslated(spider->posX + 2.4 - (3.0 * spider->distanceBetweenLegs), spider->posY, spider->posZ - (0.7 * spider->abdomenRadius));

// 	    glRotated(45.0, cos((45.0 / 180.0)), 0.0, -sin((45.0 / 180.0)));	//Rotaciona em torno do eixo X
//    	    glRotated(-135, 0, 1.0, 0);	

// 	    gluCylinder(pe4, 0.087, 0.087, 2.0, 20, 20);
//     glPopMatrix();

}

void spider_set_target(spider_t *spider, unsigned char key_pressed){
	switch (key_pressed){
		//apertando 'w', a aranha anda para frente
		case 'w':
			spider->modifierX = 0.1 * sin(deg_to_rad(spider->angle));
			spider->modifierZ = 0.1 * cos(deg_to_rad(spider->angle));

		break;

		//apertando 's', a aranha anda para trás
		case 's':
			spider->modifierX = -(0.1 * sin(deg_to_rad(spider->angle)));
			spider->modifierZ = -(0.1 * cos(deg_to_rad(spider->angle)));

		break;

		//apertando 'a', a aranha rotaciona sentido anti-horário
		case 'a':
			spider->angle_variation = 1.0;

		break;

		//apertando 'd', a aranha rotaciona sentido horário
		case 'd':
			spider->angle_variation = -1.0;

		break;

		//para o movimento da aranha
		default:
			spider->modifierX = 0.0;
			spider->modifierZ = 0.0;
			spider->angle_variation = 0.0;
	}
}

void spider_update(spider_t *spider){
	spider->posX += spider->modifierX;
	spider->posZ += spider->modifierZ;
	spider->angle += spider->angle_variation;
}