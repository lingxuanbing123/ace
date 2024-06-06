#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	PlaneEnemy();
	PlaneEnemy(double x, double y, double speed, int m);
	void draw(int m);
	void move();
	double &getX();
	double &getY();
	int &getM();
	double &getSpeed();
	double getHealth() const;	   // ?
	void setHealth(double health); // ?
	double health1 = 4;			   //       ????4
	int health2 = 4;
protected:
	IMAGE planeEnemy1, planeEnemy12, planeEnemy2, planeEnemy22,planeEnemy3, planeEnemy32;
private:
	COLORREF color = RGB(0, 255, 0);
	double speed, x = 0, y = 0;
	int m;
};



//??BOSS
class EnemyBoss
{
public:
	EnemyBoss();
	EnemyBoss(double x, double y);
	void draw(); // ??
	double &getX();
	double &getY();
	int getHealth() const; // ?  
    void setHealth(int health); // ?      
	int health = 10;    //       ????4
protected:
	IMAGE planeEnemy3, planeEnemy32;
private:
	COLORREF color = RGB(0, 255, 0); // ??
	double  x=0, y=0;
};


class Meteorite
{
public:
	// ?
	Meteorite(); // ?
	Meteorite(double mx, double my, double speed);
	void draw_meteorite(); // ?
	void meteoriteMove();  // ??
	double &getMX();
	double &getMY();
	double &getMSpeed();

private:
	COLORREF color; // ??
	double mx , my ;
	double speed;
};