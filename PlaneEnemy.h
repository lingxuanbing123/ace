#pragma once
#include <graphics.h>
class PlaneEnemy
{
public:
	int planeenemy_x = 0, planeenemy_y = -40;    //�л�����
	PlaneEnemy();
	int getX() const { return planeenemy_x; }
	int getY() const { return planeenemy_y; }	
	void setX(int x) { planeenemy_x = x; }
	void setY(int y) { planeenemy_y = y; }		// ���õл���ǰλ��
	void draw_PlaneEnemy();         //���Ƶл�
	void EnemyCreat();				//�����л�
	void EnemyMove();				//�л��ƶ�����
	void Enemy_Bullet_Creat();		//�л������ӵ�

private:
	COLORREF color; // �ɻ���ɫ
	 int speed;
};
class Meteorite
{
public:
	int mx = 0, my = -40;			//��ʯ����
	Meteorite();					//���캯��
	void draw_meteorite();			//������ʯ
	void meteoriteMove();			//��ʯ�ƶ�
private:
	COLORREF color; // ��ʯ��ɫ
	int speed;

};