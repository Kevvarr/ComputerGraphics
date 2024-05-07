#pragma once

#ifndef _MAIN_H
#define _MAIN_H

#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

#define PI 3.141592654

#include "tank.h"
#include "projectile.h"

void display();
void my_reshape(int  width, int  height);
void update(int value);
void handleKeyPress(unsigned char key, int x, int y);
void handleKeyPressUp(unsigned char key, int x, int y);
void handleSpecialKeyPress(int key, int x, int y);
void handleSpecialKeyPressUp(int key, int x, int y);



#endif