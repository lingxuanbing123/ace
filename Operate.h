#pragma once
#include <Windows.h>
#include "Game.h"
#define CMD_UP 1  //上 仅用W
#define CMD_DOWN 2  //下 仅用S
#define CMD_LEFT 4  //左仅 用A
#define CMD_RIGHT 8  //右 仅用D
#define CMD_SHIFT 16  //暂时保留 不知道干什么
#define BACK_SCOPE (m.x >= 50 && m.x <= 150 && m.y >= 50 && m.y <= 150)//鼠标在这个范围内就返回,菜单则返回游戏，游戏 则返回菜单
#define QUIT_SCOPE (m.x >= 215 && m.x <= 425 && m.y >= 450 && m.y <= 500)//鼠标在这个范围内就退出游戏
#define LEVEL_SCOPE (m.x >=215 && m.x <= 425 && m.y >=350 && m.y <= 400)//鼠标在这个范围内就选择关卡 或 重新开始游戏

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