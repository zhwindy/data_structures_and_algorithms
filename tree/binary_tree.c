#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

//二叉树的存储结构-二叉链表

typedef struct BTnode
{
    struct BTnode *lchild, *rchild;
    ElemType data;
}BTnode, *BiTree;

/*
 二叉树的遍历方法,按从左到右的顺序,有以下四种:
 1.前序遍历
 2.中序遍历
 3.后序遍历
 4.层序遍历
*/

// 有参数创建二叉树: 根据前序遍历输入节点
void CreateBTree(BiTree* T)   // BiTree*  == BTnode** 代表指向节点的指针的指针
{
    char c;
    scanf("%c", &c);

    if (c == ' '){
        *T = NULL;
    }
    else
    {
        *T = (BTnode*)malloc(sizeof(BTnode));
        (*T)->data = c;
        CreateBTree(&(*T)->lchild);
        CreateBTree(&(*T)->rchild);
    }
}

// 有参数创建二叉树: 根据前序遍历输入节点
void CreateBTree_2(BTnode* T)
{
    char c;
    scanf("%c", &c);

    if (c == '#'){
        T = NULL;
    }
    else
    {
        T = (BTnode*)malloc(sizeof(BTnode));
        T->data = c;
        CreateBTree_2(T->lchild);
        CreateBTree_2(T->rchild);
    }
}

// 无参数创建二叉树,返回数根节点的指针
BTnode* InitBTree()
{
    BTnode* s;
    char c;
    scanf("%c", &c);
    if (c == '#'){
        return NULL;
    }
    else
    {
        s = (BTnode*)malloc(sizeof(BTnode));
        s->data = c;
        s->lchild = InitBTree();
        s->rchild = InitBTree();
    }
    return s;
} 

// 访问二叉树的节点
void visit(BTnode* t, int level)
{
    printf("元素%c 在第%d层\n", t->data, level);
}

// 前序遍历二叉树
void PreOrderTrval(BTnode* T, int level)
{
    if (T)
    {
        visit(T, level);
        PreOrderTrval(T->lchild, level + 1);
        PreOrderTrval(T->rchild, level + 1);
    }
}

int main()
{
    BTnode* t;
    int level = 1;
    // CreateBTree(&t);
    // t = InitBTree();
    CreateBTree_2(t);
    PreOrderTrval(t, level);
}