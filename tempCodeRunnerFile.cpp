#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "Game.h"
int main()
{
    IMAGE background;
    initgraph(640, 640);
    loadimage(&background, "E:\\test\\ace\\rs\\background.bmp");
    putimage(0,0,&background);
    _getch();
    closegraph();
    return 0;
}
