#include "Menu.h"

void screenIntro()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(\
        (double)7 / 255,
        (double)63 / 255,
        (double)13 / 255, 1.0); // green background
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
    glVertex2f(-220, -300);
    glVertex2f(-220, 300);
    glVertex2f(220, +300);
    glVertex2f(220, -300);
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



 

    displayRasterText(-30, 200, 0.4,  "Start Game");
    displayRasterText(-30, 50, 0.4,   " Options  ");
    displayRasterText(-30, -100, 0.4, " Exit     ");
    displayRasterText(-200, -200, 0.0, "Screen MENU");

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

