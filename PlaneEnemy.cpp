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
    loadimage(&planeEnemy1, "D:\\Git warehouse\\github\\ace\\rs\\image\\3.png");
    loadimage(&planeEnemy12, "D:\\Git warehouse\\github\\ace\\rs\\image\\32.png");
    loadimage(&planeEnemy2, "D:\\Git warehouse\\github\\ace\\rs\\image\\4.png");
    loadimage(&planeEnemy22, "D:\\Git warehouse\\github\\ace\\rs\\image\\42.png");
}

PlaneEnemy::PlaneEnemy(double x, double y, double speed,int m)  
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->m = m;
    loadimage(&planeEnemy1, "D:\\git0\\ace\\rs\\image\\3.png");
    loadimage(&planeEnemy12, "D:\\git0\\ace\\rs\\image\\32.png");
    loadimage(&planeEnemy2, "D:\\git0\\ace\\rs\\image\\4.png");
    loadimage(&planeEnemy22, "D:\\git0\\ace\\rs\\image\\42.png");
}
void PlaneEnemy::draw(int m)
{
    switch (m)          
    {
        case 1:
            putimage(this->x, this->y, &planeEnemy12, SRCAND);
            putimage(this->x, this->y, &planeEnemy1, SRCPAINT);
            break;
        case 2:
            putimage(this->x, this->y, &planeEnemy22, SRCAND);
            putimage(this->x, this->y, &planeEnemy2, SRCPAINT);
            break;
        case 3:
            setfillcolor(RGB(128, 128, 128));
            solidcircle(this->x+23,this-> y+20, 20);
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

double PlaneEnemy::getHealth() const 
{ 
    switch(m){
        case 1:
            return health1;
        case 2:
            return health2;
        case 3:
            return 1;
    }
}

void PlaneEnemy::setHealth(double newHealth) 
{ 
    if (newHealth >= 0) health1 = newHealth;
    if (newHealth >= 0) health2 = newHealth;
}







//敌机BOSS
EnemyBoss::EnemyBoss()        
{
	color = RGB(0,255,0); 
    this->x = x;
    this->y = y;
    loadimage(&planeEnemy3, "D:\\git0\\ace\\rs\\image\\5.png");
    loadimage(&planeEnemy32, "D:\\git0\\ace\\rs\\image\\52.png");
}

EnemyBoss::EnemyBoss(double x, double y)  
{
    this->x = x;
    this->y = y;
    loadimage(&planeEnemy3, "D:\\git0\\ace\\rs\\image\\5.png");
    loadimage(&planeEnemy32, "D:\\git0\\ace\\rs\\image\\52.png");
}
void EnemyBoss::draw()
{

    putimage(this->x, this->y, &planeEnemy32, SRCAND);
    putimage(this->x, this->y, &planeEnemy3, SRCPAINT);

}
double &EnemyBoss::getX()  
{
    return x;
}
double &EnemyBoss::getY()
{
    return y;
}
int EnemyBoss::getHealth() const 
{ 
    return health;
}

void EnemyBoss::setHealth(int newHealth) 
{ 
     health = newHealth; 
}
