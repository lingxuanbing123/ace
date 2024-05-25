// 未来得及采用的敌机子弹方案，v2需完善

#include <iostream>
#include <graphics.h>
#include <easyx.h>
using namespace std;
class BulletEnemy
{
public:
   BulletEnemy();
   BulletEnemy(int x, int y, int speed, int i);
   void drawBulletEnemy(); //绘制子弹
   void moveBulletEnemy(); //移动子弹
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