#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>


class Projectile {
public:
    static void create(int x, int y, int directionX, int directionY);
    static void drawAll();
    static void updateAll();
    void draw();

private:
    int x, y;
    int directionX, directionY;
    int speed = 10;
    int size = 5;
};

#endif // PROJECTILE_H
