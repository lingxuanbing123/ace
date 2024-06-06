#pragma once
#include <time.h>
#include <graphics.h>
#define PI 3.14159265

#define WIDTH 640
#define HEIGHT 800

#define DEFAULT -1
#define WIDTH_ME 104
#define HEIGHT_ME 120
#define WIDTH_NORMAL 112
#define HEIGHT_NORMAL 79
#define WIDTH_GUARD 159
#define HEIGHT_GUARD 212
#define WIDTH_BOSS 372
#define HEIGHT_BOSS 315
#define WIDTH_QUICKER 190
#define HEIGHT_QUICKER 142
#define WIDTH_RAIDER 126
#define HEIGHT_RAIDER 108
#define WIDTH_BULLET_ME 40
#define WIDTH_BULLET_SSHOCKWAVE 62
#define HEIGHT_BULLET_SSHOCKWAVE 92
#define WIDTH_BULLET_LONG 40
#define HEIGHT_BULLET_LONG 89
#define WIDTH_BULLET_REDBALL 61
#define HEIGHT_BULLET_REDBALL 61
#define WIDTH_BULLET_RHOMBUS 20
#define HEIGHT_BULLET_RHOMBUS 20
#define WIDTH_BULLET_BOSSSHOCKWAVE 270
#define HEIGHT_BULLET_BOSSSHOCKWAVE 160
#define WIDTH_BOOM_1 150
#define HEIGHT_BOOM_1 150
#define WIDTH_MAP_1 680
#define HEIGHT_MAP_1 1024
#define HEIGHT_NUM 32
#define WIDTH_NUM 28
#define WIDTH_BULLET_ME_1 44
#define WIDTH_BULLET_ME_2 44
#define WIDTH_BULLET_ME_3 60
#define HEIGHT_BULLET_ME 184
#define SIZE_PROP 58
#define NORMAL 0
#define UPDATE 1
#define ULTRA 2
#define BOSS 1
#define QUICKER 2
#define RAIDER 3
#define GUARD 4
#define ME 5
#define NORMALB 6
#define ATTACK 0
#define INJURE 1
#define LONG 0
#define SSHOCKWAVE 1
#define REDBALL 2
#define RHOMBUS 3
#define BOSSSHOCKWAVE 4
#define LEFTARC 0
#define RIGHTARC 1
#define STRAIGHT 2
#define STOP 3

typedef struct NODE
{
    int x;         // x坐标
    int y;         // y坐标
    int blood;     // 血量
    int fullblood; // manxue
    int x0;        // 保存子弹射出时候的位置
    int y0;
    double theta;
    int direction; // 移动方向
    int fire_off;
    int ff_fire;    // 中间值
    int FireSwitch; // 敌机开火
    int width;      // 宽
    int height;     // 高
    int hitpoints;  // 伤害
    double speed;   // 移动速度
    double slowspeed;
    struct NODE *next;
    int invincible;
    int weaponlevel;
} Node;
typedef struct
{
    int up;
    int down;
    int left;
    int right;
} DIRECTION;           //方向结构体定义
typedef struct Boom
{
    int x;
    int y;
    int type;
    int size;
    int f_create;
    struct Boom *next;
} Boom;


struct Stage  //当前状态判定    使用0 1
{
    int pause;  //暂停
    int game1;  //关卡1中
    int game2;  //关卡2中
    int home;   //主菜单
    int choose;  //飞机选择
};
struct CoverButton    //按钮绘制 亮或者熄 使用0 1
{
    int button_level1;
    int button_level2;
    int button_quit;
    int button_continue;
    int button_home;
    int button_choose1;
    int button_choose2;
};

struct FRAME
{
    int f_total;
    int f_zawarudo;
    int f_resume;
    int f_pause;
};
extern FRAME Frame;
extern int score; // 得分

extern Boom *pBoom;
extern Node *pBullet;       // 子弹
extern Node *pBullet_Enemy; // 敌机子弹
extern Node *pEnemy;        // 敌机
extern Node *pMyself;       // 我机

extern int num[10];
extern int boss; // 是否存在boss
extern struct Stage stage;
extern struct CoverButton CoverButton;
