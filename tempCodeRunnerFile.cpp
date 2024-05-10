/* #include <iostream>
#include <graphics.h>
#include <conio.h>
#include "Game.h"
#include "Operate.h"

struct Stage stage;
struct CoverButton CoverButton;

int main()
{
    IMAGE startImage, pauseImage, gameImage;
    initgraph(640, 800);
    loadimage(&startImage, "D:\\git0\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\git0\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\git0\\ace\\rs\\game.bmp");
    putimage(0, 0, &startImage);

    stage.pause = 0;
    stage.game = 0;
    stage.home = 1;
    CoverButton.button_continue = 0;
    CoverButton.button_quit = 0;
    CoverButton.button_home = 0;
    CoverButton.button_level1 = 0;
    CoverButton.button_level2 = 0;

    while (!CoverButton.button_quit)
    {
        MouseListener();
        if (stage.game == 1)
        {
            putimage(0, 0, &gameImage);
        }
        else if (stage.pause == 1)
        {
            putimage(0, 0, &pauseImage);
        }
        else if (stage.home == 1)
        {
            putimage(0, 0, &startImage);
        }
    }

    _getch();
    closegraph();
    return 0;
} */

/* int main()
{
    IMAGE startImage, pauseImage, gameImage;
    initgraph(640, 800);
    loadimage(&startImage, "D:\\git0\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\git0\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\git0\\ace\\rs\\game.bmp");
    putimage(0, 0, &startImage);
    stage.pause = 0;
    stage.game = 0;
    stage.home = 1;
    if (CoverButton.button_level1) //开始页面按下level 1
    {
         stage.pause = 0;
         stage.game = 1;
         stage.home = 0;
        putimage(0,0,&gameImage);
    // 按esc暂停不会写
    putimage(0,0,&pauseImage);
    if (CoverButton.button_quit)
    {
        closegraph();
        return 0;
    }
    else if (CoverButton.button_continue){
        putimage(0,0,&gameImage);
    }
    else if (CoverButton.button_home)
    {
        putimage(0,0,&startImage);
    }
}

    else if (CoverButton.button_level2)  //开始页面按下level 2
     {
        putimage(0,0,&gameImage);
        //按esc暂停不会写
        putimage(0,0,&pauseImage);
        if (CoverButton.button_quit)
        {
            closegraph();
            return 0;
        }
        else if (CoverButton.button_continue)
        {
            putimage(0,0,&gameImage);
        }
        else if (CoverButton.button_home)
        {
            putimage(0,0,&startImage);
        }
     }
    else if (CoverButton.button_quit)  //开始页面按下quit
    {
        closegraph();
        return 0;
    }
    _getch();
    closegraph();
    return 0;
} */

/* #include <conio.h>
#include "Plane.h"
int main()
{
    initgraph(1360, 760);                        // 初始化图形窗口
    Plane *playerPlane = new Plane(680, 380, 5); // 创建玩家飞机对象
    playerPlane->draw();
    while (1)
    {
        cleardevice();          // 清空画面
        playerPlane->draw();    // 绘制玩家飞机
        char key = _getch();    // 获取键盘输入
        playerPlane->move(key); // 移动玩家飞机
        playerPlane->draw();
        Sleep(10); // 等待一段时间，避免画面闪烁
    }
    _getch();
    closegraph(); // 关闭图形窗口
    return 0;
} */
