#include <stdio.h>
#include "Prop.h"
#include "Plane.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include "Game.h"

Prop::Prop()
{
    this->x = x;
    this->y = y;
    this->model = model;
    loadimage(&prop1, "D:\\git0\\ace\\rs\\image\\prop1.png");
    loadimage(&prop2, "D:\\git0\\ace\\rs\\image\\prop2.png");
}
Prop::Prop(int x, int y, int r, int model) // 获取相关信息
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->model = model;
    loadimage(&prop1, "D:\\git0\\ace\\rs\\image\\prop1.png");
    loadimage(&prop12, "D:\\git0\\ace\\rs\\image\\prop12.png");
    loadimage(&prop2, "D:\\git0\\ace\\rs\\image\\prop2.png");
    loadimage(&prop22, "D:\\git0\\ace\\rs\\image\\prop22.png");
}

void Prop::drawProp() // 根据model画道具
{
    if (this->model == 1)
    {
        putimage(this->x, this->y, &prop12, SRCAND);
        putimage(this->x, this->y, &prop1, SRCPAINT);
    }
    else if (this->model == 2)
    {
        putimage(this->x, this->y, &prop22, SRCAND);
        putimage(this->x, this->y, &prop2, SRCPAINT);
    }
}

void Prop::drawProp2()
{
    if (r == 1)
    {
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
