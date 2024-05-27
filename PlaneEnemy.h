#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	PlaneEnemy();
	PlaneEnemy(double x, double y, double speed, int m);
	void draw(int m); // ���Ʒɻ�
	void move();	  // �ƶ��ɻ������ݰ�����Ӧ
	double &getX();
	double &getY();
	int &getM();
	double &getSpeed();
	int getHealth() const; // ����Ѫ��  
    void setHealth(int health); // ����Ѫ��      
	int health = 2;    //       С�ɻ�Ѫ��Ϊ4
protected:
	IMAGE planeEnemy1, planeEnemy12, planeEnemy2, planeEnemy22;
private:
	COLORREF color = RGB(0, 255, 0); // �ɻ���ɫ
	double speed, x=0, y=0;
	int m;
};




class Meteorite
{
public:
	// ��ʯ����
	Meteorite(); // ���캯��
	Meteorite(double mx, double my, double speed);
	void draw_meteorite(); // ������ʯ
	void meteoriteMove();  // ��ʯ�ƶ�
	double &getMX();
	double &getMY();
	double &getMSpeed();

private:
	COLORREF color; // ��ʯ��ɫ
	double mx , my ;
	double speed;
};