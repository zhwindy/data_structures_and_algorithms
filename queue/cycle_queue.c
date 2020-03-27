#include "stdio.h"
#include "stdlib.h"
#define QUEUE_SIZE 10

typedef char ElemType;

/*
为解决顺序队列的假溢出问题,考虑循环队列,将队列在逻辑上设置为循环的队列,front和rear指针仍然指向队头和队尾元素的位置
0. 指针设置: front指向队头元素, rear指向队尾元素的下一个位置
1. 初始队列为空时: front == rear == 0
2. 入队: 将元素放入rear指针指向的位置, 然后设置rear = (rear + 1) % MAXSIZE
3. 出队: 将front指针指向的元素拿出, 然后设置front = (front + 1) % MAXSIZE
4. 判满: front == rear
5. 队列中元素个数: (rear - front + MAXSIZE) % MAXSIZE

上述一个明显的问题是: 判空条件和判满条件一样, 当front== rear时, 无法判断当前是空队列还是满队列

解决这个问题常用以下2个方法:
1. 牺牲1个单元的存储空间,约定当队头指针在队尾指针的下一个位置时, 即为队列已满
    a.空队列: front = rear
    b.满队列: (rear + 1) % MAXSIZE == front
    c.队列中元素个数: (rear - front + MAXSIZE) % MAXSIZE
2. 新增标记 Qsize 为记录队列中元素的个数
    a.空队列: Qsize = 0
    b.满队列: Qsize = MAXSIZE
*/

// 队列的顺序存储结构
typedef struct queue
{
    int front, rear;
    ElemType* base;
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
        (Q->base)[Q->rear] = c;
        Q->rear  = (Q->rear + 1) % QUEUE_SIZE;
    }
}

// 初始化顺序队列-循环队列
void CreateSeqQueue(SeqQueue* Q)
{
    char c;
    Q->base = (ElemType*)malloc(QUEUE_SIZE * sizeof(ElemType));
    Q->front = 0;
    Q->rear = 0;

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
        c = (Q->base)[Q->front];
        Q->front  = (Q->front + 1) % QUEUE_SIZE;
    }
}

void ReadSeqQueue(SeqQueue* Q)
{
    int i, Qsize;
    Qsize = (Q->rear - Q->front + QUEUE_SIZE) % QUEUE_SIZE;
    for(i=0;i<Qsize; i++)
    {
        printf("%c", Q->base[i]);
    }
    printf("\n");
}

int main()
{
    SeqQueue Q;
    CreateSeqQueue(&Q);
    ReadSeqQueue(&Q);
}