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
    void draw();         // 绘制飞机
    void move(char key); // 移动飞机，根据按键响应
    int &getX();        // 获取x
    int &getY();        // 获取y
    int &getSpeed();    // 获取speed
    int &setSpeed();
    bool &getinvincible();

protected:
    IMAGE plane1,plane12, plane2,plane22;    
private:
/*     COLORREF color = RGB(255, 0, 0); // 设置飞机颜色为红色; // 飞机颜色 */
    int x = 320, y = 380, speed = 12;
    /* protected:
        int x, y;  // 飞机坐标
        int speed; // 飞机速度 */
        
};
