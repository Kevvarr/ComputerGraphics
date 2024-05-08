
#include "Main.h"


void passiveMotionFunc(int x, int y) {
    //when mouse is moving but not clicked

    mouseX = (float(x) * INIT_WINDOWS_SIZE_WEIGHT / glutGet(GLUT_WINDOW_WIDTH)) - (INIT_WINDOWS_SIZE_WEIGHT / 2);  //converting screen resolution to ortho 2d spec
    mouseY = (float(y) * INIT_WINDOWS_SIZE_HEIGHT / glutGet(GLUT_WINDOW_HEIGHT)) - (INIT_WINDOWS_SIZE_HEIGHT/ 2);  //converting screen resolution to ortho 2d spec

    std::cout << "\
        Cursor: (" << x << ", " << y << ") \
        \t Windows : (" << glutGet(GLUT_WINDOW_WIDTH) << ", " << glutGet(GLUT_WINDOW_HEIGHT) << ")." << "\
        \t Ortohognal : (" << mouseX << ", " << mouseY << ")." << std::endl;

    //Do calculations to find value of LaserAngle
    glutPostRedisplay();
}


void displayRasterText(float x, float y, float z, std::string stringToDisplay) {
    glRasterPos3f(x, y, z);

    // Traverse the string 
    for (auto& ch : stringToDisplay) {

        // Print current character 
        //cout << ch << " ";
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (char)ch);
    }
    /*
    for (char* c = stringToDisplay; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }*/
}

void mouseClick(int buttonPressed, int state, int x, int y) {
    std::cout << "Mouse clicked on: " << x << ", " << y << std::endl;

    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}

void screenIntro()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-50, 250, 0.0, "Tank 2d");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-150, -250, 0.0, "Press ENTER to start the game");
    
    //glFlush();
    
    glutPostRedisplay();
    //glutSwapBuffers();
}

void screenMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(10);
    //SetDisplayMode(MENU_SCREEN);

    //Border
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);               
    glVertex2f(-400, -300);
    glVertex2f(-400, 300);
    glVertex2f(400, +300);
    glVertex2f(400, -300);
    glEnd();

    glLineWidth(1);

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);				//START GAME PLOYGON
    glVertex2f(-200, +250);
    glVertex2f(-200, +150);
    glVertex2f(+200, +150);
    glVertex2f(+200, +250);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);				//INSTRUCTIONS POLYGON
    glVertex2f(-200, +100);
    glVertex2f(-200, +0);
    glVertex2f(+200, +0);
    glVertex2f(+200, +100);
    glEnd();

    glBegin(GL_POLYGON);				//QUIT POLYGON
    glVertex2f(-200, -50);
    glVertex2f(-200, -150);
    glVertex2f(200, -150);
    glVertex2f(200, -50);
    glEnd();

    displayRasterText(-300, -200, 0.0, "Screen MENU");

    
    if (mouseX >= -200 && mouseX <= 200 && mouseY >= 150 && mouseY <= 250) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            //alienLife1 = alienLife2 = 100;
            viewPage = GAME;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(0, 0, 0);

    displayRasterText(-100, 340, 0.4, "Start Game");
    /*
    if (mouseX >= -100 && mouseX <= 100 && mouseY >= 30 && mouseY <= 80) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = INSTRUCTIONS;
            printf("button pressed bitch\n");
            mButtonPressed = false;
        }
    }
    else
        glColor3f(0, 0, 0);
    displayRasterText(-120, 80, 0.4, "Instructions");

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -90 && mouseY <= -40) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            mButtonPressed = false;
            exit(0);
        }
    }
    else
        glColor3f(0, 0, 0);
    displayRasterText(-100, -170, 0.4, "    Quit");

    
    if (mouseX >= -100 && mouseX <= 100 && mouseY >= 150 && mouseY <= 200) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            //alienLife1 = alienLife2 = 100;
            viewPage = GAME;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(0, 0, 0);

    displayRasterText(-100, 340, 0.4, "Start Game");

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= 30 && mouseY <= 80) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = INSTRUCTIONS;
            printf("button pressed bitch\n");
            mButtonPressed = false;
        }
    }
    else
        glColor3f(0, 0, 0);
    displayRasterText(-120, 80, 0.4, "Instructions");

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -90 && mouseY <= -40) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            mButtonPressed = false;
            exit(0);
        }
    }
    else
        glColor3f(0, 0, 0);
    displayRasterText(-100, -170, 0.4, "    Quit");

    */
    glutPostRedisplay();
}

void screenGame()
{
    displayRasterText(-300, -200, 0.0, "Starting Game");

    /*
    // Update tanks
    tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();
    */
    glutPostRedisplay();
}

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
    glClearColor((double)  0 / 255, 
                 (double)149 / 255,
                 (double) 49 / 255, 1.0); // green background



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
    case INTRO:
        screenIntro();
        //std::cout << "INTRO MODE" << std::endl;
        break;
    case MENU:
        screenMenu();
        break;
    case GAME:
        screenGame();
        //reset scaling values
        //glScalef(1 / 2, 1 / 2, 0);
        break;
    case GAMEOVER:
        //displayGameOverMessage();
        screenIntro();
        break;
    }

    glLoadIdentity();

    //tank1 = new Tank("/Image/t34.png", 100, 100);
    //gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    //std::cout << "Direction tank2 X:" << tank2.getDirectionX() << ", " << tank2.getDirectionY() << std::endl;


    tank1.draw();
    tank2.draw();

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
    std::cout << "# VIEW:  " << viewPage << "." << std::endl;
    std::cout << "# key status:  " << keys[13] << "." << std::endl;

    if (keys[13] == true && viewPage == INTRO) viewPage = MENU;
    if (keys[int('z')] == true && viewPage == MENU) viewPage = GAME;
    if (keys[int('x')] == true && viewPage == GAME) viewPage = INTRO;
    //if (keys[int('n')] == true && viewPage == MENU) viewPage = GAME;

    // Testing zoom area
    if (keys[int('+')] == true && viewPage == MENU) {
        m_viewport[0] = 0; // X-coordinate of the lower left corner
        m_viewport[1] = 0; // Y-coordinate of the lower left corner
        m_viewport[2] = 800; // Width of the viewport
        m_viewport[3] = 600; // Height of the viewport
        glViewport(m_viewport[0], m_viewport[1], m_viewport[2], m_viewport[3]);
    }

    if (keys[int('-')] == true && viewPage == MENU) {
        m_viewport[0] = 0; // X-coordinate of the lower left corner
        m_viewport[1] = 0; // Y-coordinate of the lower left corner
        m_viewport[2] = 400; // Width of the viewport
        m_viewport[3] = 300; // Height of the viewport
        glViewport(m_viewport[0], m_viewport[1], m_viewport[2], m_viewport[3]);
    }

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
