#include <GL/glut.h>
#include "tank.h"
#include "projectile.h"


Tank tank1("/Image/t34.png", 100, 100); // Initial position of tank 1
Tank tank2("/Image/panzer.png", 500, 500); // Initial position of tank 2

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    tank1.draw();
    tank2.draw();

    glutSwapBuffers();
}

void update(int value) {
    // Update tanks
    tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 fps)
}

void handleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        tank1.moveUp();
        break;
    case 's':
        tank1.moveDown();
        break;
    case 'a':
        tank1.moveLeft();
        break;
    case 'd':
        tank1.moveRight();
        break;
    case ' ':
        tank1.shoot();
        break;
    case 13: // ASCII code for Enter key
        tank2.shoot();
        break;
    }
}

void handleSpecialKeyPress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        tank2.moveUp();
        break;
    case GLUT_KEY_DOWN:
        tank2.moveDown();
        break;
    case GLUT_KEY_LEFT:
        tank2.moveLeft();
        break;
    case GLUT_KEY_RIGHT:
        tank2.moveRight();
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tank Game");

    glClearColor(0.0, 1.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKeyPress);

    glutMainLoop();

    return 0;
}
