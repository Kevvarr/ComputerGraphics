#ifndef TEXTURES_H
#define TEXTURES_H

#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Textures {
public:
    Textures(std::string imageFile, int x, int y);
    virtual void loadTexture(std::string imageFile);
    virtual void drawTexture();

    //

private:
    std::string imageFile;
    int x, y;
    GLfloat size = 20.0f;
    float speed = 3.5f;
    float directionX = 0.0f; // Horizontal direction (-1 for left, 1 for right)
    float directionY = 0.0f; // Vertical direction (-1 for down, 1 for up)
};

#endif // TANK_H
