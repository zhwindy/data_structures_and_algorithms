#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef int Status;

// 顺序表结构
typedef struct{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

//单链表节点结构
typedef struct node{
    ElemType data;
    struct node* next;
} LinkNode;

typedef LinkNode* LinkList;

// 顺序表的查找
Status getElemSeqList(SeqList *L, int i, ElemType* e){
    if (i<1 || i > L->length){
        return ERROR;
    }
    // 为指针指向的内存赋值
    *e = L->data[i-1];
    return OK;
}

// 单链表的查找: 因为链表的长度未知,所以不能使用for循环查找.只能使用while循环
Status getElemLinkList(LinkList L, int i, ElemType* e){
    LinkList p=L->next;
    int j=1;
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if (!p){
        return ERROR;
    }
    // 为指针指向的内存赋值
    *e = p->data;
    return OK;
}

// 尾插法建立单链表
void CreateLinkListTail(LinkNode* L, int n)
{
    LinkList s;
    int i;
    L->next = NULL;
    for(i=1; i<n; i++)
    {
        s = (LinkList)malloc(sizeof(LinkNode));
        s->data = (rand() % 100 + 1);
        s->next = L->next;
        L->next = s;
        L = s;
    }
}

// 测试题:在未知长度的单链表中,找到中间位置的元素
ElemType getMidElemLinkList(LinkList L, ElemType* e){
    if (!L || !(L->next)){
        return ERROR;
    }
    LinkList p, q;
    int i;
    p = q = L;
    while (p)
    {
        p = p->next->next;
        q = q->next;
    }
    // e = &q->data;
    *e = q->data;
    return OK;
}

Status main(){
    LinkList L=(LinkList)malloc(sizeof(LinkNode));
    int value, n = 50;
    CreateLinkListTail(L, n);
    getMidElemLinkList(L, &value);
    printf("链表中间位置的元素为:%d\n", value);
    while (L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
    return OK;
}