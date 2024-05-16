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
    //glutPostRedisplay();
    glutSwapBuffers();
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

    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);				//START GAME PLOYGON
    glVertex2f(-200, +250);
    glVertex2f(-200, +150);
    glVertex2f(+200, +150);
    glVertex2f(+200, +250);
    glEnd();

    /*
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);				//OPTION POLYGON
    glVertex2f(-200, +100);
    glVertex2f(-200, +0);
    glVertex2f(+200, +0);
    glVertex2f(+200, +100);
    glEnd();*/

    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);				//QUIT POLYGON
    glVertex2f(-200, -50);
    glVertex2f(-200, -150);
    glVertex2f(200, -150);
    glVertex2f(200, -50);
    glEnd();

    glColor3f(0, 0, 1);
    displayRasterText(-30, 200, 0.4,  "Start Game");
    //displayRasterText(-30, 50, 0.4,   " Options  ");
    displayRasterText(-30, -100, 0.4, " Exit     ");
   
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

