#pragma once

typedef struct checkerboard CHECKERBOARD;

double centerx(CHECKERBOARD *c);
double centerz(CHECKERBOARD *c);
CHECKERBOARD *createCheckerboard();
void drawCheckerboard(CHECKERBOARD *c);