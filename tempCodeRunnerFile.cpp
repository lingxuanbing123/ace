#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "Game.h"
int main(){
    IMAGE startImage,pauseImage,gameImage;
    initgraph(640, 800);
    loadimage(&startImage, "D:\\lingxuanbing\\ace\\rs\\start.bmp");
    loadimage(&pauseImage, "D:\\lingxuanbing\\ace\\rs\\pause.bmp");
    loadimage(&gameImage, "D:\\lingxuanbing\\ace\\rs\\game.bmp");
    putimage(0,0,&startImage);   
    stage.pause = 0;
	stage.game = 0;
	stage.home = 1;
    if (CoverButton.button_level1) //开始页面按下level 1
    {
         stage.pause = 0;
	     stage.game = 1;
	     stage.home = 0;
        putimage(0,0,&gameImage);
        //按esc暂停不会写
        putimage(0,0,&pauseImage);
        if (CoverButton.button_quit) 
        {
            closegraph();
            return 0;
        }
        else if (CoverButton.button_continue)   
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
}
