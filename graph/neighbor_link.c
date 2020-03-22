#include "stdio.h"
#include "stdlib.h"

#define SIZE 10

// 链表节点结构
typedef struct linknode
{
    int index;
    struct linknode* next;
}LinkNode;

// 顶点结构
typedef struct vex{
    char data;
    LinkNode* first;
} Vex;

// 图的存储->邻接链表
typedef struct graph{
    Vex vex[SIZE];
    int vexSize;   // 图的顶点个数
    int EdgeSize;   // 图的边个数
} Graph;

void CreateGraph(Graph* G)
{
    int j, k, a, b;
    char c;
    LinkNode* p, *q;

    printf("请输入顶点和边的个数:");
    scanf("%d %d", &G->vexSize, &G->EdgeSize);

    for(j=0; j<G->vexSize; j++)
    {
        getchar();  // 非常关键,清除键盘缓冲区中的<回车>字符,避免直接进入下一次循环,会出现跳过的现象: 请输入顶点的值:请输入顶点的值:A
        printf("请输入顶点的值:");
        scanf("%c", &c);
        G->vex[j].data = c;
        G->vex[j].first = NULL;
    }

    for(k=0; k<G->EdgeSize; k++)
    {
        // getchar()  这里输入的是数字,所以不需要用getchar清理缓冲区
        printf("请输入顶点的序号:");
        scanf("%d %d", &a, &b);

        // printf("当前的a=%d, b=%d\n", a, b);
        p = (LinkNode*)malloc(sizeof(LinkNode));
        p->index = b;
        p->next = G->vex[a].first;
        G->vex[a].first = p;


        q = (LinkNode*)malloc(sizeof(LinkNode));
        q->index = a;
        q->next = G->vex[b].first;
        G->vex[b].first = q;
    }
}

void Visit(Graph G)
{
    int i;
    LinkNode* p;
    printf("打印图中的%d个顶点的值:\n", G.vexSize);
    for(i=0;i<G.vexSize; i++)
    {
        printf("%c", G.vex[i].data);
        p = G.vex[i].first;
        while (p)
        {
            printf("->%d", p->index);
            p = p->next;
        }
        printf("\n");
        
    }
}

int main()
{
    Graph G;
    CreateGraph(&G);
    Visit(G);
    return 1;
}