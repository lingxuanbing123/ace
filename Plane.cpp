

#include "Plane.h"

Plane::Plane() // 飞机获取相关参数
{
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
    this->x = x;
    this->y = y;
    this->speed = speed;
}

Plane::Plane(int x, int y, int speed) // 从飞机获取相关参数
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}
void Plane::draw()
{
    // 绘制飞机的矩形身体
    setfillcolor(color);
    solidrectangle(this->x - 20, this->y, this->x + 20, this->y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                                          // 设置引擎颜色为蓝色
    solidrectangle(this->x - 10, this->y + 30, this->x - 5, this->y + 40); // 左引擎
    solidrectangle(this->x + 5, this->y + 30, this->x + 10, this->y + 40); // 右引擎
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
        if (y < 800)
            this->y += speed;
    }
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
    {
        if (x > 0)
            this->x -= speed;
    }
    if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
    {
        if (x < 640)
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
    speed+=2;
    return speed;
}