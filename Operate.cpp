#include "Operate.h"
//获取键盘事件
int GetCommand(void)												//得到按键
{
	int c = 0;
	if (GetAsyncKeyState('A') & 0x8000)		c |= CMD_LEFT;
	if (GetAsyncKeyState('D') & 0x8000)	c |= CMD_RIGHT;
	if (GetAsyncKeyState('W') & 0x8000)		c |= CMD_UP;
	if (GetAsyncKeyState('S') & 0x8000)		c |= CMD_DOWN;
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) c |= CMD_SHIFT;
	return c;
}
//鼠标消息
void MouseListener(void) {
	HWND hwnd = GetHWnd();										//获取绘图窗口句柄
	HWND hwnd_now = GetForegroundWindow();						//获取当前焦点窗口句柄
	MOUSEMSG m;
	HCURSOR hcur;
    