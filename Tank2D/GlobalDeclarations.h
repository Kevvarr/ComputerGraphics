#pragma once

bool isFullscreen = false;

std::string addrTank1 = "Image/t34.png";

Tank tank1(addrTank1 , -300, 0); // Initial position of tank 1
//Tank tank2("/Image/panzer.png", 300, 0); // Initial position of tank 2

GLfloat eyeX = 0.0f;
GLfloat eyeY = 2.0f;
GLfloat eyeZ = 5.0f;
