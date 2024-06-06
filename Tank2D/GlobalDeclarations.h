#pragma once
#define INIT_WINDOWS_SIZE_WEIGHT 1200
#define INIT_WINDOWS_SIZE_HEIGHT 900

bool isFullscreen = true;
float mouseX, mouseY;
bool mButtonPressed = false;

GLint m_viewport[4]; 
enum class View { INTRO, MENU, GAME, GAMEOVER };
View viewPage = View::INTRO; // initial value

Tank tank1("/Image/t34.png", -400, 0); // Initial position of tank 1
Tank tank2("/Image/panzer.png", 400, 0); // Initial position of tank 2

GLfloat eyeX = 0.0f;
GLfloat eyeY = 2.0f;
GLfloat eyeZ = 5.0f;

std::map< int, bool > keys;
