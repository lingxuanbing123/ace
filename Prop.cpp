#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

auto hitTime = std::chrono::steady_clock::now(); // 记录时间

Prop::Prop()                //道具获取相关参数
{
    color = RGB(255, 0, 0); // 设置道具颜色为红色
    model=0;
}

// 生成随机数的函数
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 获得道具的函数
void prop_acquire() {
    if(model==0){
    playerPlane_shield();
} 
    }
    else if(model==1)
    if (isColliding(player, item)) 
    {
   playerPlane_accelerator();
} 
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
            drawProp1();       //护盾
            model=0;
            break;
        case 2:
            drawProp2();      //加速
            model=1;
            break;       
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

void playerPlane_shield()               //护盾效果：五秒无敌
{
     while (true) {
        if (isColliding(player, item)) {
            invincible = true; // 己方飞机被击中，进入无敌状态
            hitTime = std::chrono::steady_clock::now(); // 更新被击中时间
        } else if (invincible) {
            auto now = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - hitTime);
            if (duration.count() >= 5) {
                invincible = false; // 超过5秒，取消己方飞机的无敌状态
            }
        }       
    }
}

void playerPlane_accelerator()          //加速效果：移速增加
{
    if(playerPlane.speed<=40)
    playerPlane.speed+=2;
}

struct Rectangle {
    int x, y; // 左上角坐标
    int width, height; // 宽度和高度
};

Rectangle player = {playerPlane.getX(), playerPlane.getY(), 50, 50}; // 己方飞机的位置和大小
Rectangle item = {Prop_x, Prop_y, 20, 20}; // 道具的位置和大小

bool isColliding(const Rectangle& a, const Rectangle& b) {
    if (a.x + a.width < b.x || b.x + b.width < a.x) {
        return false; // 水平方向没有重叠
    }
    if (a.y + a.height < b.y || b.y + b.height < a.y) {
        return false; // 垂直方向没有重叠
    }
    return true; // 发生碰撞
}




