/* #include "PlaneEnemy.h"
#include <graphics.h>
#include <conio.h>
PlaneEnemy::PlaneEnemy()
{
	color = RGB(0,255,0); // ���÷ɻ���ɫΪ��ɫ
    speed = 1;
    draw_PlaneEnemy();
}
void PlaneEnemy::draw_PlaneEnemy()
{
    setfillcolor(color);
    solidrectangle(planeenemy_x - 20, planeenemy_y, planeenemy_x + 20, planeenemy_y + 30);

    // ���Ʒɻ�����������
    setfillcolor(RGB(0, 0, 255));                  // ����������ɫΪ��ɫ
    solidrectangle(planeenemy_x - 10, planeenemy_y  + 30, planeenemy_x - 5, planeenemy_y + 40); // ������
    solidrectangle(planeenemy_x  + 5, planeenemy_y + 30, planeenemy_x + 10, planeenemy_y + 40); // ������
}
void PlaneEnemy::EnemyMove()
{
    while (1) 
    {
        planeenemy_x+=speed;
        planeenemy_y+=speed;
    }
}

Meteorite::Meteorite()
{
    color = RGB(128,128,128);   // ������ʯ��ɫΪ��ɫ
    speed = 1;
}

void Meteorite::draw_meteorite()
{
    setfillcolor(color);
    circle(mx, my, 20);
}

void Meteorite::meteoriteMove()
{
    while (1)
        my+=speed;
}
int main() {
    initgraph(640, 800); // ��ʼ��ͼ�δ���
    PlaneEnemy enemyPlane;          //�����л�����
    _getch();
    Meteorite testmeteorite;
} */
