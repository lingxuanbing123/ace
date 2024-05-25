#include "Bullet.h"
#include <conio.h>
Bullet::Bullet()        //赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}
Bullet::Bullet(double x, double y, double speed, double i)  //赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}
void Bullet::drawBullet(double x, double y) // 绘制子弹,己方子弹为蓝色实心圆
{
    setfillcolor(BLUE);
    solidcircle(x, y, 5);
}
void Bullet::moveBullet() // 移动子弹,己方子弹只往上移动
{
    this->y -= this->speed;
}
double &Bullet::getX() // 子弹坐标
{
    return x;
}
double &Bullet::getY()
{
    return y;
}
double &Bullet::getSpeed() // 子弹速度，参考速度为1
{
    return speed;
}
double &Bullet::getI()  //子弹半径，v2应替换为贴图
{
    return i;
}
