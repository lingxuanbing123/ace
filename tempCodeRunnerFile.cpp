#include <iostream>
#include <graphics.h>
#include <conio.h>

int main(){
    IMAGE background;
    initgraph(800, 900);
    loadimage(&background, "D:\\git0\\ace\\rs\\background.bmp");
    putimage(0,0,&background);
    _getch();
    closegraph();
    return 0;
}

