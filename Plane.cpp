#include "Plane.h"
#include <stdio.h>
#include "Prop.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Game.h"

/* auto hitTime = std::chrono::steady_clock::now(); // 记录时间
void Plane::playerPlane_accelerator(bool z)          //加速效果：移速增加
{
    if(this->speed<=20)
    setSpeed();
} */
/* void Plane::playerPlane_shield(bool z) // 护盾效果：五秒无敌
{
    while (true)
    {
        invincible = true;             // 己方飞机被击中，进入无敌状态
        hitTime = std::chrono::steady_clock::now(); // 更新被击中时间
        if (invincible)
        {
            auto now = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - hitTime);
            if (duration.count() >= 5)
            {
                invincible = false; // 超过5秒，取消己方飞机的无敌状态
            }
        }
    }
} */
Plane::Plane() // 飞机获取相关参数
{
    /*     color = RGB(255, 0, 0); // 设置飞机颜色为红色 */
    this->x = x;
    this->y = y;
    this->speed = speed;
    loadimage(&plane1, "D:\\git0\\ace\\rs\\image\\1.png");
    loadimage(&plane12, "D:\\git0\\ace\\rs\\image\\12.png");
}

Plane::Plane(int x, int y, int speed) // 从飞机获取相关参数
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    loadimage(&plane1, "D:\\git0\\ace\\rs\\image\\1.png");
    loadimage(&plane12, "D:\\git0\\ace\\rs\\image\\12.png");
}
void Plane::draw()
{
    // 绘制飞机的矩形身体
    /*     setfillcolor(color); */
    /*     solidrectangle(this->x - 20, this->y, this->x + 20, this->y + 30);

        // 绘制飞机的两个引擎
        setfillcolor(RGB(0, 0, 255));                                          // 设置引擎颜色为蓝色
        solidrectangle(this->x - 10, this->y + 30, this->x - 5, this->y + 40); // 左引擎
        solidrectangle(this->x + 5, this->y + 30, this->x + 10, this->y + 40); // 右引擎 */
    putimage(this->x, this->y, &plane12, SRCAND);
    putimage(this->x, this->y, &plane1, SRCPAINT);
}

void Plane::move(char key) // 移动相关函数，后续如有必要可改成其他方式
{
    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
    {
        if (y > 0)
            this->y -= speed;
    }
    if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
    {
        if (y < 760)
            this->y += speed;
    }
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
    {
        if (x > 0)
            this->x -= speed;
    }
    if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
    {
        if (x < 600)
            this->x += speed;
    }
}

int &Plane::getX()
{
    return x;
}
int &Plane::getY()
{
    return y;
}
int &Plane::getSpeed()
{
    return speed;
}
int &Plane::setSpeed()
{
    speed += 2;
    return speed;
}
bool &Plane::getinvincible(){
    return invincible;
}
void Plane::setinvincible(bool z){
        invincible = z;
}