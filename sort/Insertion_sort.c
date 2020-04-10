#include "stdio.h"

// 插入排序
void InsertSort(int *a, int n)
{
    int i, pre, current;
    for(i=1; i<n; i++)
    {
        pre = i - 1;
        current = a[i];
        while (pre >= 0 && a[pre]>=current)
        {
            a[pre + 1] = a[pre];
            pre--;
        }
        a[pre + 1] = current;
    }
}

int main()
{
    int a[11] = {2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int n = 11, i;
    InsertSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}