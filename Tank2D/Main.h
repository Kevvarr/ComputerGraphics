#pragma once

#ifndef _MAIN_H
#define _MAIN_H

void my_reshape(int  width, int  height);
void display();
void update(int value);
void handleKeyPress(unsigned char key, int x, int y);

void handleSpecialKeyPress(int key, int x, int y);


void initRendering();
int main(int argc, char** argv);
void drawScene();
void setOrthographicProjection();
void resetPerspectiveProjection();
void createTank(float x, float y);
void checkInput();
void update(int value);
void handleKeypress(unsigned char key, int x, int y);
void handleKeyUp(unsigned char key, int x, int y);

#endif