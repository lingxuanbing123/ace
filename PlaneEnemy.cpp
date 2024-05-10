/* #include "PlaneEnemy.h"
#include <graphics.h>
#include <conio.h>
PlaneEnemy::PlaneEnemy()
{
	color = RGB(0,255,0); // 设置飞机颜色为绿色
    speed = 1;
    draw_PlaneEnemy();
}
void PlaneEnemy::draw_PlaneEnemy()
{
    setfillcolor(color);
    solidrectangle(planeenemy_x - 20, planeenemy_y, planeenemy_x + 20, planeenemy_y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                  // 设置引擎颜色为蓝色
    solidrectangle(planeenemy_x - 10, planeenemy_y  + 30, planeenemy_x - 5, planeenemy_y + 40); // 左引擎
    solidrectangle(planeenemy_x  + 5, planeenemy_y + 30, planeenemy_x + 10, planeenemy_y + 40); // 右引擎
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
    color = RGB(128,128,128);   // 设置陨石颜色为灰色
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
    initgraph(640, 800); // 初始化图形窗口
    PlaneEnemy enemyPlane;          //创建敌机对象
    _getch();
    Meteorite testmeteorite;
} */
