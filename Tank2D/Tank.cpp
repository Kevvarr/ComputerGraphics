#include <GL/glew.h>
#include <GL/glut.h>
#include "tank.h"
//#include "projectile.h"
#include <iostream>
#include "textures.h"


const float PI = 3.14159265;

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

    return;
}

Tank::Tank(std::string imageFile, int x, int y) : imageFile(imageFile), x(x), y(y) {
    x = x;
    y = y;
    imageFile = imageFile;
    std::cout << "XX: " << x;
    std::cout << "YY: " << y;
    Tank::loadTexture(imageFile); // Load texture in constructor
    //Tank::drawTexture(); // Load texture in constructor
}

void Tank::loadTexture(std::string imageFile) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(imageFile.c_str(), &width, &height, &nrChannels, 0);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Generate texture
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cerr << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Tank::drawTexture() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x - size, y - size);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + size, y - size);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + size, y + size);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x - size, y + size);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

// The rest of your Tank class implementation remains unchanged


void Tank::moveUp() {
    directionX = 0.0f;
    directionY = 1.0f;
    //std::cout << "Moving Up";
}

void Tank::moveDown() {
    directionX = 0.0f;
    directionY = -1.0f;
    //std::cout << "Moving Down";
}

void Tank::moveLeft() {
    directionX = -1.0f;
    directionY = 0.0f;
    //std::cout << "Moving Left";
}

void Tank::moveRight() {
    directionX = 1.0f;
    directionY = 0.0f;
    //std::cout << "Moving Right";
}

void Tank::moveIdle() {
    directionX = 0.0f;
    directionY = 0.0f;
    std::cout << "Moving Idle";
}

void Tank::shoot() {
    //Projectile::create(x, y, directionX, directionY);
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