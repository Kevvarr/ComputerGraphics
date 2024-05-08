
#include "Main.h"


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //Tank tank1 = new Tank("/Image/t34.png", 100, 100);
    //Tank tank2 = new Tank("/Image/panzer.png", 500, 500);

    // Windows Config
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(INIT_WINDOWS_SIZE_WEIGHT, INIT_WINDOWS_SIZE_HEIGHT);
    //glutInitWindowPosition(0, 0);
    //glutInitWindowSize(1200, 900);
    glutCreateWindow("Tank Game");

    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(1.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        -(int)INIT_WINDOWS_SIZE_WEIGHT / 2,
        (int)INIT_WINDOWS_SIZE_WEIGHT/ 2,
        -(int)INIT_WINDOWS_SIZE_HEIGHT / 2,
        (int)INIT_WINDOWS_SIZE_HEIGHT / 2);
//  gluOrtho2D(-200,200,-200,200);
    glMatrixMode(GL_MODELVIEW);

    ///BackGround green color
    //glClearColor(0.0, 1.0, 0.0, 1.0);
    glClearColor((double)  7 / 255, 
                 (double) 63 / 255,
                 (double) 13 / 255, 1.0); // green background



    // Handle funtions
    //glutIdleFunc(refresh);

    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKeyPress);

    glutMouseFunc(mouseClick);
    glGetIntegerv(GL_VIEWPORT, m_viewport);
    glutPassiveMotionFunc(passiveMotionFunc);

    glutReshapeFunc(my_reshape);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    // Handle funtions
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyPressUp);
    glutSpecialFunc(handleSpecialKeyPress);
    glutSpecialUpFunc(handleSpecialKeyPressUp);

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
        //screenGame();
        //reset scaling values
        //glScalef(1 / 2, 1 / 2, 0);
        //tank1.draw();
        //tank2.draw();
        break;
    case View::GAMEOVER:
        //displayGameOverMessage();
        screenIntro();
        break;
    }



    glLoadIdentity();

    //tank1 = new Tank("/Image/t34.png", 100, 100);
    //gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    //std::cout << "Direction tank2 X:" << tank2.getDirectionX() << ", " << tank2.getDirectionY() << std::endl;
    /*if (viewPage == View::GAME) {
        
    }*/
    glutSwapBuffers();
    //glFlush();
}

void timer(int value) {
    /*
    // Update tanks

    //checkInput();

    */
    /*tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();*/
    

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Update every 16 milliseconds (about 60 fps)*/
}

void my_reshape(int  width, int  height)
{
    int aspect = width * 1.0f / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        -(int)INIT_WINDOWS_SIZE_HEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_HEIGHT / 2,
        -(int)INIT_WINDOWS_SIZE_WEIGHT / 2,
         (int)INIT_WINDOWS_SIZE_WEIGHT / 2);
    glMatrixMode(GL_MODELVIEW);
    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

void handleKeyPress(unsigned char key, int x, int y) {
    keys[key] = true;

    std::cout << "# key " << key << " released" << std::endl;
    std::cout << "# VIEW:  " << static_cast<std::underlying_type<View>::type>(viewPage) << "." << std::endl;
    std::cout << "# key status:  " << keys[13] << "." << std::endl;

    if (keys[13] == true && viewPage == View::INTRO) viewPage = View::MENU;
    if (keys[int('z')] == true && viewPage == View::MENU) viewPage = View::GAME;
    if (keys[int('x')] == true && viewPage == View::GAME) viewPage = View::INTRO;
    //if (keys[int('n')] == true && viewPage == MENU) viewPage = GAME;

    // Testing zoom area
    if (keys[int('i')] == true && viewPage == View::MENU) {
        m_viewport[0] = 0; // X-coordinate of the lower left corner
        m_viewport[1] = 0; // Y-coordinate of the lower left corner
        m_viewport[2] = 800; // Width of the viewport
        m_viewport[3] = 600; // Height of the viewport
        glViewport(m_viewport[0], m_viewport[1], m_viewport[2], m_viewport[3]);
    }

    if (keys[int('o')] == true && viewPage == View::MENU) {
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

    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}
