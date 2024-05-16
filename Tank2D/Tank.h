#ifndef _TANK_H
#define _TANK_H
#include <string>

class Tank {
public:
    Tank(std::string imageFile, int x, int y);
    void draw();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();    
    void moveUpRelease();
    void moveDownRelease();
    void moveLeftRelease();
    void moveRightRelease();
    void moveIdle();
    float getDirectionX();
    float getDirectionY();
    void shoot();
    void update();

private:
    std::string imageFile;
    int x, y;
    int size = 20;
    float speed = 1.0;
    float directionX = 0.0f; // Horizontal direction (-1 for left, 1 for right)
    float directionY = 0.0f; // Vertical direction (-1 for down, 1 for up)
};

#endif // TANK_H
