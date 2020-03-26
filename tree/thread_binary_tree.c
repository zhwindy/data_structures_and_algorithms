#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0

typedef char ElemType;

typedef enum{Link, Thread} PointTag;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    PointTag ltag;
    PointTag rtag;
}BiTNode, *BiThrTree;

BiThrTree pre;

// 构造一颗二叉树,按前序遍历序列
void CreateThrBiTree(BiThrTree* root)
{
    char c;
    scanf("%c", &c);
    if (c == '#')
    {
        (*root) = NULL;
    }
    else
    {
        *root = (BiThrTree)malloc(sizeof(BiTNode));
        (*root)->data = c;
        (*root)->ltag = Link;
        (*root)->rtag = Link;
        CreateThrBiTree(&(*root)->lchild);
        CreateThrBiTree(&(*root)->rchild);
    }
    
}

void InBiTreeThreading(BiThrTree root)
{
    if (root)
    {
        InBiTreeThreading(root->lchild);
        // 处理节点
        if (!root->lchild)
        {
            root->ltag = Thread;
            root->lchild = pre;
        }

        if (!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = root;
        }

        pre = root;

        InBiTreeThreading(root->rchild);
    }
}

int InOrderTravelThreading(BiThrTree* p, BiThrTree root)
{
    *p = (BiThrTree)malloc(sizeof(BiTNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if (!root)
    {
        (*p)->lchild = *p;
        return OK;
    }
    (*p)->lchild = root;
    pre = (*p);
    InBiTreeThreading(root);

    pre->rtag = Thread;
    pre->rchild = *p;
    (*p)->rchild = pre;

    return OK;
}

// 非递归遍历线索二叉树
void InOrderTravel(BiThrTree root)
{
    BiThrTree p;
    p = root->lchild;
    while (p != root)
    {
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        printf("%c", p->data);
        while (p->rtag == Thread && p->rchild != root)
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    printf("\n");
}

// 递归遍历二叉树-中序遍历
void InOrderTravelBiTree(BiThrTree root)
{
    if (root)
    {
        InOrderTravelBiTree(root->lchild);
        printf("%c", root->data);
        InOrderTravelBiTree(root->rchild);
    }
}


int main()
{
    BiThrTree P, T;
    printf("请按前序遍历序列输入元素构造二叉树:");
    CreateThrBiTree(&T);         // 构造二叉树
    printf("递归中序遍历结果:");
    InOrderTravelBiTree(T);      // 中序遍历二叉树

    InOrderTravelThreading(&P, T);   // 中序遍历将二叉树线索化
    printf("\n");
    printf("线索二叉树中序遍历结果:");
    InOrderTravel(P);            // 非递归中序遍历线索二叉树
}