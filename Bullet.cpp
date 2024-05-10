#include  "Bullet.h"
Bullet::Bullet()
{

}
Bullet::Bullet(int x, int y,int speed,int i)
{
    this->x=x;
    this->y=y;
    this->speed=speed;

}
void Bullet::drawBullet() //绘制子弹,己方子弹为蓝色实心圆
{
    setfillcolor(BLUE);
	solidcircle(x, y, i);
}
void Bullet::moveBullet() //移动子弹,己方子弹只往上移动
{
 this->y-=this->speed;  
}
int& Bullet::getX() //子弹坐标
{
    return x;
}
int& Bullet::getY()
{
    return y;
}
int& Bullet::getSpeed() //子弹速度，参考速度为1
{
    return speed;
}
int& Bullet::getI()
{
    return i;
}