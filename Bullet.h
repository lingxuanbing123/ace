#include <iostream>
#include <graphics.h>
#include <easyx.h>
using namespace std;
class Bullet
{
public:
   Bullet();
   Bullet(double x, double y, double speed, double i);
   void drawBullet(double x,double y); //绘制子弹
   void moveBullet(); //移动子弹
   double& getX();
   double& getY();
   double& getSpeed();
   double& getI();
private:
   double x; //子弹坐标
   double y;
   double speed; //子弹速度
   double i; //子弹半径
};