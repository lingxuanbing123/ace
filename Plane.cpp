
#include "Plane.h"

Plane::Plane()
{
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
    this->x = x;
    this->y = y;
    this->speed = speed;
}

Plane::Plane(int x, int y, int speed)
{
    /*     // 绘制飞机的矩形身体
        setfillcolor(color);
        solidrectangle(x - 20, y, x + 20, y + 30);

        // 绘制飞机的两个引擎
        setfillcolor(RGB(0, 0, 255)); // 设置引擎颜色为蓝色
        solidrectangle(x - 10, y + 30, x - 5, y + 40); // 左引擎
        solidrectangle(x + 5, y + 30, x + 10, y + 40); // 右引擎 */
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
        if (y < 800)
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
        if (x < 640)
            this->x += this->speed;
        break;
    default:
        break;
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

