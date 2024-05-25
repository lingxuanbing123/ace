#pragma once
#include <graphics.h>

class Prop
{
public:
    Prop(); // 构造函数
    void drawProp1(); 
    void drawProp2();
    void prop_generate();   //道具生成
    void prop_acquire();    //道具获得
    void playerPlane_shield();
    void playerPlane_accelerator();
    int getX();        // 获取x
    int getY();        // 获取y
    int getR();
    bool &getModel();   //获取道具类型
private:
    COLORREF color = RGB(255, 0, 0); // 设置道具颜色为红色; 
    int x;
    int y; 
    int r;
    bool model;                          //道具类型
};


