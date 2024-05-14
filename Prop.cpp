// 未来得及采用的prop，v2需完善

/* #include "Prop.h"
#include "Game.h"

void upSpeed();

void drawProp(int x, int y) // 绘制道具
{
    setfillcolor(YELLOW);
    solidcircle(x, y, 0.5 * SIZE_PROP);
}

void Addprop(int flag)
{
    Prop *p;
    switch (flag)
    {
    case SPEEDUP:
        p = (Prop *)malloc(sizeof(Prop));
        p->type = SPEEDUP;
        p->x = rand() % (WIDTH - SIZE_PROP);
        p->y = -SIZE_PROP;
        p->next = prop->next;
        prop->next = p;
        break;
    }
}
void Move_prop(void)
{
    Prop *p = prop->next;
    while (p != NULL)
    {
        switch (p->type)
        {
            case SHIELD:case HEALTHPOT:case BOMB:case BOMBS:
        case SPEEDUP:
            p->y = ; // 移动道具，待补充
            break;
        }
        p = p->next;
    }
}
void Paint_prop(void)
{
    Prop *p = prop->next;
    while (p != NULL)
    {
        switch (p->type)
        {
        case SPEEDUP:
        {
            Draw_prop(p->x, p->y);
            break;
        }
        }
        p = p->next;
    }
}
void DeletePropB(int x, int y)
{
    Prop *p = prop->next;
    Prop *ptr = prop;

    while (p != NULL)
    {
        if (p->x == x && p->y == y)
        {
            ptr->next = p->next;
            free(p);
            p = nullptr;
        }
        else
            ptr = p;
        p = ptr->next;
    }
}
void DeletePropA(void)
{
    Prop *p = prop->next;
    Prop *ptr = prop;
    while (p != NULL)
    {
        ptr->next = p->next;
        free(p);
        p = nullptr;
        p = ptr->next;
    }
}
void Get_prop(void)
{
    Prop *p = prop->next;
    while (p != NULL)
    {
        if (p->x >= pMyself->x - SIZE_PROP / 2 &&
            p->x <= pMyself->x + SIZE_PROP / 2 &&
            p->y >= pMyself->y - SIZE_PROP / 2 && p->y <= pMyself->y + HEIGHT_ME + SIZE_PROP / 2)
        {
            switch (p->type)
            {
            case SPEEDUP:
                upSpeed();
                break;
            }
            DeletePropB(p->x, p->y);
            p = prop->next;
        }
        else
            p = p->next;
    }
} */
