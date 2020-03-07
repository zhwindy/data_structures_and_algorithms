#include "stdlib.h"
#include "stdio.h"

#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

typedef struct node{
    ElemType data;
    struct node* next;
} LinkNode;

typedef LinkNode* LinkList;

// 向顺序存储的线性表中插入1个元素
// 1.确定插入的位置i
// 2.若i小于0或者大于数组的最大长度, 则返回错误
// 3.若插入位置在最后,则直接插入。否则将i到最后的位置后移1位

// 顺序表插入 特别注意: 线性表从1开始,但数组下标从0开始
Status insertSeqList(SeqList* L, int i, ElemType e){
    int j;
    if (i > L->length){
        return ERROR;
    }
    if (i < 1 || i > MAXSIZE){
        return ERROR;
    }
    if (i <= L->length){
        for(j=L->length-1; j>i; j--){
            L->data[j + 1] = L->data[j];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

// 单链表插入
Status insertLinkList(LinkList L, int i, ElemType e){
    LinkList p, s;
    p = L;
    int j=1;
    while (p && j<i){
        p = p->next;
        j++;
    }
    if (!p){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LinkNode));
    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;
}

int main(){
    printf("Hello World");
    printf("\n");
}