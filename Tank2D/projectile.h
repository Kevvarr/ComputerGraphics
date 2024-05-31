#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <vector>


class Projectile {
public:
    static std::vector<Projectile> getProjectiles();
    static void create(int x, int y, int directionX, int directionY);
    static void drawAll();
    static void updateAll();
    static void updateAlive();
    static void collisionDetectionAll();
    void detection();
    void draw();
    int x, y;
    bool kill = false;
    bool alive = true;

private:
    int directionX, directionY;
    int speed = 10;
    int size = 5;
    int counterTimerMax = 50;
    int counterTimerKill = 0;
    int counterTimer = 0;
    
    
};

#endif // PROJECTILE_H
