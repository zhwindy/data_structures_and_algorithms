#include "stdio.h"
#include "stdlib.h"
#define QUEUE_SIZE 10

typedef char ElemType;

/*
队列的顺序存储结构,用一段连续的存储单元保存队列中的元素,并附设两个指针front和rear分别指向队头元素和队尾元素的位置;
0. 指针设置: front指向队头元素的位置, rear指向队尾元素的下一个位置
1. 队列判空条件: front == rear == 0
2. 入队: 队列未满时,将元素放入rear指向的位置, 然后rear+1
3. 出队: 队列不空时,将front指向位置的元素出队,然后front+1
4. 队列判满条件: 无法判满,会存在假溢出的问题
*/

// 队列的顺序存储结构
typedef struct queue
{
    int front, rear;
    ElemType data[QUEUE_SIZE];   // 用数组存放队列中的元素
} SeqQueue;

// 入队操作
void InsertQueue(SeqQueue* Q, char c)
{
    if( (Q->rear + 1) % QUEUE_SIZE == Q->front)
    {
        printf("队列已满");
        exit(0);
    }
    else
    {
        Q->data[Q->rear] = c;
        Q->rear  = (Q->rear + 1) % QUEUE_SIZE;
    }
}

// 初始化顺序队列
void CreateSeqQueue(SeqQueue* Q)
{
    char c;
    Q->front = Q->rear = 0;

    printf("请输入要入队的元素, 以#结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        InsertQueue(Q, c);
        scanf("%c", &c);
    }
    
}

// 出队操作
void DeleteQueue(SeqQueue* Q, char c)
{
    if(Q->front == Q->rear)
    {
        printf("队列已空");
        exit(0);
    }
    else
    {
        c = Q->data[Q->front];
        Q->front  = (Q->front + 1) % QUEUE_SIZE;
    }
}

int main()
{
    SeqQueue Q;
    CreateSeqQueue(&Q);
    ReadSeqQueue(&Q);
}