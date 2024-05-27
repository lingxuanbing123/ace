#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	PlaneEnemy();
	PlaneEnemy(double x, double y, double speed, int m);
	void draw(int m); // 绘制飞机
	void move();	  // 移动飞机，根据按键响应
	double &getX();
	double &getY();
	int &getM();
	double &getSpeed();
	int getHealth() const; // 返回血量  
    void setHealth(int health); // 设置血量      
	int health = 2;    //       小飞机血量为4
protected:
	IMAGE planeEnemy1, planeEnemy12, planeEnemy2, planeEnemy22;
private:
	COLORREF color = RGB(0, 255, 0); // 飞机颜色
	double speed, x=0, y=0;
	int m;
};




class Meteorite
{
public:
	// 陨石坐标
	Meteorite(); // 构造函数
	Meteorite(double mx, double my, double speed);
	void draw_meteorite(); // 绘制陨石
	void meteoriteMove();  // 陨石移动
	double &getMX();
	double &getMY();
	double &getMSpeed();

private:
	COLORREF color; // 陨石颜色
	double mx , my ;
	double speed;
};