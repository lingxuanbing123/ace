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
#define CHOOSE1_SCOPE (m.x >=108 && m.x <= 256 && m.y >= 556 && m.y <= 604)
#define CHOOSE2_SCOPE (m.x >=400 && m.x <= 548 && m.y >= 556 && m.y <= 604)

//获取键盘事件
int GetCommand(void);
//获取鼠标事件
void MouseListener(void);
