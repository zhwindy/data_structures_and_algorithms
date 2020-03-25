#include <stdio.h>
#include <stdlib.h>

// 参考资料:https://www.jianshu.com/p/deb1d2f2549a

typedef char ElemType;
typedef enum
{
    link,
    thread
} PointTag;

// 线索二叉树的节点定义
// link(0) 表示指向左右孩子的指针
// thread(1) 表示指向前驱后继节点的线索
typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild, *rchild;
    PointTag ltag;
    PointTag rtag;
} BiThrNode, *BiThrTree;

BiThrTree pre;

// 前序遍历输入顶点 -> 创建一棵二叉树
void CreateBiTree(BiThrTree* root)
{
    char c;
    scanf("%c", &c);
    if (c == '#')
    {
        *root = NULL;
    }
    else{
        *root = (BiThrTree)malloc(sizeof(BiThrNode));
        (*root)->data = c;
        (*root)->ltag = link;
        (*root)->rtag = link;

        CreateBiTree(&(*root)->lchild);
        CreateBiTree(&(*root)->rchild);
    }
}

// 对普通二叉树以某种遍历次序使其成为线索二叉树的过程称为二叉树的线索化, 线索化的过程就是在遍历的过程中修改空指针
void ThreadingBiTree(BiThrTree root)
{
    if (root){
        ThreadingBiTree(root->lchild);
        // 节点处理
        if (!root->lchild)   //如果当前节点没有左孩子,则左指针为线索,并指向其前驱结点
        {
            root->ltag = thread;
            root->lchild = pre;
        }

        if (!pre->rchild)   //如果pre节点没有右孩子,则右指针为线索,指向其后继节点
        {
            pre->rtag = thread;
            pre->rchild = root;
        }
        
        pre = root;     // pre 全局变量永远指向当前访问节点的上一个节点
        ThreadingBiTree(root->rchild);
    }
};

void InOrderThreadingBiTree(BiThrTree root)
{
    if (!root)
    {
        printf("一棵空树!");
    }
    else
    {
        BiThrTree tmp;
        tmp = (BiThrTree)malloc(sizeof(BiThrNode));
        pre = tmp;
        // 初始化pre指针, 作为树的头结点
        pre->ltag = link;
        pre->lchild = root;

        pre->rtag = thread;
        pre->rchild = pre;

        ThreadingBiTree(root);

        pre->rtag = thread;
        pre->rchild = tmp;
        tmp->rchild = pre;
        
        pre = tmp;
    }
}


// 中序遍历线索二叉树-非递归方式
void InOrderTravelBiTree(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p!=T)
    {
        while (p->ltag == link)
        {
            p = p->lchild;
        }
        printf("%c ", p->data);
        while (p->rtag == thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild;   // 收尾,遍历到最后一个节点,将其右孩子指向头结点,即 p = T
    }
    printf("\n");
}

int main()
{
    BiThrTree root;
    printf("请输入前序遍历序列构造二叉树:");   // ABC##D##E#F##
    CreateBiTree(&root);
    // printf("二叉树构造完成!\n");
    InOrderThreadingBiTree(root);
    printf("线索二叉树前序遍历结果为:");
    InOrderTravelBiTree(pre);
    return 1;
}