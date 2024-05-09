#pragma once
#include <Windows.h>
#include "Game.h"
#define CMD_UP 1  //上 仅用W
#define CMD_DOWN 2  //下 仅用S
#define CMD_LEFT 4  //左仅 用A
#define CMD_RIGHT 8  //右 仅用D
#define CMD_SHIFT 16  //暂时保留 不知道干什么
#define PAUSE_SCOPE (m.x >= 0 && m.x <= 110 && m.y >= HEIGHT - 39 && m.y <= HEIGHT - 10 || m.x >= 110 && m.x <= 130 && m.y >= HEIGHT - 39 && m.y <= -1.45 * m.x + HEIGHT + 149.5)   //鼠标在这个范围内就暂停
#define RESUME_SCOPE (m.x >= 489 && m.x <= 489 + 91 && m.y >= 378 && m.y <= 419) //鼠标在这个范围内就重新开始游戏
#define BACK_SCOPE (m.x >= 50 && m.x <= 141 && m.y >= 378 && m.y <= 419)//鼠标在这个范围内就返回，第一个返回按键
#define START_SCOPE (m.x >= 215 && m.x <= 425 && m.y >= 500 && m.y <= 564)//鼠标在这个范围内就开始游戏
#define QUIT_SCOPE (m.x >= 215 && m.x <= 425 && m.y >= 650 && m.y <= 700)//鼠标在这个范围内就退出游戏
#define BACK2_SCOPE (m.x >= 193 && m.x <= 448 && m.y >= 693 && m.y <= 762)//

//获取键盘事件
int GetCommand(void);
//获取鼠标事件
void MouseListener(void);