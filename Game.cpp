#include <iostream>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#include <graphics.h>

// esayx
#include "Game.h"
#include "Prop.h"
#include "Plane.h"
#include "Shoot.h"
#include "BulletEnemy.h"
#include "Boom.h"
#include "Bullet.h"
#include "Interface.h"
#include "PlaneEnemy.h"
#include "Operate.h"
#include "Score.h"

#pragma comment(lib, "MSIMG32.LIB")
#pragma comment(lib, "Winmm.lib")

int score; // 得分
typedef int SOUND;

Prop *prop;
Boom *pBoom;
Node *pBullet;   // 子弹
Node *pBullet_E; // 敌机子弹
Node *pEnemy;    // 敌机
Node *pMyself;   // 我机

int num[10];  // 得分每一位数,用全局以方便清零
int boss = 0; // 是否存在boss
FRAME Frame;
struct CoverButton CoverButton;
struct Stage stage;
double lct = 0; // 地图坐标

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
void RotateImage(IMAGE *pTo, IMAGE *pFrom, double rad)
{
/*     IMAGE *pWorking = GetWorkingImage();
    SetWorkingImage(pFrom);
    int iWidth = getwidth();
    int iHeight = getheight(); // 获取原图长宽
    while (rad > 2 * PI)       // 化简弧度
        rad -= 2 * PI;

    double pad = rad; // 处理弧度
    if (pad > PI / 2 && pad <= PI)
    {
        pad -= PI / 2;
        pad = PI / 2 - pad;
    }
    else if (pad > PI && pad <= PI / 2 * 3)
    {
        pad -= PI;
    }
    else if (pad > PI / 2 * 3 && pad <= PI * 2)
    {
        pad -= PI / 2 * 3;
        pad = PI / 2 - pad;
    }

    int tWidth = int(iWidth * cos(pad) + iHeight * sin(pad));
    int tHeight = int(iHeight * cos(pad) + iWidth * sin(pad)); // 计算新图大小

    int iMinX = -(iWidth / 2), iMinY = -(iHeight / 2);
    int iMaxX = iMinX + iWidth, iMaxY = iMinY + iHeight; // 计算原图最小（大）坐标

    int tMinX = -(tWidth / 2), tMinY = -(tHeight / 2);
    int tMaxX = tMinX + tWidth, tMaxY = tMinY + tHeight; // 计算新图最小（大）坐标

    setorigin(-iMinX, -iMinY); // 设置图片中心为原点

    SetWorkingImage(NULL);
    pTo->Resize(tWidth, tHeight); // 初始化新图

    DWORD *dst = GetImageBuffer(pTo);
    DWORD *src = GetImageBuffer(pFrom); // 获取新图、原图的缓冲区

    SetWorkingImage(pTo);
    for (int y1 = 0; y1 < tHeight; y1++)
    {
        for (int x1 = 0; x1 < tWidth; x1++)
            dst[x1] = 0x00000000;
        dst += tWidth;
    }

    SetWorkingImage(pWorking);
    for (int y1 = 0; y1 < tHeight; y1++) 
        dst -= tWidth;

    for (int y1 = tMinY; y1 < tMaxY; y1++)
    {
        for (int x1 = tMinX; x1 < tMaxX; x1++)
        {
            int x = int(x1 * cos(rad) - y1 * sin(rad));
            int y = int(x1 * sin(rad) + y1 * cos(rad)); 

            int sxy = (iHeight - (y - iMinY) - 1) * iWidth + (x - iMinX);
            int dxy = (tHeight - (y1 - tMinY) - 1) * tWidth + (x1 - tMinX); 

            if (x >= iMinX && x < iMaxX && y >= iMinY && y < iMaxY)
                dst[dxy] = src[sxy];
        }
    }

    SetWorkingImage(pFrom);
    setorigin(0, 0);
    SetWorkingImage(pWorking); // 还原原图坐标 */
}
void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg)
{
    DWORD *dst = GetImageBuffer(dstimg);
    DWORD *src = GetImageBuffer(srcimg);
    int src_width = srcimg->getwidth();
    int src_height = srcimg->getheight();
    int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
    int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());
    int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;
    int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;
    if (x < 0)
    {
        src += -x;
        iwidth -= -x;
        x = 0;
    }
    if (y < 0)
    {
        src += src_width * -y;
        iheight -= -y;
        y = 0;
    }
    dst += dst_width * y + x;
    for (int iy = 0; iy < iheight; iy++)
    {
        for (int ix = 0; ix < iwidth; ix++)
        {
            int sa = ((src[ix] & 0xff000000) >> 24);
            int sr = ((src[ix] & 0xff0000) >> 16);
            int sg = ((src[ix] & 0xff00) >> 8);
            int sb = src[ix] & 0xff;
            int dr = ((dst[ix] & 0xff0000) >> 16);
            int dg = ((dst[ix] & 0xff00) >> 8);
            int db = dst[ix] & 0xff;
            dst[ix] = ((sr + dr * (255 - sa) / 255) << 16) | ((sg + dg * (255 - sa) / 255) << 8) | (sb + db * (255 - sa) / 255);
        }
        dst += dst_width;
        src += src_width;
    }
}
void Delete(int flag, int x, int y)
{
    Node *p;
    Node *ptr;
    Boom *pb; 
    Boom *ptrb;
    switch (flag)
    {
    case 0:
        p = pEnemy->next; 
        ptr = pEnemy;
        while (p != NULL)
        {
            if (p->y >= HEIGHT || (p->x == x && p->y == y))
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next; 
        }
        break;
    case 1:
        p = pBullet->next; 
        ptr = pBullet;

        while (p != NULL)
        { 

            if (p->y <= 0 || (p->x == x && p->y == y))
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next; 
        }
        break;

    case 2:
        p = pBullet_E->next; 
        ptr = pBullet_E;
        while (p != NULL)
        { 

            if (p->y >= HEIGHT || p->y <= 0 || (p->x == x && p->y == y))
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next;
        }
        break;
    case 3:
        pb = pBoom->next; 
        ptrb = pBoom;
        while (pb != NULL)
        { 

            if (pb->x == x && pb->y == y)
            {
                ptrb->next = pb->next;
                free(pb);
                pb = nullptr;
            }
            else
                ptrb = pb;
            pb = ptrb->next; 
        }
        break;
    }
}
void Delete(int flag)
{
    Node *p;
    Node *ptr;
    Boom *pb, *ptrb;
    switch (flag)
    {
    case 0:
        p = pEnemy->next; 
        ptr = pEnemy;
        while (p != NULL)
        { 
            if (p->y >= HEIGHT || p->x < -100 || p->x > WIDTH + 100)
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next; 
        }
        break;
    case 1:
        p = pBullet->next; 
        ptr = pBullet;

        while (p != NULL)
        { 

            if (p->y <= -p->height)
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next; 
        }
        break;

    case 2:
        p = pBullet_E->next; 
        ptr = pBullet_E;
        while (p != NULL)
        { 

            if (p->y > HEIGHT || p->y < -80 || p->x < -50 || p->x > WIDTH)
            {
                ptr->next = p->next;
                free(p); 
                p = nullptr;
            }
            else
                ptr = p;
            p = ptr->next; 
        }
        break;
    case 3:
        p = pBullet->next; 
        ptr = pBullet;
        while (p != NULL)
        { 
            ptr->next = p->next;
            free(p); 
            p = nullptr;
            p = ptr->next; 
        }

        p = pEnemy->next; 
        ptr = pEnemy;
        while (p != NULL)
        { 
            ptr->next = p->next;
            free(p); 
            p = nullptr;
            p = ptr->next; 
        }

        p = pBullet_E->next; 
        ptr = pBullet_E;
        while (p != NULL)
        {
            ptr->next = p->next;
            free(p);
            p = nullptr;
            p = ptr->next; 
        }

        pb = pBoom->next; 
        ptrb = pBoom;
        while (pb != NULL)
        { 
            ptrb->next = pb->next;
            free(pb);
            pb = nullptr;
            pb = ptrb->next; 
        }
        break;
    }
}

// 将得分每一位的数字放在数组里
int digitofscore(void)
{
    int x = score;
    int i = 0;
    while (x > 0)
    {
        num[i] = x % 10;
        x /= 10;
        i++;
    }
    return i;
}
// 创建链表
void CreateList(void)
{
    pEnemy = (Node *)malloc(sizeof(Node)); // 给敌机头指针分配内存
    pEnemy->next = NULL;

    pBullet = (Node *)malloc(sizeof(Node)); // 给子弹分配内存
    pBullet->next = NULL;

    pBullet_E = (Node *)malloc(sizeof(Node)); // 给子弹分配内存
    pBullet_E->next = NULL;

    pMyself = (Node *)malloc(sizeof(Node)); // 我机头指针分配内存
    pMyself->x = WIDTH / 2 - WIDTH_ME / 2;  // 初始坐标
    pMyself->y = HEIGHT - 200;
    pMyself->blood = 300;
    pMyself->next = NULL;
    pMyself->width = WIDTH_ME;
    pMyself->height = HEIGHT_ME;
    pMyself->invincible = 0;
    pMyself->weaponlevel = 1;
    pMyself->speed = 5;
    pMyself->slowspeed = 2;

    pBoom = (Boom *)malloc(sizeof(Boom));
    pBoom->next = NULL;

    prop = (Prop *)malloc(sizeof(Prop));
    prop->next = NULL;
}

