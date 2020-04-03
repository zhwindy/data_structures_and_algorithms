#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define False 0

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *lchild, *rchild;
}BTnode, *BiTree;

// 构造二叉排序树
void CreateBinarySortedTree(BiTree* root)
{
    BiTree p;
    char c;
    scanf("%c", &c);
    if(c == '#')
    {
        *root = NULL;
    }
    else
    {
        *root = (BTnode*)malloc(sizeof(BTnode));
        (*root)->data = c;
        CreateBinarySortedTree(&(*root)->lchild);
        CreateBinarySortedTree(&(*root)->rchild);
    }
}

// 二叉排序树的查找
// pre指针: 若找到则指向该结点, 若没有找到,则指向访问的最后一个结点
// f指针: 指向root的双亲结点,初始化为NULL
int Search(BiTree root, BiTree f, int key, BiTree* pre)
{
    if (!root)
    {
        *pre = f;
        return False;
    }
    if(key == root->data)
    {
        *pre = root;
        return OK;
    }
    else if(key < root->data)
    {
        return Search(root->lchild, root, key, pre);
    }
    else
    {
        return Search(root->rchild, root, key, pre);
    }
}

// 二叉排序树的插入
int Insert(BiTree root, int key)
{
    BiTree s, p, f;

    s = (BiTree)malloc(sizeof(BTnode));
    s->data = key;
    s->lchild = s->rchild = NULL;

    if(!Search(root, f, key, &p))
    {
        if(!p)
        {
            p = s;
        }
        else
        {
            if(key < p->data)
            {
                p->lchild = s;
            }
            else
            {
                p->rchild = s;
            }
            
        }
        return OK;
    }
    else
    {
        printf("关键字已经存在,请重新输入");
        return False;
    }
}

// 删除节点
int Delete(BiTree* root)
{
    BiTree p, q, s;
    p = *root;
    if(!p)
    {
        return False;
    }
    else
    {
        if((p)->rchild == NULL)
        {
            q = p;
            p = p->lchild;
            free(q);
        }
        else if(p->lchild == NULL)
        {
            q = p;
            p = p->rchild;
            free(q);
        }
        else
        {
            q = p;
            s = p->lchild;
            while (s->rchild)
            {
                q = s;
                s = s->rchild;
            }
            if(q ==p)
            {
                p->data = s->data;
                p->lchild = s->lchild;
            }
            else
            {
                p->data = s->data;
                q->rchild = s->lchild;
            }
            free(s);
        }
    }
}

// 二叉排序树-删除元素
int DeleteBST(BiTree* T, int key)
{
    if(!*T)
    {
        return False;
    }
    else
    {
        if(key == (*T)->data)
        {
            return Delete(T);
        }
        else if(key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, key);
        }
        else
        {
            return DeleteBST(&(*T)->lchild, key);
        }
    }
}

int main()
{
    BiTree root;
    printf("请输入前序遍历序列:");
    CreateBinarySortedTree(&root);
}