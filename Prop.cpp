#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

Prop::Prop()                //道具获取相关参数
{
    color = RGB(255, 0, 0); // 设置道具颜色为红色
}

// 生成随机数的函数
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 获得道具的函数
void prop_acquire() {
    
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
            break;
        case 2:
            drawProp2();      //加速
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