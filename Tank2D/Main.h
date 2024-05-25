#pragma once

#ifndef _MAIN_H
#define _MAIN_H

#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <string>

#define PI 3.141592654

#include "tank.h"
#include "projectile.h"
#include "Menu.h"
#include "GlobalDeclarations.h"


int main(int argc, char** argv);
void display();
void my_reshape(int  width, int  height);
void update(int value);

//Keyboard
void handleKeyPress(unsigned char key, int x, int y);
void handleKeyPressUp(unsigned char key, int x, int y);
void handleSpecialKeyPress(int key, int x, int y);
void handleSpecialKeyPressUp(int key, int x, int y);
// Mouse
void passiveMotionFunc(int x, int y);
void mouseClick(int buttonPressed, int state, int x, int y);
void detectCollisions(Tank tank1, Tank tank2);

#endif