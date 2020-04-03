#include "stdio.h"
#include "stdlib.h"

#define NONE -1
#define MAXSIZE 15
#define OK 1
#define FALSE 0

// 链表节点结构
typedef struct node
{
    int data;
    struct node* next;
}Node;

// 哈希表节点结构
typedef struct hashNode
{
    int data;
    Node* first;
}HashNode;

// 哈希表结构
typedef struct hashTable
{
    HashNode table[MAXSIZE];
}HashTable;

// 初始化一个散列表
void InitHashTable(HashTable* T)
{
    int i;
    for(i=0; i<MAXSIZE; i++)
    {
        (*T).table[i].data = NONE;
        (*T).table[i].first = NULL;
    }
}

// 散列函数->除留余数
int GenHashKey(int key)
{
    return key % MAXSIZE;
}

// 插入散列表
void InsertHashTable(HashTable* T, int key)
{
    int addr;
    Node *p, *s;
    addr = GenHashKey(key);
    if((*T).table[addr].data == -1)
    {
        (*T).table[addr].data = key;
    }
    else
    {
        // p = (*T).table[addr].first;   这里不能使用局部变量来操作,因为最终的结果不会应用到哈希表上

        s = (Node*)malloc(sizeof(Node));
        s->data = key;
        s->next = (*T).table[addr].first;

        (*T).table[addr].first = s;
    }
}

// 遍历散列表=本身 + 冲突链表
void PrintHashTable(HashTable T)
{
    Node* p;
    int i;
    for(i=0; i<MAXSIZE; i++)
    {
        printf("[%d] %d ", i, T.table[i].data);
        p = T.table[i].first;
        while (p)
        {
            printf("-> %d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

// 散列表 = 除留余数法 + 链地址冲突解决
int main()
{
    int i;
    int a[MAXSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34, 66, 88, 99};
    HashTable T;
    InitHashTable(&T);
    for(i=0; i<MAXSIZE; i++)
    {
        InsertHashTable(&T, a[i]);
    }
    PrintHashTable(T);
}