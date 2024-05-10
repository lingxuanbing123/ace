#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	int planeenemy_x = 0, planeenemy_y = -40;    //敌机坐标
	PlaneEnemy();
	int getX() const { return planeenemy_x; }
	int getY() const { return planeenemy_y; }	
	void setX(int x) { planeenemy_x = x; }
	void setY(int y) { planeenemy_y = y; }		// 设置敌机当前位置
	void draw_PlaneEnemy();         //绘制敌机
	void EnemyCreat();				//创建敌机
	void EnemyMove();				//敌机移动机制
	void Enemy_Bullet_Creat();		//敌机产生子弹

private:
	COLORREF color; // 飞机颜色
	 int speed;
};
class Meteorite
{
public:
	int mx = 0, my = -40;			//陨石坐标
	Meteorite();					//构造函数
	void draw_meteorite();			//绘制陨石
	void meteoriteMove();			//陨石移动
private:
	COLORREF color; // 陨石颜色
	int speed;

};