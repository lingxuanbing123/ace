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
#include "Plane.h"
#include "Shoot.h"
#include "BulletEnemy.h"
#include "Boom.h"
#include "Bullet.h"

#include "PlaneEnemy.h"
#include "Operate.h"


//所有变量的定义
Prop *prop;
Boom *pBoom;
Node *pBullet;   // 子弹
Node *pBullet_E; // 敌机子弹
Node *pEnemy;    // 敌机
Node *pMyself;   // 我机

int boss = 0; // 是否存在boss
struct CoverButton CoverButton;
struct Stage stage;


Plane::Plane()
{
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
    this->x = x;
    this->y = y;
    this->speed = speed;
}
Plane::Plane(int x, int y, int speed){}

Bullet::Bullet()
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}
Bullet::Bullet(int x, int y, int speed, int i)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}

//所有用到的函数的定义
//1.鼠标信息函数
void MouseListener(void) {
	MOUSEMSG m;                               //鼠标
	if (MouseHit() && stage.pause) {                         //如果按下鼠标且在暂停界面
		m = GetMouseMsg();                               //获取鼠标信息
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:                              //鼠标按下 在不同按钮处，CoverButton结构体内变量有不同值
				if (QUIT2_SCOPE)
					CoverButton.button_quit = 1;            //亮
				else
					CoverButton.button_quit = 0;             //熄
				if (CONTINUE_SCOPE)
					CoverButton.button_continue = 1;             //亮
				else
					CoverButton.button_continue = 0;             //熄
				if (HOME_SCOPE)
					CoverButton.button_home = 1;          //亮
				else
					CoverButton.button_home = 0;             //熄
			break;
		case WM_LBUTTONUP:                                //鼠标抬起
				if (QUIT2_SCOPE)
				{
					CoverButton.button_quit = 0;       //在QUIT处松开鼠标，状态既不是暂停界面，也不是游戏界面，直接退出
					stage.pause = 0;
					stage.game = 0;
					stage.home = 0;
				}
				else if (CONTINUE_SCOPE)
				{
					CoverButton.button_continue = 0;            //在CONTINUE处松开鼠标，继续游戏
					stage.pause = 0;
					stage.home = 0;
					stage.game = 1;

				}
				else if (HOME_SCOPE)
				{
					CoverButton.button_home = 0;              //在HOME处松开鼠标，进入HOME界面
                    stage.pause = 0;
                    stage.game = 0;
					stage.home = 1;
				}
			break;
		}
	}
	if (MouseHit() && stage.home) {                    //如果按下鼠标且在主菜单界面
		m = GetMouseMsg();                               //获取鼠标事件
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:                            //鼠标按下
		    if (LEVEL1_SCOPE)
				CoverButton.button_level1 = 1;            //按钮亮
			else
				CoverButton.button_level1 = 0;           //按钮熄
			if (LEVEL2_SCOPE)
				CoverButton.button_level2 = 1;           //亮
			else
				CoverButton.button_level2 = 0;            //熄
			if (QUIT1_SCOPE)
				CoverButton.button_quit = 1;             //亮
			else
				CoverButton.button_quit = 0;              //熄
		break;
		case WM_LBUTTONUP:                            //鼠标抬起
			if (LEVEL1_SCOPE)
			{
				CoverButton.button_level1 = 0;            //按钮熄
				stage.pause = 0;                     //在LEVEL1处松开鼠标，进入第一关
				stage.game = 1;
				stage.home = 0;
			}
			else if (LEVEL2_SCOPE)
			{
				CoverButton.button_level2 = 0;            //按钮熄
				stage.pause = 0;                     
				stage.game = 1;                      //在LEVEL2处松开鼠标，进入第二关
				stage.home = 0;
			}
			else if (QUIT1_SCOPE)
			{
				CoverButton.button_quit = 0;             //按钮熄
                stage.pause = 0;                     //在QUIT处松开鼠标，退出游戏
                stage.game = 0;
                stage.home = 0;
			}
        break;
		}
	}
}
 int GetCommand(void)												//得到按键，上下左右
{
	int c = 0;
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) 
	{
		c |= CMD_ESC;
		stage.pause = 1;
		stage.game = 0;
		stage.home = 0;
	}
	return c;
}
//2.飞机移动函数
void Plane::move(char key)
{
if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W'))
   {
    if(y>0)
    this->y-=speed;
   }
   if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))
   {
    if(y<800)
    this->y+=speed;
   }
   if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A'))
   {
    if(x>0)
    this->x-=speed;
   }
   if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D'))
   {
    if(x<640)
    this->x+=speed;
   }
}
//3.飞机参数获取函数
int &Plane::getX()
{
    return x;
}
int &Plane::getY()
{
    return y;
}
int &Plane::getSpeed()
{
    return speed;
}
//4.飞机绘制函数
void Plane::draw()
{
    // 绘制飞机的矩形身体
    setfillcolor(color);
    solidrectangle(this->x - 20, this->y, this->x + 20, this->y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255));                                          // 设置引擎颜色为蓝色
    solidrectangle(this->x - 10, this->y + 30, this->x - 5, this->y + 40); // 左引擎
    solidrectangle(this->x + 5, this->y + 30, this->x + 10, this->y + 40); // 右引擎
}
//5.子弹函数
void Bullet::drawBullet(int x,int y) // 绘制子弹,己方子弹为蓝色实心圆
{
    setfillcolor(BLUE);
    solidcircle(x, y, 5);
}
void Bullet::moveBullet() // 移动子弹,己方子弹只往上移动
{
    this->y -= this->speed;
}
int &Bullet::getX() // 子弹坐标
{
    return x;
}
int &Bullet::getY()
{
    return y;
}
int &Bullet::getSpeed() // 子弹速度，参考速度为1
{
    return speed;
}
int &Bullet::getI()
{
    return i;
}
//6.
//7.
//8.
//9.
 





//主函数
int main(){
    IMAGE startImage,pauseImage,gameImage;
    initgraph(640, 800);
    loadimage(&startImage, "D:\\Git warehouse\\github\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\Git warehouse\\github\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\Git warehouse\\github\\ace\\rs\\game.bmp");           //加载三个背景图
    putimage(0,0,&startImage);                     //初始化第一个背景图

 	list<Bullet *> bulletList;                   //创建链表以记录子弹
	list<Bullet *>::iterator bulletIter;           //创建迭代器以遍历链表
	Bullet *pBullet = nullptr; 

    stage.pause = 0;
	stage.game = 0;
	stage.home = 1; 
    CoverButton.button_continue = 0;
    CoverButton.button_quit = 0;
    CoverButton.button_home = 0;
    CoverButton.button_level1 = 0;
    CoverButton.button_level2 = 0;                    //初始化参数

	HOMEMENU:
    while(!CoverButton.button_quit)                     //只要没有按到QUIT
    {   
        MouseListener();                         //获取鼠标
		if(stage.game == 1)                      //如果按到level则进入游戏
        {
            putimage(0,0,&gameImage);             //绘制游戏背景
			Plane *playerPlane = new Plane(320, 760, 5); // 创建玩家飞机对象
    		playerPlane->draw();                      //绘制玩家飞机

    		while (1)                      //玩家飞机开始操作
    		{
				GetCommand();                           //获取ESCAPE是否按下
				if(stage.pause == 1)                            //如果按了ESCAPE，就进入暂停界面
        		{
            		putimage(0,0,&pauseImage);                //绘制暂停界面
					while(!CoverButton.button_quit)             //只要没按到QUIT
					{
						MouseListener();                         //获取鼠标
						if(stage.game == 1)           //如果按到了CONTINUE
						{
							putimage(0,0,&gameImage);             //绘制游戏背景
                            break;                      //退出获取鼠标的循环                                      
						}
						else if(stage.home == 1)             //如果按到了HOME
						{
							putimage(0,0,&startImage);         //绘制菜单背景
						 	goto HOMEMENU;           //跳出循环回到主菜单
						}
					}	
					if(CoverButton.button_quit)
					{
						goto CLOSE;
					}
        		}
        		BeginBatchDraw();
        		cleardevice();          // 清空画面
				putimage(0,0,&gameImage);
        		playerPlane->draw();    // 绘制玩家飞机
        		if (_kbhit())
				{
            		char key = _getch();    // 获取键盘输入
            		playerPlane->move(key); // 移动玩家飞机
					if (GetAsyncKeyState(VK_SPACE))           //创建子弹
                	{
						pBullet = new Bullet(playerPlane->getX(), playerPlane->getY()-10,1,5);
                		bulletList.push_back(pBullet);
             		}
				}	
        		for (bulletIter = bulletList.begin(); bulletIter != bulletList.end();bulletIter++)
				{
            		(*bulletIter)->drawBullet((*bulletIter)->getX(), (*bulletIter)->getY());
            		(*bulletIter)->moveBullet(); 
        		}
    			

				EndBatchDraw();
			}
		} 
    }
	CLOSE:
    closegraph();                        //按到QUIT直接结束
    return 0;
}

/* 					if (GetAsyncKeyState(VK_SPACE))           //创建子弹
                	{
						pBullet = new Bullet(playerPlane->getX(), playerPlane->getY()-10,5,5);
                		bulletList.push_back(pBullet);
             		}
        			for (bulletIter = bulletList.begin(); bulletIter != bulletList.end();bulletIter++)
					{
            			(*bulletIter)->drawBullet((*bulletIter)->getX(), (*bulletIter)->getY());
            			(*bulletIter)->moveBullet(); 
        			}   */

