#include "stdio.h"

// 快速排序
int QuickSort(int *a, int left, int right)
{
    int temp, flag;
    int i=left, j=right;
    flag = a[i];
    if(i > j)
    {
        return 1;
    }
    while (i != j)
    {
        // j指针先从后往前移动,直到找到比基准值小的元素
        while (a[j] >= flag && i < j)    // 这里条件必须有i<j,否则无限循环 segmentation fault
        {
            j--;
        }
        // i指针先从前往后移动,直到找到比基准值大的元素
        while (a[i] <= flag && i < j)
        {
            i++;
        }
        // i和j指向的元素交换
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[left] = a[i];
    a[i] = flag;
    QuickSort(a, left, i-1);
    QuickSort(a, i+1, right);
    return 1;
}

int main()
{
    int a[11] = {2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int i, n = 11;
    QuickSort(a, 0, 10);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}