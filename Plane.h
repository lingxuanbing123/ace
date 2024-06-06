#pragma once
#include <graphics.h>

class Plane
{
public:
    Plane(); // 构造函数
    Plane(int x, int y, int speed);
    bool invincible = false; // 己方飞机是否处于无敌状态
    bool isColliding(int x1, int y1, int r, int x, int y);  //判定
    void playerPlane_accelerator(bool z); // 加速
    void playerPlane_shield(bool z);  //护盾
    void draw1();         // 绘制飞机1
    void draw2();         // 绘制飞机2 
    void move(char key); // 移动飞机，根据按键响应
    int &getX();        // 获取x
    int &getY();        // 获取y
    int &getSpeed();    // 获取speed
    int &setSpeed();
    bool &getinvincible();
    void setinvincible(bool z);

protected:
    IMAGE plane1,
        plane12,
        plane2,
        plane22,
        dun1,
        dun2;

private:
    int x = 320, y = 380, speed = 12;
};
