#include <GL/glut.h>
#include "projectile.h"
#include <iostream>

std::vector<Projectile> projectiles;


std::vector<Projectile> Projectile::getProjectiles() {
    return projectiles;
}

void Projectile::create(int x, int y, int directionX, int directionY) {
    Projectile projectile;
    projectile.x = x;
    projectile.y = y;
    projectile.directionX = directionX;
    projectile.directionY = directionY;
    // Set direction and speed here
    projectiles.push_back(projectile);
}

void Projectile::drawAll() {
    for (auto& projectile : projectiles) {
        if (projectile.alive) {
            projectile.draw();
        }
    }
}

void Projectile::updateAlive() {
    for (auto& projectile : projectiles) {
        // Update projectile position based on direction and speed
        projectile.counterTimer++;
        projectile.counterTimerKill++;

        if (projectile.counterTimer > projectile.counterTimerMax) {
            projectile.alive = false;
            projectile.kill = false;
        }
        if (projectile.counterTimerKill > 5 && projectile.counterTimerKill < 7) {
            projectile.kill = true;
        }
    }
}



void Projectile::updateAll() {
    for (auto& projectile : projectiles) {
        if (projectile.alive) {
            // Update projectile position based on direction and speed
            projectile.x += projectile.speed * projectile.directionX;
            projectile.y += projectile.speed * projectile.directionY;
        }
        
    }
}

void Projectile::draw() {
    // Assuming projectile is drawn as a small rectangle
    glColor3f(1.0, 1.0, 0.0); // Red color for projectile
    glBegin(GL_POLYGON);
    glVertex2f(x - size, y - size); // Assuming projectile size is 4x4
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glEnd();
    // std::cout << "Drawed";
}
