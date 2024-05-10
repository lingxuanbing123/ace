
/* plane.h */
#pragma once
#include <graphics.h>

class Plane
{
public:
    Plane(); // 构造函数
    Plane(int x, int y, int speed);
    void draw();         // 绘制飞机
    void move(char key); // 移动飞机，根据按键响应
    int &getX();
    int &getY();
    int &getSpeed();

private:
    COLORREF color = RGB(255, 0, 0); // 设置飞机颜色为红色; // 飞机颜色
    int x = 320, y = 380, speed = 8;

    /* protected:
        int x, y;  // 飞机坐标
        int speed; // 飞机速度 */
};
