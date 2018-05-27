#pragma once

typedef struct {
	GLfloat posX, posY, posZ;
	GLfloat targetX, targetY, targetZ, distanceThreshold;
	GLfloat angle, angleThreshold;
	GLfloat rotationSpeed, translationSpeed;
	GLfloat abdomenRadius, headRadius;
	GLfloat distanceBetweenLegs;
	int modifierX, modifierY;
	bool rotateClockwise, rotating;

	GLfloat *color;
} spider_t;

spider_t* spider_create(GLfloat x, GLfloat y, GLfloat z, GLfloat *color);
void spider_draw(spider_t* spider);