#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	PlaneEnemy();
	PlaneEnemy(double x, double y, double speed, int m);
	void draw(int m); // ??????
	void move();	  // ??????????????????
	double &getX();
	double &getY();
	int &getM();
	double &getSpeed();
	double getHealth() const; // ����Ѫ��  
    void setHealth(double health); // ����Ѫ��      
	double health = 4;    //       С�ɻ�Ѫ��Ϊ4
protected:
	IMAGE planeEnemy1, planeEnemy12, planeEnemy2, planeEnemy22;
private:
	COLORREF color = RGB(0, 255, 0); // ??????
	double speed, x=0, y=0;
	int m;
};




/* class Meteorite
{
public:
	// ???????
	Meteorite(); // ??????
	Meteorite(double mx, double my, double speed);
	void draw_meteorite(); // ???????
	void meteoriteMove();  // ??????
	double &getMX();
	double &getMY();
	double &getMSpeed();

private:
	COLORREF color; // ??????
	double mx , my ;
	double speed;
}; */