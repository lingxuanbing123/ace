#pragma once
#include <Windows.h>
#include "Game.h"
#define CMD_UP 1  //上 仅用W
#define CMD_DOWN 2  //下 仅用S
#define CMD_LEFT 4  //左仅 用A
#define CMD_RIGHT 8  //右 仅用D
#define CMD_ESC 16  //ESC键，在游戏中进入暂停界面

#define QUIT_SCOPE (m.x >= 215 && m.x <= 425 && m.y >= 450 && m.y <= 500)//主菜单 或 暂停界面退出
#define LEVEL1_SCOPE (m.x >=215 && m.x <= 425 && m.y >=350 && m.y <= 400)//主菜单界面关卡1
#define LEVEL2_SCOPE (m.x >=215 && m.x <= 425 && m.y >=400 && m.y <= 450)//主菜单界面关卡2
#define CONTINUE_SCOPE (m.x >=215 && m.x <= 425 && m.y >= 350 && m.y <= 400)//暂停界面继续游戏
#define HOME_SCOPE (m.x >=215 && m.x <= 425  && m.y >= 400 && m.y <= 450)//暂停界面返回主菜单

//获取键盘事件
int GetCommand(void);
//获取鼠标事件
void MouseListener(void);

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