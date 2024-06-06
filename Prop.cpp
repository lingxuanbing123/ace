#include <stdio.h>
#include "Prop.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include "Game.h"
/* bool isColliding(Prop a, int x,int y)
{
    if (a.getX() + a.getR() < x|| x +46 < a.getX()-a.getR()) {
        return false; // 水平方向没有重叠
    }
    if (a.getY() + a.getR() < y|| y +40 < a.getY()-a.getR()) {
        return false; // 垂直方向没有重叠
    }
    return true; // 发生碰撞
}  */

Prop::Prop()
{
    this->x = x;
    this->y = y;
    this->model = model;
    loadimage(&prop1, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop1.png");
    loadimage(&prop2, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop2.png");
}
Prop::Prop(int x, int y,int r,int model){
    this->x = x;
    this->y = y;
    this->r = r;
    this->model = model;
    loadimage(&prop1, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop1.png");
    loadimage(&prop12, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop12.png");
    loadimage(&prop2, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop2.png");
    loadimage(&prop22, "D:\\Git warehouse\\github\\ace\\rs\\image\\prop22.png");
}

// 生成随机数的函数
/* int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
} */

void Prop::drawProp()
{
    if (this->model == 1){
        putimage(this->x, this->y, &prop12,SRCAND);
        putimage(this->x, this->y, &prop1,SRCPAINT);
    }
    else if (this->model == 2){
        putimage(this->x, this->y, &prop22, SRCAND);
        putimage(this->x, this->y, &prop2, SRCPAINT);
    }
}

void Prop::drawProp2()
{
    if(r == 1){
    putimage(this->x, this->y, &prop2);
    }
}
int &Prop::getX()
{
    return x;
}

int &Prop::getY()
{
    return y;
}

int &Prop::getModel()
{
    return model;
}

/*  void Prop::playerPlane_shield()               //护盾效果：五秒无敌
{
     while (true) {
        if (isColliding(prop, x,y)) {
            playerPlane->invincible = true; // 己方飞机被击中，进入无敌状态
            hitTime = std::chrono::steady_clock::now(); // 更新被击中时间
        } else if (playerPlane->invincible) {
            auto now = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - hitTime);
            if (duration.count() >= 5) {
                playerPlane->invincible = false; // 超过5秒，取消己方飞机的无敌状态
            }
        }
    }
} */

/* void Prop::playerPlane_accelerator()          //加速效果：移速增加
{
    if(playerPlane->getSpeed()<=40)
    playerPlane->setSpeed();
} */

// 获得道具的函数
/* void Prop::prop_acquire()
{
    if(prop.getModel()==0)
    {
    prop.playerPlane_shield();
    }
    else if(prop.getModel()==1)
    if (isColliding(prop, *playerPlane))
    {
   prop.playerPlane_accelerator();
}
} */

/* void Prop::prop_generate()
{
    while (true)
    {
        srand(time(0));                                        // 生成随机数
        int randomNumber = generateRandomNumber(1, 2);         // 根据随机数生成道具
        switch (randomNumber)
        {
        case 1:
            prop.drawProp1(); // 护盾
            model = 0;
            break;
        case 2:
            prop.drawProp2(); // 加速
            model = 1;
            break;
        }
    }
} */
