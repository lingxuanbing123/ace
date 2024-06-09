#pragma once
#include <graphics.h>
#include "Game.h"

class Prop
{
public:
    Prop(); // 构造函数
    Prop(int x, int y, int r, int model);
    void drawProp();
    void drawProp2(); // 画不同模型
    int &getX();      // 获取x
    int &getY();      // 获取y
    int &getModel();  // 判断不同模型
protected:
    IMAGE prop1, prop12, prop2, prop22;

private:
    COLORREF color = RGB(255, 0, 0); // 设置道具颜色为红色;
    int x;
    int y;
    int r;
    int model;
};
