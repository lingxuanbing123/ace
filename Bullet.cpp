#include "Bullet.h"
#include <conio.h>
Bullet::Bullet()        //赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->harm = harm;
    loadimage(&bu1, "D:\\git0\\ace\\rs\\image\\bu1.png");
    loadimage(&bu12, "D:\\git0\\ace\\rs\\image\\bu12.png");
}
Bullet::Bullet(double x, double y, double speed, double i)  //赋予子弹xys，或将子弹xys获取
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->harm = harm;
    loadimage(&bu1, "D:\\git0\\ace\\rs\\image\\bu1.png");
    loadimage(&bu12, "D:\\git0\\ace\\rs\\image\\bu12.png");
}
void Bullet::drawBullet(double x, double y) // 绘制子弹,己方子弹为蓝色实心圆
{
    putimage(x-5, y-5, &bu12, SRCAND);
    putimage(x-5, y-5, &bu1, SRCPAINT);
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
double &Bullet::getHarm()  //子弹半径，v2应替换为贴图
{
    return harm;
}

void Bullet::setHarm(int s){
    if(s == 0){
        harm = 1;
    }
    else{
         harm = 1+1*s;
    }
}
