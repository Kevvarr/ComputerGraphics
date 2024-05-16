//#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <string>
#include <GL/glut.h>
#include <stdlib.h>
//#include <SOIL.h>

#include "ExternDeclarations.h"

void screenIntro();
void screenMenu();
void screenGame();
void displayRasterText(float x, float y, float z, std::string stringToDisplay);

#endif