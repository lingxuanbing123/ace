#include "PlaneEnemy.h"
#include <graphics.h>
#include <conio.h>

PlaneEnemy::PlaneEnemy()        
{
	color = RGB(0,255,0); 
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->m = m;
}

PlaneEnemy::PlaneEnemy(double x, double y, double speed,int m)  
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->m = m;           
}
void PlaneEnemy::draw(int m)
{
    switch (m)          
    {
        case 1:
    setfillcolor(color);
    solidrectangle(this->x + 20, this->y,this-> x - 20, this->y - 30);

    setfillcolor(RGB(0, 0, 255));                 
    solidrectangle(this ->x + 10, this->y  - 30, this ->x + 5, this->y - 40); 
    solidrectangle(this ->x  - 5, this ->y - 30, this ->x - 10,this-> y - 40); 
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

void PlaneEnemy::move()    
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

    color = RGB(128,128,128);   
    this->mx = mx;
    this->my = my;
    this->speed = speed;
}
Meteorite::Meteorite(double mx, double my, double speed)
{

    color = RGB(128, 128, 128);
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