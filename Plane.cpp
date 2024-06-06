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

Plane::Plane() // 飞机获取相关参数
{
    /*     color = RGB(255, 0, 0); // 设置飞机颜色为红色 */
    this->x = x;
    this->y = y;
    this->speed = speed;
    loadimage(&plane1, "D:\\git0\\ace\\rs\\image\\1.png");
    loadimage(&plane12, "D:\\git0\\ace\\rs\\image\\12.png");
    loadimage(&dun1, "D:\\git0\\ace\\rs\\image\\dun1.png");
    loadimage(&dun2, "D:\\git0\\ace\\rs\\image\\dun2.png");
    loadimage(&plane2, "D:\\git0\\ace\\rs\\image\\2.png");
    loadimage(&plane22, "D:\\git0\\ace\\rs\\image\\22.png");
}

Plane::Plane(int x, int y, int speed) // 从飞机获取相关参数
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    loadimage(&plane1, "D:\\git0\\ace\\rs\\image\\1.png");
    loadimage(&plane12, "D:\\git0\\ace\\rs\\image\\12.png");
    loadimage(&dun1, "D:\\git0\\ace\\rs\\image\\dun1.png");
    loadimage(&dun2, "D:\\git0\\ace\\rs\\image\\dun2.png");
    loadimage(&plane2, "D:\\git0\\ace\\rs\\image\\2.png");
    loadimage(&plane22, "D:\\git0\\ace\\rs\\image\\22.png");
}
 void Plane::draw1()
{
    putimage(this->x, this->y, &plane12, SRCAND);
    putimage(this->x, this->y, &plane1, SRCPAINT);
    if (invincible)
    {
        putimage(this->x, this->y, &dun2, SRCAND);
        putimage(this->x, this->y, &dun1, SRCPAINT);
    }
}
void Plane::draw2()
{
    putimage(this->x, this->y, &plane22, SRCAND);
    putimage(this->x, this->y, &plane2, SRCPAINT);
    if (invincible) {
        putimage(this->x, this->y, &dun2, SRCAND);
        putimage(this->x, this->y,&dun1, SRCPAINT);
    }

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