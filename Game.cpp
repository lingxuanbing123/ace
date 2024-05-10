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
#include <list>
using namespace std;
// esayx
#include "Game.h"
#include "Prop.h"
#include "Shoot.h"
#include "BulletEnemy.h"
#include "Boom.h"
#include "Bullet.h"
#include "PlaneEnemy.h"
#include "Plane.h"
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
int main()
{
    srand((unsigned int)time(NULL));
    initgraph(640, 800);                        // 初始化图形窗口
    IMAGE startImage, pauseImage, gameImage;
    loadimage(&startImage, "D:\\git0\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\git0\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\git0\\ace\\rs\\game.bmp");
    putimage(0, 0, &startImage);
    Plane *playerPlane = new Plane(320, 380, 5); // 创建玩家飞机对象
    playerPlane->draw();
    list<Bullet *> bulletList;           //创建链表以记录子弹
    list<PlaneEnemy *> eplaneList;
    list<Bullet *>::iterator bulletIter;        //创建迭代器
    list<PlaneEnemy *>::iterator eplaneIter;
    Bullet *pBullet = nullptr;
    PlaneEnemy *ePlane = nullptr;
    while (1)
    {
        BeginBatchDraw();
        cleardevice();          // 清空画面
        putimage(0, 0, &startImage);
        if (eplaneList.size()<5)
        {
            int pos = rand() % 53;   //0-52
            switch (pos){
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                    ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10 + 3,1);
                    break;
                case 50:
                case 51:
                    ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10+3,2);
                    break;
                case 52:
                    ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, rand() % 8 * 100 + 50, 0, 3);
                    break;
            }
            eplaneList.push_back(ePlane);
        }
        playerPlane->draw();    // 绘制玩家飞机
        if (_kbhit()){
            char key = _getch();    // 获取键盘输入
            playerPlane->move(key); // 移动玩家飞机
                if (GetAsyncKeyState(VK_SPACE))
                {
                    // 创建子弹
                    pBullet = new Bullet(playerPlane->getX(), playerPlane->getY() - 10, 1, 5);
                    bulletList.push_back(pBullet);
                }
            }
            for (bulletIter = bulletList.begin(); bulletIter != bulletList.end(); bulletIter++)
            {
                (*bulletIter)->drawBullet((*bulletIter)->getX(), (*bulletIter)->getY());
                (*bulletIter)->moveBullet();
                /* if ((*bulletIter)->getY() < 0){
                    bulletList.erase(bulletIter);
                } */
        }
        if (!bulletList.empty()&&bulletList.front()->getY()<-10){
            bulletList.pop_front();
        }
        for (eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end(); eplaneIter++){
            (*eplaneIter)->draw((*eplaneIter)->getM());
            (*eplaneIter)->move();
        }
        for (eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end(); eplaneIter++)
        {
            if ((*eplaneIter)->getY()>=800){
                eplaneIter = eplaneList.erase(eplaneIter);
                if (eplaneIter == eplaneList.end()){
                    break;
                }
            }
            break;
        }
            EndBatchDraw();
    }
    _getch();
    closegraph(); // 关闭图形窗口
    return 0;
}
