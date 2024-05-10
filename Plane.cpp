/* plane.cpp */
/* #pragma once */
#include "Plane.h"
#include "Operate.h"


Plane::Plane()
{
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
    this->x = x;
    this->y = y;
    this->speed = speed;
    
}

Plane::Plane(int x, int y,int speed)
{
/*     // 绘制飞机的矩形身体
    setfillcolor(color);
    solidrectangle(x - 20, y, x + 20, y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                  // 设置引擎颜色为蓝色
    solidrectangle(x - 10, y + 30, x - 5, y + 40); // 左引擎
    solidrectangle(x + 5, y + 30, x + 10, y + 40); // 右引擎 */
}
void Plane::draw()
{
    // 绘制飞机的矩形身体
    setfillcolor(color);
    solidrectangle(this->x - 20, this->y, this->x + 20, this->y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                  // 设置引擎颜色为蓝色
    solidrectangle(this->x - 10, this->y + 30, this->x - 5, this->y + 40); // 左引擎
    solidrectangle(this->x + 5, this->y + 30, this->x + 10, this->y + 40); // 右引擎
}

void Plane::move(char key)
{
    switch (key)
    {
    case 'w':
    case 'W':
    case 72:
        if (y > 0)
            this->y -= this->speed;
        break;
    case 's':
    case 'S':
    case 80:
        if (y < 720)
            this->y += this->speed;
        break;
    case 'a':
    case 'A':
    case 75:
        if (x > 0)
            this->x -= this->speed;
        break;
    case 'd':
    case 'D':
    case 77:
        if (x < 1300)
            this->x += this->speed;
        break;
    default:
        break;
    }
}
int& Plane:: getX(){
    return x;
}
int& Plane:: getY()
{
    return y;
}
int& Plane:: getSpeed()
{
    return speed;
}

/* main.cpp */
#include <conio.h>
#include "Plane.h"
int main()
{
    initgraph(1360, 760); // 初始化图形窗口
    Plane *playerPlane = new Plane(680,380,5);    // 创建玩家飞机对象
    playerPlane->draw();
    while (1)
    {
        cleardevice();         // 清空画面
        playerPlane->draw();    // 绘制玩家飞机
        char key = _getch();   // 获取键盘输入
        playerPlane->move(key); // 移动玩家飞机
        playerPlane->draw();        
        Sleep(10);             // 等待一段时间，避免画面闪烁
    }
    _getch();
    closegraph(); // 关闭图形窗口
    return 0;
}
