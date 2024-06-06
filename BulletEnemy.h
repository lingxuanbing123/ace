// 未来得及采用的敌机子弹方案，v2需完善

#include <iostream>
#include <graphics.h>
#include <easyx.h>
#include <list>
using namespace std;
class BulletEnemy
{
public:
   BulletEnemy();
   BulletEnemy(int x, double y, double speed, int i);
   void drawBulletEnemy(double x,double y); //绘制子弹
   void moveBulletEnemy(); //移动子弹
   int& getX();
   double& getY();
   double& getSpeed();
   int& getI();
protected:
   int x; //子弹坐标
   double y;
   double speed; //子弹速度
   int i; //子弹半径
};
