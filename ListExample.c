#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct lnode{
    ElemType data;
    struct lnode* next;
} LinkNode;

typedef LinkNode* LinkList;

typedef struct node{
    ElemType data;
    struct node* prior;
    struct node* next;
} DualNode;

typedef DualNode* DuLinkList;

// 初始化双向循环链表
Status CreateDuList(DuLinkList S){
    DuLinkList p, q;
    int i;

    if (!S){
        return ERROR;
    }
    S->next = S->prior = NULL;
    p = S;
    for(i=0; i<26; i++){
        q = (DuLinkList)malloc(sizeof(DualNode));
        if (!q){
            return ERROR;
        }
        q->data = 'A' + i;
        q->prior = p;
        q->next = p->next;
        p->next = q;

        p = q;
    }
    p->next = S->next;
    S->next->prior = p;

    return OK;
}

// 初始化单循环链表
Status CreateLinkList(LinkList S, int n){
    LinkList p, q;
    int i;
    p = S;
    for (i=1; i<=n; i++){
        q = (LinkList)malloc(sizeof(LinkNode));
        q->data = i;
        q->next = p->next;
        p->next = q;

        p = q;
    }
    p->next = S->next;

    return OK;
}

DuLinkList Caseser(DuLinkList L, int i){
    // 移动游标到第i个位置
    if (i>0){
        do{
            L = L->next;
        }while (--i);
    }
    if (i<0){
        L = L->next;
        do{
            L = L->prior;
        }while (++i);
    }
    return L;
}

// 双向循环链表实践-字母排序问题
Status test_dulist_main(){
    DuLinkList L = (DuLinkList)malloc(sizeof(DualNode));
    DuLinkList Q;
    int i, n;

    CreateDuList(L);

    printf("请输入一个整数:");
    scanf("%d", &n);

    Q = Caseser(L, n);

    for(i=0; i<26; i++){
        Q = Q->next;
        printf("%c", Q->data);
    }
    printf("\n");

    return OK;
}

// 单循环链表实践-约瑟夫问题
Status Josephus(LinkList S, int n, int m){
    LinkList p;
    int i=1, j;
    p = S->next;
    n %= m;
    while (p != p->next)
    {
        while(p && i< m-1){
            p = p->next;
            i++;
        }
        printf("->%d", p->next->data);
        p->next = p->next->next;
        p = p->next->next;
    }
    /*
    while (p != p->next)
    {
        for(j=0; j< n-1; j++){
            p = p->next;
        }
        printf("->%d", p->next->data);
        p->next = p->next->next;
        p = p->next;
    }
    */
    printf("->%d\n", p->data);
    return OK;
}

Status main(){
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    int i, n, m;
    printf("请输入元素的数个数:");
    scanf("%d", &n);
    printf("请输入间隔数:");
    scanf("%d", &m);
    CreateLinkList(L, n);
    for(i=0; i<n; i++){
        L = L->next;
        printf("%d ", L->data);
    }
    printf("\n");
    Josephus(L, n, m);
}