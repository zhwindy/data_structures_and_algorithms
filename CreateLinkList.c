#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct node{
    ElemType data;
    struct node *next;
} LinkNode;

//01 为结构体指针定义别名
typedef LinkNode* LinkList;

//02 为结构体指针定义别名
typedef struct node* Link_List;

// 头插法建立单链表
Status createLinklistHead(LinkList L)
{
    Link_List s;
    int n;
    L->next = NULL;
    printf("请输入放入链表的数字:");
    scanf("%d", &n);
    while(n != 999)
    {
        s = (LinkList)malloc(sizeof(LinkNode));  //动态分配空间
        s->data = n;
        s->next = L->next;
        L->next = s;

        printf("请输入放入链表的数字:");
        scanf("%d", &n);
    }
    return OK;
}

// 尾插法建立单链表
void CreateLinkListTail(LinkNode* L)
{
    LinkNode* s;
    int n;
    L->next = NULL;
    printf("请输入放入链表的数字:");
    scanf("%d", &n);
    while(n != 888)
    {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = n;
        s->next = L->next;
        L->next = s;
        L = s;

        printf("请输入放入链表的数字:");
        scanf("%d", &n);
    }
}

Status printLinkList(LinkNode* L){
    if (!L){
        printf("链表为空");
        return ERROR;
    }
    while(L){
        printf("%d ", L->data);
        L = L->next;
    }
    return OK;
}

Status main(){
    LinkList L=(LinkNode*)malloc(sizeof(LinkNode));
    Link_List S=(LinkNode*)malloc(sizeof(LinkNode));

    // 头插法
    createLinklistHead(L);
    // 尾插法
    CreateLinkListTail(S);

    printLinkList(L->next);
    printf("\n");
    printLinkList(S->next);
    printf("\n");

    return OK;
}