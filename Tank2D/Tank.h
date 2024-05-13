#ifndef TANK_H
#define TANK_H

#include <string>


class Tank {
public:
    Tank(std::string imageFile, int x, int y);
    void draw();
    void loadTexture(std::string ImageFile);
    void drawTexture();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveIdle();
    void shoot();
    void update();

private:
    std::string imageFile;
    GLuint textureID;
    int x, y;
    GLfloat size = 20.0f;
    float speed = 3.5;
    float directionX = 0.0f; // Horizontal direction (-1 for left, 1 for right)
    float directionY = 0.0f; // Vertical direction (-1 for down, 1 for up)
};

#endif // TANK_H
