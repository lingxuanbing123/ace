#include <iostream>
#include <graphics.h>
#include <easyx.h>
using namespace std;
class Bullet
{
public:
   Bullet();
   Bullet(double x, double y, double speed, double i);
   void drawBullet(double x, double y, int b); // 绘制子弹
   void moveBullet();                          // 移动子弹
   double &getX();                             // 子弹坐标x
   double &getY();                             // 子弹坐标y
   double &getSpeed();                         // 子弹速度speed
   double &getHarm();                          // 获取伤害
   void setHarm(int s);                        // 改变伤害

protected:
   IMAGE bu1, bu12, bu2, bu22;
   double harm;

private:
   double x; // 子弹坐标
   double y;
   double speed; // 子弹速度
};