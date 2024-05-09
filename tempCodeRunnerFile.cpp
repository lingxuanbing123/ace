#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "Game.h"
int main()
{
    IMAGE background;
    initgraph(WIDTH, HEIGHT);
    loadimage(&background, "D:\\git0\\ace\\rs\\background.bmp");
    putimage(0, 0, &background);
    _getch();
    closegraph();
    return 0;
}
