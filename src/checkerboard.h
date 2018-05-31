#pragma once

typedef struct checkerboard CHECKERBOARD;

double checkerboard_getCenterX(CHECKERBOARD *c);
double checkerboard_getCenterZ(CHECKERBOARD *c);
CHECKERBOARD *checkerboard_create();
void checkerboard_draw(CHECKERBOARD *c);