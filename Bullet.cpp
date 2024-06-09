#include "Bullet.h"
#include <conio.h>
Bullet::Bullet() // 赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->harm = harm;
    loadimage(&bu1, "D:\\git0\\ace\\rs\\image\\bu1.png");
    loadimage(&bu12, "D:\\git0\\ace\\rs\\image\\bu12.png");
}
Bullet::Bullet(double x, double y, double speed, double i) // 赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->harm = harm;
    loadimage(&bu1, "D:\\git0\\ace\\rs\\image\\bu1.png");
    loadimage(&bu12, "D:\\git0\\ace\\rs\\image\\bu12.png");
    loadimage(&bu2, "D:\\git0\\ace\\rs\\image\\bu2.png");
    loadimage(&bu22, "D:\\git0\\ace\\rs\\image\\bu22.png");
}
void Bullet::drawBullet(double x, double y, int b) // 绘制子弹
{
    if (b == 0)
    {
        putimage(x - 5, y - 5, &bu1, SRCAND);
        putimage(x - 5, y - 5, &bu12, SRCPAINT);
    }
    else
    {
        putimage(x - 5, y - 5, &bu22, SRCAND);
        putimage(x - 5, y - 5, &bu2, SRCPAINT);
    }
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
double &Bullet::getSpeed() // 子弹速度
{
    return speed;
}
double &Bullet::getHarm() // 子弹伤害
{
    return harm;
}

void Bullet::setHarm(int s)//调整伤害
{
    if (s == 0)
    {
        harm = 1;
    }
    else
    {
        harm = 1 + 1 * s;
    }
}
