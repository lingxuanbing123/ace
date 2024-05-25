#include  "BulletEnemy.h"
BulletEnemy::BulletEnemy(int x, int y,int speed,int i)
{
    this->x=x;
    this->y=y;
    this->speed=speed;
}
void BulletEnemy::drawBulletEnemy() //绘制子弹,敌方子弹为红色实心圆
{
    setfillcolor(RED);
    solidcircle(x, y, i);
}
void BulletEnemy::moveBulletEnemy() //移动子弹,敌方子弹只往下移动
{
 this->y+=this->speed;  
}
int& BulletEnemy::getX() //子弹坐标
{
    return x;
}
int& BulletEnemy::getY()
{
    return y;
}
int& BulletEnemy::getSpeed() //子弹速度，参考速度为1
{
    return speed;
}
int& BulletEnemy::getI()
{
    return i;
} 