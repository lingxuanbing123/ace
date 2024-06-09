#include  "BulletEnemy.h"
BulletEnemy::BulletEnemy(int x, double y,double speed,int i)
{
    this->x=x;
    this->y=y;
    this->speed=speed;
}
void BulletEnemy::drawBulletEnemy(double x,double y) //绘制子弹,敌方子弹为红色实心圆
{
    setfillcolor(RED);
    solidcircle(x, y, 5);
}
void BulletEnemy::moveBulletEnemy() //移动子弹,敌方子弹只往下移动
{
    this->y+=this->speed;  
}
int& BulletEnemy::getX() //子弹坐标
{
    return x;
}
double& BulletEnemy::getY()
{
    return y;
}
double& BulletEnemy::getSpeed() //子弹速度
{
    return speed;
}
int& BulletEnemy::getI()
{
    return i;
} 