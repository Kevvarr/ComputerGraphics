#include "Main.h"
#include "GlobalDeclarations.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    // Windows Config
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(INIT_WINDOWS_SIZE_WEIGHT, INIT_WINDOWS_SIZE_HEIGHT);
    // glutInitWindowPosition(0, 0);
    glutCreateWindow("Tank Game");


    glClearColor(0.0, 0.0, 0.0, 0);

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(
        -(int)INIT_WINDOWS_SIZE_WEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_WEIGHT / 2,
        -(int)INIT_WINDOWS_SIZE_HEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_HEIGHT / 2);
    glMatrixMode(GL_MODELVIEW);

    ///BackGround green color
    //glClearColor(0.0, 1.0, 0.0, 1.0);
    glClearColor((double) 53 / 255, 
                 (double) 24 / 255,
                 (double) 14 / 255, 1.0); // green background - RGB


    // Handle funtions
    //glutIdleFunc(refresh);

    //glutKeyboardFunc(handleKeyPress);
    //glutSpecialFunc(handleSpecialKeyPress);

    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMotionFunc);



    // Handle funtions
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyPressUp);
    glutSpecialFunc(handleSpecialKeyPress);
    glutSpecialUpFunc(handleSpecialKeyPressUp);


    glGetIntegerv(GL_VIEWPORT, m_viewport);

    glutReshapeFunc(my_reshape);
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();

    return 0;
}

void display() {     
    //keyOperations();
    glClear(GL_COLOR_BUFFER_BIT);

    switch (viewPage)
    {
        case View::INTRO:
            screenIntro();
            //std::cout << "INTRO MODE" << std::endl;
            break;
        case View::MENU:
            screenMenu();
            break;
        case View::GAME:
            screenGame();
            break;
        case View::GAMEOVER:
            //displayGameOverMessage();
            screenIntro();
            break;
    }

}

void update(int value) {
    // Update tanks
    tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 fps)
    /*
    // Update tanks

    //checkInput();

    */
    /*tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();*/
    

    //glutPostRedisplay();
    //glutTimerFunc(16, timer, 0); // Update every 16 milliseconds (about 60 fps)*/
}

void my_reshape(int  width, int  height)
{
    int aspect = width * 1.0f / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(-400, 400, -300, 300);
    gluOrtho2D(
        -(int)INIT_WINDOWS_SIZE_HEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_HEIGHT / 2,
        -(int)INIT_WINDOWS_SIZE_WEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_WEIGHT / 2);
    glMatrixMode(GL_MODELVIEW);
    //gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

void handleKeyPress(unsigned char key, int x, int y) {
    keys[key] = true;

    std::cout << "# key " << key << " released" << std::endl;
    std::cout << "# VIEW:  " << static_cast<std::underlying_type<View>::type>(viewPage) << "." << std::endl;
    std::cout << "# key status:  " << keys[13] << "." << std::endl;

    if (keys[13] == true && viewPage == View::INTRO) viewPage = View::MENU;
    if (keys[int('m')] == true && viewPage == View::MENU) viewPage = View::GAME;
    if (keys[int('g')] == true && viewPage == View::GAME) viewPage = View::INTRO;
    if (keys[int('x')] == true && viewPage == View::GAMEOVER) viewPage = View::GAMEOVER;

    // Testing zoom area keys
    if (keys[int('i')] == true && viewPage == View::GAME) {
        m_viewport[0] = 0; // X-coordinate of the lower left corner
        m_viewport[1] = 0; // Y-coordinate of the lower left corner
        m_viewport[2] = 800; // Width of the viewport
        m_viewport[3] = 600; // Height of the viewport
        glViewport(m_viewport[0], m_viewport[1], m_viewport[2], m_viewport[3]);
    }

    if (keys[int('o')] == true && viewPage == View::GAME) {
        m_viewport[0] = 0; // X-coordinate of the lower left corner
        m_viewport[1] = 0; // Y-coordinate of the lower left corner
        m_viewport[2] = 400; // Width of the viewport
        m_viewport[3] = 300; // Height of the viewport
        glViewport(m_viewport[0], m_viewport[1], m_viewport[2], m_viewport[3]);
    }

    if (viewPage == View::GAME) {
        std::cout << "# key " << key << " hold down" << std::endl;
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
        case 'q':
            tank1.shoot();
            break;
        case 'k': // ASCII code for Enter key
            tank2.shoot();
            break;
            /*
        case ' ':
            tank1.shoot();
            break;

        case 13: // ASCII code for Enter key
            tank2.shoot();
            break;
            */
            //key = " ";
        }
    }
}

void handleKeyPressUp(unsigned char key, int x, int y) {
    /*    switch (key) {
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
    }*/
    keys[key] = false;



    switch (key) {
    case 'w':
        tank1.moveLeftRelease();
        break;
    case 's':
        tank1.moveRightRelease();
        break;
    case 'a':
        tank1.moveUpRelease();
        break;
    case 'd':
        tank1.moveDownRelease();
        break;
        /*
    case ' ':
        tank1.shoot();
        break;
    case 13: // ASCII code for Enter key
        tank2.shoot();
        break;
        */
        //key = " ";
    }


}

void handleSpecialKeyPress(int key, int x, int y) {
    /*
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
    case 'q':
        tank1.shoot();
        break;
    case 'o': // ASCII code for Enter key
        tank2.shoot();
        break;
        */
    keys[key] = true;
    std::cout << "special key " << key << " hold down" << std::endl;

    if (keys[GLUT_KEY_LEFT])    tank2.moveLeft();
    if (keys[GLUT_KEY_RIGHT])   tank2.moveRight();
    if (keys[GLUT_KEY_UP])      tank2.moveUp();
    if (keys[GLUT_KEY_DOWN])    tank2.moveDown();

}

void handleSpecialKeyPressUp(int key, int x, int y)
{
    keys[key] = false;
    std::cout << "special key" << key << " released" << std::endl;

    if (!keys[GLUT_KEY_LEFT])   tank2.moveLeftRelease();
    if (!keys[GLUT_KEY_RIGHT])  tank2.moveRightRelease();
    if (!keys[GLUT_KEY_UP])     tank2.moveUpRelease();
    if (!keys[GLUT_KEY_DOWN])   tank2.moveDownRelease();
}

void passiveMotionFunc(int x, int y) {
    //when mouse is moving but not clicked

    mouseX = (float(x) * INIT_WINDOWS_SIZE_WEIGHT / glutGet(GLUT_WINDOW_WIDTH)) - (INIT_WINDOWS_SIZE_WEIGHT / 2);  //converting screen resolution to ortho 2d spec
    mouseY = (float(y) * INIT_WINDOWS_SIZE_HEIGHT / glutGet(GLUT_WINDOW_HEIGHT)) - (INIT_WINDOWS_SIZE_HEIGHT / 2);  //converting screen resolution to ortho 2d spec

    std::cout << "\
        Cursor: (" << x << ", " << y << ") \
        \t Windows : (" << glutGet(GLUT_WINDOW_WIDTH) << ", " << glutGet(GLUT_WINDOW_HEIGHT) << ")." << "\
        \t Ortohognal : (" << mouseX << ", " << mouseY << ")." << std::endl;

    //Do calculations to find value of LaserAngle
    glutPostRedisplay();
}

void mouseClick(int buttonPressed, int state, int x, int y) {
    std::cout << "Mouse clicked on: " << x << ", " << y << std::endl;

    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN) mButtonPressed = true;
    else mButtonPressed = false;

    // Game button action
    if (mouseX >= -260 && mouseX <= 260 && 
        mouseY >= -180 && mouseY <= -110) {
        glColor3f(1, 0, 0);
        displayRasterText(-30, 200, 0.4, "Start Game");
        if (mButtonPressed) {
            viewPage = View::GAME;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 0);

    // Exit button action
    if (mouseX >= -260 && mouseX <= 260 && 
        mouseY >= 40 && mouseY <= 110) {
        glColor3f(1, 0, 0);
        displayRasterText(-30, -100, 0.4, " Exit     ");
        if (mButtonPressed) {
            mButtonPressed = false;
            exit(0);
        }
    }
    else
        glColor3f(0, 0, 0);

    glutPostRedisplay();
}

void screenGame()
{
    //reset scaling values
    // glScalef(1 / 2, 1 / 2, 0);
    
    //Border
    glLineWidth(10);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-220, -300);
    glVertex2f(-220, 300);
    glVertex2f(220, +300);
    glVertex2f(220, -300);
    glEnd();

    glLoadIdentity();

    // Update tanks
    tank1.draw(); //tank1.update();
    tank2.draw(); //tank2.update();

    // Update projectiles
    Projectile::drawAll();

    glutPostRedisplay();


    //tank1 = new Tank("/Image/t34.png", 100, 100);
    //gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    //std::cout << "Direction tank2 X:" << tank2.getDirectionX() << ", " << tank2.getDirectionY() << std::endl;
    /*if (viewPage == View::GAME) {

    }*/
    glutSwapBuffers();
    //glFlush();
}
