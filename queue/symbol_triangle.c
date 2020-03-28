#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 50

/*题目: 打印符号三角形 */

typedef struct queue
{
    char* base;
    int front, rear;
}Queue;

// 元素入队操作
void InsertQueue(Queue* Q, char c)
{
    if( (Q->rear+1) % MAXSIZE == Q->front)
    {
        printf("队列已满, 无法入队");
    }
    else
    {
        Q->base[Q->rear] = c;
        Q->rear = (Q->rear+1) % MAXSIZE;
    }
}

int QueueLen(Queue* Q)
{
    if (Q->front == Q->rear)
    {
        return 0;
    }
    else
    {
        return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
    }
}

// 初始化队列并输入元素
void CreateQueue(Queue* Q)
{
    char c;
    Q->base = (char*)malloc(MAXSIZE * sizeof(char));
    Q->front = Q->rear = 0;
    printf("请输入符号串并以#符号表示结束输入:");
    scanf("%c", &c);
    while (c != '#')
    {
        InsertQueue(Q, c);
        scanf("%c", &c);
    }
}

void PrintSymbol(Queue* Q)
{
    char a, b;
    int i, j, len;
    Queue* p;
    len = QueueLen(Q);
    printf("当前队列的长度为:%d\n", len);
    while(Q->front != Q->rear)
    {
        for(i=0;i<len; i++){
            for(j=0;j<len-i; j++)
            {
                a = Q->base[Q->front];
                printf("%c ", a);
                Q->front = (Q->front+1) % MAXSIZE;
                b = Q->base[Q->front];
                if( a == b)
                {
                    InsertQueue(Q, '+');
                }
                else
                {
                    InsertQueue(Q, '-');
                }
            }
            printf("\n");
        }
        break;
    }
    printf("\n");
}

int main()
{
    Queue Q;
    CreateQueue(&Q);
    PrintSymbol(&Q);
}