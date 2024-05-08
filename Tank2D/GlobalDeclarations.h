#pragma once

bool isFullscreen = false;
float mouseX, mouseY;
bool mButtonPressed = false;

GLint m_viewport[4];
enum view { INTRO, MENU, INSTRUCTIONS, GAME, GAMEOVER };
//enum view { INTRO, MENU, GAME, GAMEOVER };
view viewPage = INTRO; // initial value

Tank tank1("/Image/t34.png", -300, 0); // Initial position of tank 1
Tank tank2("/Image/panzer.png", 300, 0); // Initial position of tank 2

GLfloat eyeX = 0.0f;
GLfloat eyeY = 2.0f;
GLfloat eyeZ = 5.0f;
