#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef enum
{
    link,
    thread
} PointTag;

// 线索二叉树的节点定义
typedef struct Btnode
{
    ElemType data;
    struct Btnode *lchild, *rchild;
    PointTag ltag;
    PointTag rtag;
} BTnode, *BiTree;

// 前序遍历输入->创建二叉树
void CreateBTree(BiTree* root)
{
    char c;
    scanf("%c", &c);
    if (c == '#')
    {
        *root = NULL;
    }
    else{
        *root = (BTnode*)malloc(sizeof(BTnode));
        (*root)->data = c;
        (*root)->ltag = link;
        (*root)->rtag = link;

        CreateBTree(&(*root)->lchild);
        CreateBTree(&(*root)->rchild);
    }
}

// 中序遍历->将二叉树线索化
void ThreadingBTree(){};