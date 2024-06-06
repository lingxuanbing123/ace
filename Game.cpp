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
#include <thread>
#include <list>
#include <ctime>
#include <cstdlib>
#include <thread>
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
#include "Plane.h"
#include "Operate.h"

#pragma comment(lib, "winmm.lib")

typedef int SOUND;

Boom *pBoom;

Node *pBullet_E;   // 敌机子弹
PlaneEnemy *enemyPlane;  // 敌机
Node *playerPlane; // 我机
int boss = 0;      // 是否存在boss
struct CoverButton CoverButton;
struct Stage stage;

int Timer()
{
    static DWORD t1,t2;
    while(1)
    {if (t2-t1>63)
    {
        t1=t2;
        return 1;
    }
    t2 = clock();
    return 0;
    }
}

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
bool isColliding(int x1, int y1, int r, int x, int y)
{
    if (x1 + r < x || x + 46 < x - r)
    {
        return false; // 水平方向没有重叠
    }
    if (y1 + r < y || y + 40 < y1 - r)
    {
        return false; // 垂直方向没有重叠
    }
    return true; // 发生碰撞
}

int main()
{
    srand((unsigned int)time(NULL)); // 随机数初始化
    IMAGE startImage, pauseImage, gameImage, plane1, plane2, planeEnemy1, planeEnemy2, boss, bullet, bulletEnemy;
    initgraph(640, 800);
    loadimage(&startImage, "E:\\test\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "E:\\test\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "E:\\test\\ace\\rs\\game.bmp"); // 加载三个背景图
    putimage(0, 0, &startImage);                          // 初始化第一个背景图
    list<Bullet *> bulletList;                            // 创建链表以记录子弹
    list<PlaneEnemy *> eplaneList;                        // 创建链表以记录敌机
    list<Prop *> propList;                                // 创建链表以记录道具
    Bullet *pBullet = nullptr;                            // 创建迭代器
    PlaneEnemy *ePlane = nullptr;
    Prop *pProp = nullptr;
    list<BulletEnemy *> bulletEnemyList;
    BulletEnemy *pBulletEnemy=nullptr;
    stage.pause = 0; // 界面相关参数
    stage.game = 0;
    stage.home = 1;
    CoverButton.button_continue = 0; // 按钮相关参数
    CoverButton.button_quit = 0;
    CoverButton.button_home = 0;
    CoverButton.button_level1 = 0;
    CoverButton.button_level2 = 0; // 初始化参数
    int a, b=0,s;
    int prop1 = 0, prop2 = 0;
    double ha;

HOMEMENU:
    while (!CoverButton.button_quit) // 只要没有按到QUIT
    {
        if (0 == PlaySound(TEXT("D:\\git0\\ace\\rs\\music\\test.wav"), NULL, SND_FILENAME | SND_ASYNC))
        {
            printf("playsound false");
        }
        system("pause");
        a = 0;
        s = 0;
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
                            // 清空子弹列表
                            bulletList.clear();
                            // 清空敌机列表
                            eplaneList.clear();
                            putimage(0, 0, &startImage); // 绘制菜单背景
                            goto HOMEMENU;               // 跳出循环回到主菜单
                        }
                    }
                    if (CoverButton.button_quit) // 按到quit，给我丨
                    {
                        goto CLOSE;
                    }
                }
                BeginBatchDraw(); // 双缓冲机制维持画图稳定，非必要勿删
                cleardevice();    // 清空画面
                putimage(0, 0, &gameImage);

                // 用随机数生成决定敌机种类 敌：陨石=50:2
                if (eplaneList.size() < 5)
                {
                    int pos = rand() % 52; // 0-51
                    switch (pos)
                    {
                    case 0 ... 49:
                        {ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 5 + 3, 1);
/* while(1){
                    if(Timer(500))
                    {
    pBulletEnemy = new BulletEnemy(enemyPlane->getX() + 23, enemyPlane->getY() + 10, 4, 1);
    bulletEnemyList.push_back(pBulletEnemy);
      for (auto bulletEnemyIter = bulletEnemyList.begin(); bulletEnemyIter != bulletEnemyList.end();)
                {
                    if ((*bulletEnemyIter)->getY() > 810)
                    {
                        delete *bulletEnemyIter;
                        bulletEnemyIter = bulletEnemyList.erase(bulletEnemyIter);
                    }
                    else
                    {
                        ++bulletEnemyIter;
                    }
                }
                    }
                    } */
                        break;}
                    case 50:
                    case 51:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10 + 3, 2);
                        break;
                    }
                    eplaneList.push_back(ePlane);
                }
                if (propList.size() < 1)
                {
                    int posp = rand() % 53;
                    switch (posp)
                    {
                    case 0 ... 26:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50, 1, 2);
                        break;
                    case 27 ... 52:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50, 1, 2);
                        break;
                    }
                    propList.push_back(pProp);
                }

                playerPlane->draw(); // 绘制玩家飞机

                if (_kbhit())
                {
                    char key = _getch();            // 获取键盘输入
                    playerPlane->move(key);         // 移动玩家飞机
                    if (GetAsyncKeyState(VK_SPACE)) // 创建子弹
                    {
                        pBullet = new Bullet(playerPlane->getX() + 28, playerPlane->getY() - 10, 1, 5);
                        bulletList.push_back(pBullet);
                    }
                }
                // 道具和我方碰撞，给予效果
                for (auto propIter = propList.begin(); propIter != propList.end();)
                {
                    (*propIter)->drawProp();
                    if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*propIter)->getX(), (*propIter)->getY(), (*propIter)->getX() + 23, (*propIter)->getY() + 27))
                    {
                        if ((*propIter)->getModel() == 1)
                        {
                            if (playerPlane->getinvincible() == false)
                            {
                                playerPlane->setinvincible(true);
                            }
                        }
                        if ((*propIter)->getModel() == 2)
                        {
                            if(b<=3){
                                b++ ;
                            }
/*                             if (playerPlane->getinvincible() == false)
                            {
                                playerPlane->setinvincible(true);
                            } */
                        }
                        delete *propIter;
                        propIter = propList.erase(propIter);
                    }
                    else
                    {
                        propIter++;
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
                        if (s == 0)
                        {
                            (*bulletIter)->setHarm(0);
                            ha = (*bulletIter)->getHarm();
                            s = 1;
                        }
                        if (b != 0)
                        {
                            (*bulletIter)->setHarm(b);
                            ha = (*bulletIter)->getHarm();
                        }
                        if (planeEP((*bulletIter)->getX(), (*bulletIter)->getY(), (*bulletIter)->getX() + 8, (*bulletIter)->getY() + 8, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                        {

                              (*eplaneIter)->setHealth((*eplaneIter)->getHealth() - ha ); //   减少敌机的血量

                            // 检查敌机是否已经被摧毁（即血量是否减至0或以下）
                            if ((*eplaneIter)->getHealth() <= 0)
                            {
                                delete *eplaneIter;
                                eplaneIter = eplaneList.erase(eplaneIter);
                            }
                            else
                            {
                                // 如果敌机未被摧毁，则继续遍历下一个敌机
                                ++eplaneIter;
                            }
                            // 无论敌机是否被摧毁，都删除子弹并退出内部循环
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
                    if(Timer())
                    {
                    pBulletEnemy = new BulletEnemy((*eplaneIter)->getX() + 23, (*eplaneIter)->getY() + 50, 0.1, 1);
                    bulletEnemyList.push_back(pBulletEnemy);
                    }
                     for(auto bulletEnemyIter = bulletEnemyList.begin(); bulletEnemyIter != bulletEnemyList.end();)        
                    {
                    (*bulletEnemyIter)->drawBulletEnemy((*bulletEnemyIter)->getX(), (*bulletEnemyIter)->getY());
                    (*bulletEnemyIter)->moveBulletEnemy();
                    ++bulletEnemyIter;
                    }

                  
                   
            
            
                    if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                    {
                        delete *eplaneIter;
                        eplaneIter = eplaneList.erase(eplaneIter);
                        if (playerPlane->getinvincible() == false)
                        {
                            a = 1;
                        }
                        else
                        {
                            playerPlane->setinvincible(false);
                            ++eplaneIter;
                        }
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

                    for(auto bulletEnemyIter = bulletEnemyList.begin(); bulletEnemyIter != bulletEnemyList.end();)        
                    {
                    (*bulletEnemyIter)->drawBulletEnemy((*bulletEnemyIter)->getX(), (*bulletEnemyIter)->getY());
                    (*bulletEnemyIter)->moveBulletEnemy();
                    ++bulletEnemyIter;
                    }

                for (auto bulletEnemyIter = bulletEnemyList.begin(); bulletEnemyIter != bulletEnemyList.end();)
                {
                    if ((*bulletEnemyIter)->getY() > 810)
                    {
                        delete *bulletEnemyIter;
                        bulletEnemyIter = bulletEnemyList.erase(bulletEnemyIter);
                    }
                    else
                    {
                        ++bulletEnemyIter;
                    }
                }

                EndBatchDraw();
                if (a == 1)
                {
                    // 清空子弹列表
                    bulletList.clear();
                    b = 0;
                    // 清空敌机列表
                    eplaneList.clear();
                    propList.clear();
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