#include "stdio.h"

#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

// 顺序表定义
typedef struct{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

// 单链表节点定义
typedef struct node{
    ElemType data;
    struct node* next;
} LinkNode;

typedef LinkNode* LinkList;

// 从顺序存储的线性表中删除1个元素
// 1.确定插入的位置,若位置非法,返回异常
// 2.若i小于0或者大于数组的最大长度, 则返回错误
// 3.从删除位置开始,依次向前移1位

// 特别注意: 线性表从1开始,但数组下标从0开始
Status deleteList(SeqList *L, int i){
    int j;
    if (i > L->length){
        return ERROR;
    }
    if (i < 1 || i > MAXSIZE){
        return ERROR;
    }
    if (i < L->length){
        for(j=i; j<=L->length; j++){
            L->data[j-1] = L->data[j];
        }
    }
    L->length--;
    return OK;
}

// 单链表中删除指定位置的元素
Status deleteLinklist(LinkList L, int i, ElemType* e){
    LinkList p;
    p = L;
    int j=1;
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if (!p){
        return ERROR;
    }
    *e = p->data;
    p->next = p->next->next;
    return OK;
}

int main(){
    printf("Hello World");
    printf("\n");
}