#include <GL/glut.h>
#include "projectile.h"

std::vector<Projectile> projectiles;

void Projectile::create(int x, int y, int directionX, int directionY) {
    Projectile projectile;
    projectile.x = x;
    projectile.y = y;
    // Set direction and speed here
    projectiles.push_back(projectile);
}

void Projectile::updateAll() {
    for (auto& projectile : projectiles) {
        // Update projectile position based on direction and speed
        projectile.y += projectile.speed;
    }
}

void Projectile::draw() {
    // Assuming projectile is drawn as a small rectangle
    glColor3f(1.0, 0.0, 0.0); // Red color for projectile
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y - 2); // Assuming projectile size is 4x4
    glVertex2f(x + 2, y - 2);
    glVertex2f(x + 2, y + 2);
    glVertex2f(x - 2, y + 2);
    glEnd();
}
