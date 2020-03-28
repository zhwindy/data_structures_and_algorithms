#include "stdio.h"

#define SIZE 10

// 查找算法-顺序查找

int search(int* a, int n, int key)
{
    int i;
    for(i=0; i<n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int a[SIZE] = {1, 11, 5, 22, 7, 9, 13, 998};
    int pos, key;
    printf("请输入需要查找的值:");
    scanf("%d", &key);
    pos = search(a, SIZE, key);
    printf("查找结果: %d\n", pos);
}