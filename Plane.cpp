
#include "Plane.h"
#include "Operate.h"
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
Plane::Plane()
{
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
    this->x = x;
    this->y = y;
    this->speed = speed;
}

Plane::Plane(int x, int y, int speed){}
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





#include <conio.h>
#include "Plane.h"
int main()
{
    initgraph(640, 800);                        // 初始化图形窗口
    IMAGE startImage, pauseImage, gameImage;
    loadimage(&startImage, "D:\\git0\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\git0\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\git0\\ace\\rs\\game.bmp");
    putimage(0, 0, &startImage);
    Plane *playerPlane = new Plane(320, 380, 5); // 创建玩家飞机对象
    playerPlane->draw();
    while (1)
    {
        BeginBatchDraw();
        cleardevice();          // 清空画面
        putimage(0, 0, &startImage);
        playerPlane->draw();    // 绘制玩家飞机
        if (_kbhit()){
            char key = _getch();    // 获取键盘输入
            playerPlane->move(key); // 移动玩家飞机
        }
        EndBatchDraw();
    }
    _getch();
    closegraph(); // 关闭图形窗口
    return 0;
} 