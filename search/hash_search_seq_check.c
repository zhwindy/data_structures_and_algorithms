#include "stdio.h"
#include "stdlib.h"

#define NONE -1
#define MAXSIZE 12
#define OK 1
#define FALSE 0

// 哈希表结构
typedef struct hashTable
{
    int table[MAXSIZE];
}HashTable;

// 初始化散列表
void InitHashTable(HashTable* T)
{
    int i;
    for(i=0; i<MAXSIZE; i++)
    {
        (*T).table[i] = NONE;
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
    addr = GenHashKey(key);
    while ((*T).table[addr] != NONE)   // 若待插入位置已放入元素,则按开放定址法的线性探测寻找下一个可插入的位置
    {
        addr = (addr + 1) % MAXSIZE;
    }
    (*T).table[addr] = key;
}

// 遍历散列表
void PrintHashTable(HashTable T)
{
    int i;
    for(i=0; i<MAXSIZE; i++)
    {
        printf("[%2d] %d\n", i, T.table[i]);
    }
}

// 散列表 = 除留余数法 + 开放定址法的线性探测
int main()
{
    int i;
    int a[MAXSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    HashTable T;
    InitHashTable(&T);
    for(i=0; i<MAXSIZE; i++)
    {
        InsertHashTable(&T, a[i]);
    }
    PrintHashTable(T);
}