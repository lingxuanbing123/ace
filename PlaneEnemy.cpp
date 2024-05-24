#include "PlaneEnemy.h"
#include <graphics.h>
#include <conio.h>
PlaneEnemy::PlaneEnemy()        //敌机获取相关参数
{
	color = RGB(0,255,0); // 设置飞机颜色为绿色
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->m = m;
}
PlaneEnemy::PlaneEnemy(double x, double y, double speed,int m)  //获取敌机参数
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->m = m;            //用来区分敌机种类
}
void PlaneEnemy::draw(int m)
{
    switch (m)          //根据m绘制不同敌机
    {
        case 1:
    setfillcolor(color);
    solidrectangle(this->x + 20, this->y,this-> x - 20, this->y - 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                  // 设置引擎颜色为蓝色
    solidrectangle(this ->x + 10, this->y  - 30, this ->x + 5, this->y - 40); // 左引擎
    solidrectangle(this ->x  - 5, this ->y - 30, this ->x - 10,this-> y - 40); // 右引擎
    break;
    case 2:
        setfillcolor(RGB(128, 128, 128));
        solidcircle(x, y, 20);
        break;
    case 3:
        setfillcolor(YELLOW);
        solidcircle(x, y, 10);
        break;
    }
}
void PlaneEnemy::move()     //敌机移动（v2需根据m值进行不同的设定）
{
    this->y += (this->speed)/25;
}
double &PlaneEnemy::getX()  
{
    return x;
}
double &PlaneEnemy::getY()
{
    return y;
}
int &PlaneEnemy::getM()
{
    return m;
}
double &PlaneEnemy::getSpeed()
{
    return speed;
}

Meteorite::Meteorite()
{
    color = RGB(128,128,128);   // 设置陨石颜色为灰色
    this->mx = mx;
    this->my = my;
    this->speed = speed;
}
Meteorite::Meteorite(double mx, double my, double speed)
{
    color = RGB(128, 128, 128); // 设置陨石颜色为灰色
    this->mx = mx;
    this->my = my;
    this->speed = speed;
}
void Meteorite::draw_meteorite()
{
    setfillcolor(color);
    circle(mx, my, 20);
}

void Meteorite::meteoriteMove()
{
    this->my += (this->speed) / 5;
}
double &Meteorite::getMX()
{
    return mx;
}
double &Meteorite::getMY()
{
    return my;
}
double &Meteorite::getMSpeed()
{
    return speed;
}