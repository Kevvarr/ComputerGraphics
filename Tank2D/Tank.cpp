#include <GL/glut.h>
#include "tank.h"
#include "projectile.h"
#include <iostream>

const float PI = 3.14159265;

Tank::Tank(std::string imageFile, int x, int y) : imageFile(imageFile), x(x), y(y) {
    x = x;
    y = y;
    imageFile = imageFile;
    std::cout << "XX: " << x;
    std::cout << "YY: " << y;
}

void Tank::draw() {
    // Assuming the tank image is drawn as a rectangle at position (x, y)
    glColor3f(1.0, 0.0, 0.0); // White color for tank
    glBegin(GL_POLYGON);
    glVertex2f(x - size, y - size); // Assuming tank size is 40x40
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glEnd();
    glFlush();
}

void Tank::moveUp() {
    directionY = 1.0f;
    //std::cout << "Moving Up";
}

void Tank::moveDown() {
    directionY = -1.0f;
    //std::cout << "Moving Down";
}

void Tank::moveLeft() {
    directionX = -1.0f;
    //std::cout << "Moving Left";
}

void Tank::moveRight() {
    directionX = 1.0f;
    //std::cout << "Moving Right";
}

void Tank::moveUpRelease() {
    directionY = 0.0f;
}

void Tank::moveDownRelease() {
    directionY = 0.0f;
}

void Tank::moveLeftRelease() {
    directionX = 0.0f;
}

void Tank::moveRightRelease() {
    directionX = 0.0f;
}

void Tank::moveIdle() {
    directionX = 0.0f;
    directionY = 0.0f;
    std::cout << "Moving Idle";
}

float Tank::getDirectionX() { return this->directionX; }
float Tank::getDirectionY() { return this->directionY; }

void Tank::shoot() {
    Projectile::create(x, y, directionX, directionY);
}

void Tank::update() {
    // Update tank position based on direction and speed
    x += speed * directionX;
    y += speed * directionY;
    //std::cout << "/x: " << x;
    //std::cout << "/y: " << y;
    //x = 0;
    //y = 0;
    
    // Ensure tank stays within the bounds of the screen
    if (x < -380) {
        x = -380;
    }
    else if (x > 380) {
        x = 380;
    }

    if (y < -280) {
        y = -280;
    }
    else if (y > 280) {
        y = 280;
    }
    
}
