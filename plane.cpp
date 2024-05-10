/* plane.cpp */
#pragma once
#include "plane.h"

Plane::Plane() {
    color = RGB(255, 0, 0); // 设置飞机颜色为红色
}

void Plane::draw() {
    // 绘制飞机的矩形身体
    setfillcolor(color);
    solidrectangle(x - 20, y, x + 20, y + 30);

    // 绘制飞机的两个引擎
    setfillcolor(RGB(0, 0, 255)); // 设置引擎颜色为蓝色
    solidrectangle(x - 10, y + 30, x - 5, y + 40); // 左引擎
    solidrectangle(x + 5, y + 30, x + 10, y + 40); // 右引擎
}

void Plane::move(char key_hit) {
    switch (key_hit) {
    case 'w':
    case 'W':
        if (y > 500) y -= speed;
        break;
    case 's':
    case 'S':
        if (y < 720) y += speed;
        break;
    case 'a':
    case 'A':
        if (x > 0) x -= speed;
        break;
    case 'd':
    case 'D':
        if (x < 1300) x += speed;
        break;
    default:
        break;
    }
}

/* main.cpp */
#include <conio.h>
#include "plane.h"

int main() {
    initgraph(1360, 760);       // 初始化图形窗口
    Plane playerPlane;          // 创建玩家飞机对象

    while (!kbhit()) {
        cleardevice();          // 清空画面
        playerPlane.draw();     // 绘制玩家飞机
        char key = _getch();    // 获取键盘输入
        playerPlane.move(key);  // 移动玩家飞机
        Sleep(50);              // 等待一段时间，避免画面闪烁
    }

    closegraph();               // 关闭图形窗口
    return 0;
}
