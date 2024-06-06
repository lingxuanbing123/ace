#pragma once
#include <Windows.h>
#include "Game.h"
#define CMD_ESC 16  //ESC键，在游戏中进入暂停界面

#define QUIT1_SCOPE (m.x >= 223 && m.x <= 419 && m.y >= 597 && m.y <= 667)//主菜单的退出
#define QUIT2_SCOPE (m.x >= 140 && m.x <= 509 && m.y >= 551 && m.y <= 635)//暂停界面的退出
#define LEVEL1_SCOPE (m.x >=223 && m.x <= 419 && m.y >=362 && m.y <= 432)//主菜单界面关卡1
#define LEVEL2_SCOPE (m.x >=223 && m.x <= 419 && m.y >=481 && m.y <= 551)//主菜单界面关卡2
#define CONTINUE_SCOPE (m.x >=140 && m.x <= 509 && m.y >= 183 && m.y <= 267)//暂停界面继续游戏
#define HOME_SCOPE (m.x >=140 && m.x <= 509  && m.y >= 365 && m.y <= 449)//暂停界面返回主菜单
#define CHOOSE1_SCOPE (m.x >=108 && m.x <= 252 && m.y >= 552 && m.y <= 600)//选择界面选择飞机一
#define CHOOSE2_SCOPE (m.x >=400 && m.x <= 544 && m.y >= 552 && m.y <= 600)//选择界面选择飞机二

//获取键盘事件
int GetCommand(void);
//获取鼠标事件
void MouseListener(void);
int choose;
/*鼠标信息结构体
struct MOUSEMSG
{
	UINT uMsg;			// 当前鼠标消息
	bool mkCtrl;		// Ctrl 键是否按下
	bool mkShift;		// Shift 键是否按下
	bool mkLButton;		// 鼠标左键是否按下
	bool mkMButton;		// 鼠标中键是否按下
	bool mkRButton;		// 鼠标右键是否按下
	int x;				// 当前鼠标 x 坐标（物理坐标）
	int y;				// 当前鼠标 y 坐标（物理坐标）
	int wheel;			// 鼠标滚轮滚动值
};*/