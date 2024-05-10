#include "Operate.h"
#include <iostream>
#include <conio.h>
//获取键盘事件
int GetCommand(void)												//得到按键，上下左右
{
	int c = 0;
	if (GetAsyncKeyState('A') & 0x8000)		c |= CMD_LEFT;
	if (GetAsyncKeyState('D') & 0x8000)	c |= CMD_RIGHT;
	if (GetAsyncKeyState('W') & 0x8000)		c |= CMD_UP;
	if (GetAsyncKeyState('S') & 0x8000)		c |= CMD_DOWN;
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) 
	{
		c |= CMD_ESC;
		stage.pause = 1;
		stage.game = 0;
		stage.home = 0;
	}
	return c;
}
//鼠标消息
void MouseListener(void) {				//获取当前焦点窗口句柄
	MOUSEMSG m;                               //鼠标
//home界面中间三个按钮LEVEL1，LEVEL2,QUIT
//pause界面三个按钮CONTINUE,HOME,QUIT

	if (MouseHit() && stage.pause) {                         //如果按下鼠标且在暂停界面
		m = GetMouseMsg();                               //获取鼠标信息
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:                              //鼠标按下 在不同按钮处，CoverButton结构体内变量有不同值
				if (QUIT_SCOPE)
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
				if (QUIT_SCOPE)
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
			if (QUIT_SCOPE)
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
			else if (QUIT_SCOPE)
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
