#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

// 链式队列的节点结构
typedef struct Qnode
{
    ElemType data;
    struct Qnode* next;
} Qnode;

// 链队列
typedef struct queue
{
    Qnode *front, *rear;
} Queue;


// 初始化一个队列
void CreateQueue(Queue* Q)
{
    char c;
    Qnode* p;

    p = (Qnode*)malloc(sizeof(Qnode));   // 为链队列增加1个头结点
    p->data = '>';
    Q->front = p;
    Q->rear = p;

    printf("请输入要入队的元素, 以#结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        p = (Qnode*)malloc(sizeof(Qnode));
        p->data = c;
        p->next = NULL;

        Q->rear->next = p;
        Q->rear = p;

        scanf("%c", &c);
    }
    
}

// 遍历队列
void ReadQueue(Queue* Q)
{
    Qnode* p;
    p = Q->front;
    while(p)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Queue Q;
    CreateQueue(&Q);
    ReadQueue(&Q);
}