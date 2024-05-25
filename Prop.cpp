#include <stdio.h>
#include "Prop.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
bool isColliding(Prop a, Plane b) 
{
    if (a.getX() + a.getR() < b.getX()-50|| b.getX() +50 < a.getX()-a.getR()) {
        return false; // 水平方向没有重叠
    }
    if (a.getY() + a.getR() < b.getY()-50|| b.getY() +50 < a.getY()-a.getR()) {
        return false; // 垂直方向没有重叠
    }
    return true; // 发生碰撞
} 
auto hitTime = std::chrono::steady_clock::now(); // 记录时间
Prop prop= Prop();
 Plane *playerPlane = new Plane(320, 760, 5); // 创建玩家飞机对象

Prop::Prop()
{
    model=0;
    r=10;
}

// 生成随机数的函数
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Prop::drawProp1()
{
    srand(time(NULL));                  // 设置随机种子
    int Prop_x = rand() % 561 + 40;     // 生成40-600之间的随机数
    int Prop_y = rand() % 701 + 50;     // 生成50-750之间的随机数
    setfillcolor(color);
    circle(Prop_x, Prop_y, 10);         // 绘制道具的圆形身体
}

 
void Prop::drawProp2()
{
    srand(time(NULL));                  // 设置随机种子
    int Prop_x = rand() % 561 + 40;     // 生成40-600之间的随机数
    int Prop_y = rand() % 701 + 50;     // 生成50-750之间的随机数
    setfillcolor(color);
    circle(Prop_x, Prop_y, 10);         // 绘制道具的圆形身体
}

 
 void Prop::playerPlane_shield()               //护盾效果：五秒无敌
{
     while (true) {
        if (isColliding(prop, *playerPlane)) {
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
}

void Prop::playerPlane_accelerator()          //加速效果：移速增加
{
    if(playerPlane->getSpeed()<=40)
    playerPlane->setSpeed();
}




// 获得道具的函数
void Prop::prop_acquire() 
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
}

void Prop::prop_generate()
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));  // 等待10秒
        srand(time(0));                                         // 生成随机数
    int randomNumber = generateRandomNumber(1, 2);              // 根据随机数生成道具
    switch (randomNumber) {
        case 1:
            prop.drawProp1();       //护盾
            model=0;
            break;
        case 2:
            prop.drawProp2();      //加速
            model=1;
            break;       
        }
        }
}
