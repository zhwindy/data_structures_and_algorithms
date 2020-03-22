#include "stdio.h"

#define SIZE 10

typedef struct link
{
    int index;
    struct link* next;
}Link;

typedef struct vex{
    char data;
    Link* next;
} Vex;

// 图的存储->邻接链表
typedef struct graph{
    Vex vex[SIZE];
    int vexSize;   // 图的定点个数
    int EdgeSize;   // 图的边个数
} Graph;

