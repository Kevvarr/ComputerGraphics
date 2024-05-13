
#include "Main.h"
#include "GlobalDeclarations.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //Tank tank1 = new Tank("/Image/t34.png", 100, 100);
    //Tank tank2 = new Tank("/Image/panzer.png", 500, 500);

    // Windows Config
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tank Game");

    ///BackGround green color
    glClearColor(0.0, 1.0, 0.0, 1.0);

    glutReshapeFunc(my_reshape);
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    // Handle funtions
    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKeyPress);

    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    //tank1 = new Tank("/Image/t34.png", 100, 100);
    //gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    tank1.draw();
    tank1.drawTexture();
    //tank2.draw();

    glutSwapBuffers();
    //glFlush();
}

void update(int value) {
    // Update tanks
    tank1.update();
    //tank2.update();

    // Update projectiles
    //Projectile::updateAll();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 fps)
}

void my_reshape(int  width, int  height)
{
    int aspect = width * 1.0f / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);
    glMatrixMode(GL_MODELVIEW);
    //gluPerspective(60.0f, aspect, 0.1f, 10.0f);
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
        /*
    case ' ':
        tank1.shoot();
        break;
    case 13: // ASCII code for Enter key
        tank2.shoot();
        break;
        */
    }
}

void handleSpecialKeyPress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        //tank2.moveUp();
        break;
    case GLUT_KEY_DOWN:
        //tank2.moveDown();
        break;
    case GLUT_KEY_LEFT:
        //tank2.moveLeft();
        break;
    case GLUT_KEY_RIGHT:
        //tank2.moveRight();
        break;
    }
}
