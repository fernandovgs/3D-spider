#pragma once

typedef struct {
	GLfloat posX, posY, posZ;
	GLfloat dX, dY, dZ, distanceThreshold;
	GLfloat angle, angleThreshold, angle_variation;
	GLfloat rotationSpeed, translationSpeed;
	GLfloat abdomenRadius, headRadius;
	GLfloat distanceBetweenLegs;
	GLfloat distanceBetweenSpheres;
	GLfloat modifierX, modifierZ;
	bool rotateClockwise, rotating;

	GLfloat *color;
} spider_t;

spider_t* spider_create(GLfloat x, GLfloat y, GLfloat z, GLfloat *color);
void spider_draw(spider_t* spider);
void spider_set_target(spider_t *spider, unsigned char key_pressed);
void spider_update(spider_t *spider);
GLfloat spider_getX(spider_t *spider);
GLfloat spider_getY(spider_t *spider);
GLfloat spider_getZ(spider_t *spider);