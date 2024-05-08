
#include "Main.h"
#include "GlobalDeclarations.h"

void passiveMotionFunc(int x, int y) {

    //when mouse not clicked
    mouseX = float(x) / (m_viewport[2] / 1200.0) - 600.0;  //converting screen resolution to ortho 2d spec
    mouseY = -(float(y) / (m_viewport[3] / 700.0) - 350.0);

    std::cout << x << ", " << y << "/" << mouseX << ", " << mouseY << std::endl;

    //Do calculations to find value of LaserAngle
    //somethingMovedRecalculateLaserAngle();
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

void introScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-425, 490, 0.0, "NMAM INSTITUTE OF TECHNOLOGY");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-700, 385, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(0.0, 0.0, 1.0);
    displayRasterText(-225, 300, 0.0, "A MINI PROJECT ON ");
    glColor3f(1.0, 0.0, 1.0);
    displayRasterText(-125, 225, 0.0, "Space Shooter");
    glColor3f(1.0, 0.7, 0.8);
    displayRasterText(-100, 150, 0.0, "created by");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-130, 80, 0.0, "SHOOTERS");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-800, -100, 0.0, " STUDENT NAMES");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-800, -200, 0.0, " Saurav N Shetty");
    displayRasterText(-800, -285, 0.0, " Rajath R Pai");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(500, -100, 0.0, "Under the Guidance of");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(500, -200, 0.0, "Prof X");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-250, -400, 0.0, "Academic Year 2020-2021");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-300, -550, 0.0, "Press ENTER to start the game");
    glFlush();
    //glutSwapBuffers();
}



void mouseClick(int buttonPressed, int state, int x, int y) {
    std::cout << "Cursor: " << x << ", " << y << std::endl;

    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}


void startScreenDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(10);
    //SetDisplayMode(MENU_SCREEN);

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);               //Border
    glVertex2f(-750, -500);
    glVertex2f(-750, 550);
    glVertex2f(750, 550);
    glVertex2f(750, -500);
    glEnd();

    glLineWidth(1);

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);				//START GAME PLOYGON
    glVertex2f(-200, 300);
    glVertex2f(-200, 400);
    glVertex2f(200, 400);
    glVertex2f(200, 300);
    glEnd();

    glBegin(GL_POLYGON);				//INSTRUCTIONS POLYGON
    glVertex2f(-200, 50);
    glVertex2f(-200, 150);
    glVertex2f(200, 150);
    glVertex2f(200, 50);
    glEnd();

    glBegin(GL_POLYGON);				//QUIT POLYGON
    glVertex2f(-200, -200);
    glVertex2f(-200, -100);
    glVertex2f(200, -100);
    glVertex2f(200, -200);
    glEnd();
    
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
    glutPostRedisplay();
}

void refresh() {
    glutPostRedisplay();
}

void gameScreenDisplay()
{
    // Update tanks
    tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 fps)

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //Tank tank1 = new Tank("/Image/t34.png", 100, 100);
    //Tank tank2 = new Tank("/Image/panzer.png", 500, 500);

    // Windows Config
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //glutInitWindowSize(800, 600);
    //glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 900);
    glutCreateWindow("Tank Game");

    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1200, 1200, -700, 700);                   //<-----CHANGE THIS TO GET EXTRA SPACE
//  gluOrtho2D(-200,200,-200,200);
    glMatrixMode(GL_MODELVIEW);

    ///BackGround green color
    glClearColor(0.0, 1.0, 0.0, 1.0);



    // Handle funtions
    glutIdleFunc(refresh);

    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKeyPress);

    glutMouseFunc(mouseClick);
    glGetIntegerv(GL_VIEWPORT, m_viewport);
    glutPassiveMotionFunc(passiveMotionFunc);

    glutReshapeFunc(my_reshape);
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (viewPage)
    {
    case INTRO:
        introScreen();
        break;
    case MENU:
        startScreenDisplay();
        break;
    case INSTRUCTIONS:
        //instructionsScreenDisplay();
        break;
    case GAME:
        gameScreenDisplay();
        //reset scaling values
        glScalef(1 / 2, 1 / 2, 0);
        break;
    case GAMEOVER:
        //displayGameOverMessage();
        startScreenDisplay();
        break;
    }

    glLoadIdentity();

    //tank1 = new Tank("/Image/t34.png", 100, 100);
    //gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    tank1.draw();
    tank2.draw();

    glutSwapBuffers();
    //glFlush();
}

void update(int value) {
    /*
    // Update tanks
    tank1.update();
    tank2.update();

    // Update projectiles
    Projectile::updateAll();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Update every 16 milliseconds (about 60 fps)*/
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
