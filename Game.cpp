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

typedef int SOUND;

Boom *pBoom;
Node *pBullet_E;   // 敌机子弹
Node *enemyPlane;  // 敌机
Node *playerPlane; // 我机
struct CoverButton CoverButton;
struct Stage stage;

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
    IMAGE startImage, pauseImage, gameImage,winImage,chooseImage, plane1, plane2, planeEnemy1, planeEnemy2, boss, bullet, bulletEnemy;
    initgraph(640, 800);
    loadimage(&startImage, "D:\\Git warehouse\\github\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\Git warehouse\\github\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\Git warehouse\\github\\ace\\rs\\game.bmp"); 
    loadimage(&chooseImage, "D:\\Git warehouse\\github\\ace\\rs\\choose.bmp");
    loadimage(&winImage,"D:\\Git warehouse\\github\\ace\\rs\\win.png");// 加载五个背景图
    putimage(0, 0, &startImage);                          // 初始化第一个背景图
    list<Bullet *> bulletList;                            // 创建链表以记录子弹
    list<PlaneEnemy *> eplaneList;                        // 创建链表以记录敌机
    list<Prop *> propList;                                //创建链表以记录道具
    Bullet *pBullet = nullptr;                            // 创建迭代器
    PlaneEnemy *ePlane = nullptr;
    Prop *pProp = nullptr;

    stage.pause = 0; // 界面相关参数
    stage.game1 = 0;
    stage.game2 = 0;
    stage.home = 1;
    stage.choose = 0;
    CoverButton.button_continue = 0; // 按钮相关参数
    CoverButton.button_quit = 0;
    CoverButton.button_home = 0;
    CoverButton.button_level1 = 0;
    CoverButton.button_level2 = 0; 
    CoverButton.button_choose1 = 0;
    CoverButton.button_choose2 = 0;// 初始化参数
    int a;
    int prop1 = 0,prop2=0;
    int flag = 0;      // 当前关卡进度，初始为0，第一关达到30胜利，第二关达到30产生BOSS

HOMEMENU:
    while (!CoverButton.button_quit) // 只要没有按到QUIT
    {
        a = 0;
        MouseListener();     // 获取鼠标
        if(stage.choose == 1)    
        {
            putimage(0,0,&chooseImage);
            MouseListener(); 
            stage.choose = 0;
            stage.game1 = 1;
        }
        if(stage.choose == 2)    
        {
            putimage(0,0,&chooseImage);
            MouseListener(); 
            stage.choose = 0;
            stage.game2 = 1;
        }


        if (stage.game1 == 1) // 如果按到level1则进入关卡1
        {
            putimage(0, 0, &gameImage);                  // 绘制游戏背景
            Plane *playerPlane = new Plane(320, 760, 5); // 创建玩家飞机对象

            if(choose = 1)
            {
                playerPlane->draw1();
            }                         
            if(choose = 2)
            {
                playerPlane->draw2();
            }

            while (1) // 玩家飞机开始操作
            {
                GetCommand();         // 获取ESCAPE是否按下
                if (stage.pause == 1) // 如果按了ESCAPE，就进入暂停界面
                {
                    putimage(0, 0, &pauseImage);     // 绘制暂停界面
                    while (!CoverButton.button_quit) // 只要没按到QUIT
                    {
                        MouseListener();     // 获取鼠标
                        if (stage.game1 == 1) // 如果按到了CONTINUE
                        {
                            stage.game2 = 0;
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
                            flag = 0;
                        }
                    }
                    if (CoverButton.button_quit) // 按到quit，给我丨
                    {
                        flag = 0;
                        goto CLOSE;
                    }
                }

                if(flag>=30)
                {
                        flag = 0;
                        // 清空子弹列表
                        bulletList.clear();
                        // 清空敌机列表
                        eplaneList.clear();
                        // 进入胜利界面
                        putimage(0, 0, &winImage);
                        Sleep(3000);
                        stage.game1 = 0;
                        stage.home = 1;
                        putimage(0, 0, &startImage); // 绘制菜单背景
                        goto HOMEMENU;               // 跳出循环回到主菜单
                }



                BeginBatchDraw(); // 双缓冲机制维持画图稳定，非必要勿删
                cleardevice();    // 清空画面
                putimage(0, 0, &gameImage);

                // 用随机数生成决定敌机种类 敌：陨石=47:5
                if (eplaneList.size() < 5)
                {
                    int pos = rand() % 52; // 0-51
                    switch (pos)
                    {
                    case 0 ... 46:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 5 + 3, 1);
                        break;
                    case 47 ...51:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 5 + 3, 3);
                        break;
                    }
                    eplaneList.push_back(ePlane);
                }
                if(propList.size()<1){
                    int posp = rand() % 53;
                    switch (posp){
                    case 0 ...26:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50,1,1);
                        break;
                        case 27 ...52:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50,1,2);
                        break;
                        }
                    propList.push_back(pProp);
                }

            if(choose = 1)
            {
                playerPlane->draw1();
            }                         
            if(choose = 2)
            {
                playerPlane->draw2();
            }



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

                for (auto propIter = propList.begin();propIter!=propList.end();)
                {
                        (*propIter)->drawProp();
                        if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*propIter)->getX(), (*propIter)->getY(), (*propIter)->getX() + 23, (*propIter)->getY() + 27))
                        {
                            delete *propIter;
                            propIter = propList.erase(propIter);
                        }
                        else {
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
                            if (planeEP((*bulletIter)->getX() , (*bulletIter)->getY() , (*bulletIter)->getX() + 8, (*bulletIter)->getY() + 8, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                            {

                                (*eplaneIter)->setHealth((*eplaneIter)->getHealth() - 1); //   减少敌机的血量

                                // 检查敌机是否已经被摧毁（即血量是否减至0或以下）
                                if ((*eplaneIter)->getHealth() <= 0)
                                {
                                    flag++;
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

                    if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                    {
                        delete *eplaneIter;
                        eplaneIter = eplaneList.erase(eplaneIter);
                        a = 1;
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
                if (a == 1)
                {
                    // 清空子弹列表
                    bulletList.clear();
                    // 清空敌机列表
                    eplaneList.clear();
                    propList.clear();
                    stage.home = 1;
                    stage.game1 = 0;
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








        else if (stage.game2 == 1)
        {
            putimage(0, 0, &gameImage);                  // 绘制游戏背景
            Plane *playerPlane = new Plane(320, 760, 5); // 创建玩家飞机对象
            EnemyBoss *enemyBoss = new EnemyBoss(70, 0); //创建BOSS对象
 
             if(choose = 1)
            {
                playerPlane->draw1();
            }                         
            if(choose = 2)
            {
                playerPlane->draw2();
            }


            while (1) // 玩家飞机开始操作
            {
                GetCommand();         // 获取ESCAPE是否按下
                if (stage.pause == 1) // 如果按了ESCAPE，就进入暂停界面
                {
                    putimage(0, 0, &pauseImage);     // 绘制暂停界面
                    while (!CoverButton.button_quit) // 只要没按到QUIT
                    {
                        MouseListener();     // 获取鼠标
                        if (stage.game1 == 1) // 如果按到了CONTINUE
                        {
                            stage.game2 = 0;
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

                // 用随机数生成决定敌机种类 敌1：敌2：陨石=24:24:4
                if (eplaneList.size() < 5)
                {
                    int pos = rand() % 52; // 0-51
                    switch (pos)
                    {
                    case 0 ... 23:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 5 + 3, 1);
                        break;
                    case 24 ... 48:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 5 + 3, 2);
                        break;
                    case 49 ...51:
                        ePlane = new PlaneEnemy(rand() % 6 * 100 + 100, -100, rand() % 10 + 3, 3);
                        break;
                    }
                    eplaneList.push_back(ePlane);
                }
                if(propList.size()<1){
                    int posp = rand() % 53;
                    switch (posp){
                    case 0 ...26:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50,1,1);
                        break;
                        case 27 ...52:
                        pProp = new Prop(rand() % 561 + 40, rand() % 701 + 50,1,2);
                        break;
                        }
                    propList.push_back(pProp);
                }

            if(choose = 1)
            {
                playerPlane->draw1();
            }                     
            if(choose = 2)
            {
                playerPlane->draw2();
            }
            playerPlane->draw1();

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

                for (auto propIter = propList.begin();propIter!=propList.end();)
                {
                        (*propIter)->drawProp();
                        if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*propIter)->getX(), (*propIter)->getY(), (*propIter)->getX() + 23, (*propIter)->getY() + 27))
                        {
                            delete *propIter;
                            propIter = propList.erase(propIter);
                        }
                        else {
                            propIter++;
                        }
                }

                //BOSS出现
                if(flag >= 1)
                {
                    enemyBoss->draw(); // 绘制BOSS
                }


                    // 检测子弹与敌机的碰撞
                    for (auto bulletIter = bulletList.begin(); bulletIter != bulletList.end();)
                    {
                        (*bulletIter)->drawBullet((*bulletIter)->getX(), (*bulletIter)->getY());
                        (*bulletIter)->moveBullet();

                        bool bulletRemoved = false;
                        for (auto eplaneIter = eplaneList.begin(); eplaneIter != eplaneList.end();)
                        {
                            if (planeEP((*bulletIter)->getX() , (*bulletIter)->getY() , (*bulletIter)->getX() + 8, (*bulletIter)->getY() + 8, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                            {

                                (*eplaneIter)->setHealth((*eplaneIter)->getHealth() - 1); //   减少敌机的血量

                                // 检查敌机是否已经被摧毁（即血量是否减至0或以下）
                                if ((*eplaneIter)->getHealth() <= 0)
                                {
                                    flag++;   //敌机被摧毁了，BOSS进度加一
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

                    if (planeEP(playerPlane->getX(), playerPlane->getY(), playerPlane->getX() + 46, playerPlane->getY() + 40, (*eplaneIter)->getX(), (*eplaneIter)->getY(), (*eplaneIter)->getX() + 46, (*eplaneIter)->getY() + 50))
                    {
                        delete *eplaneIter;
                        eplaneIter = eplaneList.erase(eplaneIter);
                        a = 1;
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
                if (a == 1)
                {
                    // 清空子弹列表
                    bulletList.clear();
                    // 清空敌机列表
                    eplaneList.clear();
                    propList.clear();
                    stage.home = 1;
                    stage.game2 = 0;
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