/* plane.h */
#pragma once
#include <graphics.h>

class Plane
{
public:
    int x = 650, y = 720; // 飞机初始坐标
    int speed = 10;       // 飞机移动速度

    Plane();                 // 构造函数
    void draw();             // 绘制飞机
    void move(char key_hit); // 移动飞机，根据按键响应

private:
    COLORREF color; // 飞机颜色
};
