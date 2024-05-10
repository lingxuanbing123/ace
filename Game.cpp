#include <iostream>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#include <graphics.h>

// esayx
#include "Game.h"
#include "Prop.h"
#include "Shoot.h"
#include "BulletEnemy.h"
#include "Boom.h"
#include "Bullet.h"

#include "PlaneEnemy.h"
#include "Operate.h"

typedef int SOUND;

Prop *prop;
Boom *pBoom;
/* Node *pBullet;     // 子弹 */
Node *pBullet_E;   // 敌机子弹
Node *enemyPlane;  // 敌机
Node *playerPlane; // 我机
int boss = 0;      // 是否存在boss
struct CoverButton CoverButton;
struct Stage stage;

#include <conio.h>
#include "Plane.h"
int main()
{
    initgraph(640, 800);                        // 初始化图形窗口
    IMAGE startImage, pauseImage, gameImage;
    loadimage(&startImage, "D:\\git0\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\git0\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\git0\\ace\\rs\\game.bmp");
    putimage(0, 0, &startImage);
    Plane *playerPlane = new Plane(320, 380, 5); // 创建玩家飞机对象
    playerPlane->draw();
    while (1)
    {
        BeginBatchDraw();
        cleardevice();          // 清空画面
        putimage(0, 0, &startImage);
        playerPlane->draw();    // 绘制玩家飞机
        if (_kbhit()){
            char key = _getch();    // 获取键盘输入
            playerPlane->move(key); // 移动玩家飞机
            if (key == ' '){
                Bullet *pBullet = new Bullet(playerPlane->getX(), playerPlane->getY()-10,5,5);
                pBullet->drawBullet(playerPlane->getX(), playerPlane->getY() - 10);
                pBullet->moveBullet();
                /* pBullet = new Node(bullet, pBullet); */
            }
        }
        EndBatchDraw();
    }
    _getch();
    closegraph(); // 关闭图形窗口
    return 0;
}
