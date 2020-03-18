#include "stdio.h"

#define SIZE 100

// 树的存储结构-孩子双亲表示法

typedef struct CTnode     // 孩子节点
{
    int child;       // 孩子节点的下标
    struct CTnode* next;
} CTnode;


typedef struct PTnode   // 双亲节点(表头结构)
{
    int data;
    int parent;
    CTnode* firstChild;
} PTnode;


typedef struct Tree
{
    PTnode tree[SIZE];   // 节点数组
    int r, n;
} Tree;