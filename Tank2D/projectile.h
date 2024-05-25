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
    void destroy(Projectile);
    int x, y;
    bool kill = false;

private:
    int directionX, directionY;
    int speed = 10;
    int size = 5;
    int counterTimerMax = 50;
    int counterTimerKill = 0;
    int counterTimer = 0;
    bool alive = true;
    
};

#endif // PROJECTILE_H
