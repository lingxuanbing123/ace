#include <iostream>
#include <graphics.h>
#include <easyx.h>
using namespace std;
class Bullet
{
public:
   Bullet();
   Bullet(int x, int y, int speed, int i);
   void drawBullet(int x,int y); //绘制子弹
   void moveBullet(); //移动子弹
   int& getX();
   int& getY();
   int& getSpeed();
   int& getI();
protected:
   int x; //子弹坐标
   int y;
   int speed; //子弹速度
   int i; //子弹半径
};