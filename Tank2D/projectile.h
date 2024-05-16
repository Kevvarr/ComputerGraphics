#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>


class Projectile {
public:
    static void create(int x, int y, int directionX, int directionY);
    static void drawAll();
    static void updateAll();
    static void updateAlive();
    void draw();
    void destroy(Projectile);

private:
    int x, y;
    int directionX, directionY;
    int speed = 10;
    int size = 5;
    int counterTimerMax = 50;
    int counterTimer = 0;
    bool alive = true;
};

#endif // PROJECTILE_H
