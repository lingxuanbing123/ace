<<<<<<< Updated upstream
/* plane.h */
#pragma once
#include <graphics.h>

class Plane {
public:
    int x = 650, y = 720;        // �ɻ���ʼ����
    int speed = 10;              // �ɻ��ƶ��ٶ�

    Plane();                     // ���캯��
    void draw();                 // ���Ʒɻ�
    void move(char key_hit);     // �ƶ��ɻ������ݰ�����Ӧ

private:
    COLORREF color;              // �ɻ���ɫ
}; 
=======
>>>>>>> Stashed changes
