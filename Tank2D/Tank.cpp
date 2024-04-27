#include <GL/glut.h>
#include "tank.h"
#include "projectile.h"

const float PI = 3.14159265;

Tank::Tank(std::string imageFile, int x, int y) : imageFile(imageFile), x(x), y(y) {}

void Tank::draw() {
    // Assuming the tank image is drawn as a rectangle at position (x, y)
    glColor3f(0.0, 1.0, 1.0); // White color for tank
    glBegin(GL_POLYGON);
    glVertex2f(x - 20, y - 20); // Assuming tank size is 40x40
    glVertex2f(x + 20, y - 20);
    glVertex2f(x + 20, y + 20);
    glVertex2f(x - 20, y + 20);
    glEnd();
}

void Tank::moveUp() {
    directionX = 0.0f;
    directionY = 1.0f;
}

void Tank::moveDown() {
    directionX = 0.0f;
    directionY = -1.0f;
}

void Tank::moveLeft() {
    directionX = -1.0f;
    directionY = 0.0f;
}

void Tank::moveRight() {
    directionX = 1.0f;
    directionY = 0.0f;
}

void Tank::shoot() {
    Projectile::create(x, y, directionX, directionY);
}

void Tank::update() {
    // Update tank position based on direction and speed
    x += speed * directionX;
    y += speed * directionY;

    // Ensure tank stays within the bounds of the screen
    if (x < 20) {
        x = 20;
    }
    else if (x > 800 - 20) {
        x = 800 - 20;
    }

    if (y < 20) {
        y = 20;
    }
    else if (y > 600 - 20) {
        y = 600 - 20;
    }
}
