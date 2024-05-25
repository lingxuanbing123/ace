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

// Include necessary headers
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

Boom *pBoom;

Node *pBullet_E;   // 敌机子弹
PlaneEnemy *enemyPlane;  // 敌机
Node *playerPlane; // 我机
int boss = 0;      // 是否存在boss
struct CoverButton CoverButton;
struct Stage stage;
list<BulletEnemy *> bulletEnemyList;
BulletEnemy *pBulletEnemy=nullptr;
// 碰撞检测函数
bool planeEP(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22);

bool planeEP(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22)
{
    if (x12 < x21 || x11 > x22 || y12 < y21 || y11 > y22)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    srand((unsigned int)time(NULL)); // 随机数初始化
    IMAGE startImage, pauseImage, gameImage;
    initgraph(640, 800);
    loadimage(&startImage, "E:\\test\\ace\\start.bmp");
    loadimage(&pauseImage, "E:\\test\\ace\\pause.bmp");
    loadimage(&gameImage, "E:\\test\\ace\\game.bmp"); // 加载三个背景图
    putimage(0, 0, &startImage);                          // 初始化第一个背景图
    list<Bullet *> bulletList;                            // 创建链表以记录子弹
    list<PlaneEnemy *> eplaneList;                        // 创建链表以记录敌机
    Bullet *pBullet = nullptr;                            // 创建迭代器
    PlaneEnemy *ePlane = nullptr;

    stage.pause = 0;        //界面相关参数
    stage.game = 0;
    stage.home = 1;
    CoverButton.button_continue = 0;    //按钮相关参数
    CoverButton.button_quit = 0;
    CoverButton.button_home = 0;
    CoverButton.button_level1 = 0;
    CoverButton.button_level2 = 0; // 初始化参数
    int a;

HOMEMENU:
    while (!CoverButton.button_quit) // 只要没有按到QUIT
    {
        a = 0;
        MouseListener();     // 获取鼠标
        if (stage.game == 1) // 如果按到level则进入游戏
        {
            putimage(0, 0, &gameImage);                  // 绘制游戏背景
            Plane *playerPlane = new Plane(320, 760, 5); // 创建玩家飞机对象
            playerPlane->draw();                         // 绘制玩家飞机


            while (1) // 玩家飞机开始操作
            {
                GetCommand();         // 获取ESCAPE是否按下
                if (stage.pause == 1) // 如果按了ESCAPE，就进入暂停界面
                {
                    putimage(0, 0, &pauseImage);     // 绘制暂停界面
                    while (!CoverButton.button_quit) // 只要没按到QUIT
                    {
                        MouseListener();     // 获取鼠标
                        if (stage.game == 1) // 如果按到了CONTINUE
                        {
                            putimage(0, 0, &gameImage); // 绘制游戏背景
                            break;                      // 退出获取鼠标的循环
                        }
                        else if (stage.home == 1) // 如果按到了HOME
                        {
                            putimage(0, 0, &startImage); // 绘制菜单背景
                            goto HOMEMENU;               // 跳出循环回到主菜单
                        }
                    }
                    if (CoverButton.button_quit)        // 按到quit，给我丨
                    {
                        goto CLOSE;
                    }
                }
                BeginBatchDraw();       //双缓冲机制维持画图稳定，非必要勿删
                cleardevice(); // 清空画面
                putimage(0, 0, &gameImage);

                //用随机数生成决定敌机种类 敌：陨石：道具=50:2:1
                if (eplaneList.size() < 5)
                {
                    int pos = rand() % 53; // 0-52
                    switch (pos)
                    {
                    case 0 ... 49:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10 + 3, 1);
                        break;
                    case 50:
                    case 51:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10 + 3, 2);
                        break;
                    case 52:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, rand() % 8 * 100 + 50, 0, 3);
                        break;
                    }
                    eplaneList.push_back(ePlane);
                }
                pBulletEnemy = new BulletEnemy(enemyPlane->getX(), enemyPlane->getY() + 10, 1, 5);
                bulletEnemyList.push_back(pBulletEnemy);
                playerPlane->draw(); // 绘制玩家飞机

                if (_kbhit())
                {
                    char key = _getch();            // 获取键盘输入
                    playerPlane->move(key);         // 移动玩家飞机
                    if (GetAsyncKeyState(VK_SPACE)) // 创建子弹
                    {
                        pBullet = new Bullet(playerPlane->getX(), playerPlane->getY() - 10, 1, 5);
                        bulletList.push_back(pBullet);
                    }
                }

                // 检测子弹与敌机的碰撞
for (auto bulletIter = bulletList.begin(); bulletIter != bulletList.end();)
{
    (*bulletIter)->drawBullet((*bulletIter)->getX(), (*bulletIter)->getY());
    (*bulletIter)->moveBullet();

    bool bulletRemoved = false;

    for (auto eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end();)
    {
        if (planeEP((*bulletIter)->getX() - 2.5, (*bulletIter)->getY() - 2.5, (*bulletIter)->getX() + 2.5, (*bulletIter)->getY() + 2.5,(*eplaneIter)->getX() - 20, (*eplaneIter)->getY(), (*eplaneIter)->getX() + 20, (*eplaneIter)->getY() + 30))
        {
            delete *eplaneIter;
            eplaneIter = eplaneList.erase(eplaneIter);

            delete *bulletIter;
            bulletIter = bulletList.erase(bulletIter);
            bulletRemoved = true;
            break;
        }
        else
        {
            ++eplaneIter;
        }
    }

    if (!bulletRemoved)
    {
        ++bulletIter;
    }
}


                // 子弹打出屏幕后进行消除
                for (auto bulletIter = bulletList.begin(); bulletIter != bulletList.end();)
                {
                    if ((*bulletIter)->getY() < -10)
                    {
                        delete *bulletIter;
                        bulletIter = bulletList.erase(bulletIter);
                    }
                    else
                    {
                        ++bulletIter;
                    }
                }

                // 画敌机，对敌机位置和我方位置进行判断
                for (auto eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end();)
                {
                    (*eplaneIter)->draw((*eplaneIter)->getM());
                    (*eplaneIter)->move();

                    if (planeEP(playerPlane->getX() - 20, playerPlane->getY(), playerPlane->getX() + 20, playerPlane->getY() + 30, (*eplaneIter)->getX() - 20, (*eplaneIter)->getY(), (*eplaneIter)->getX() + 20, (*eplaneIter)->getY() + 30))
                    {
                        delete *eplaneIter;
                        eplaneIter = eplaneList.erase(eplaneIter);
                        a=1;
                        // handle player plane damage or destruction here
                    }
                    else if ((*eplaneIter)->getY() > 820) // 判断敌机是否飞出屏幕
                    {
                        delete *eplaneIter;
                        eplaneIter = eplaneList.erase(eplaneIter);
                    }
                    else
                    {
                        ++eplaneIter;
                    }
                }

                EndBatchDraw();
                if (a==1){
                    stage.home = 1;
                    stage.game = 0;
                    putimage(0, 0, &startImage);
                    for (auto eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end(); eplaneIter++)
                    {
                        eplaneIter = eplaneList.erase(eplaneIter);
                        if (eplaneIter == eplaneList.end())
                        {
                            break;
                        }
                        break;
                    }
                    break;
                }
            }
        }
    }

CLOSE:
    closegraph(); // 关闭图形界面
    return 0;
}