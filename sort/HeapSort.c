#include "stdio.h"

#define SIZE 12

// 堆的平衡调整
void HeapAdjust(int* a, int p, int n)
{
    int left, right;
    int temp, tmp;
    while (2*p < n)
    {
        left = 2*p + 1;
        right = 2*p + 2;
        // 找到左右子树中比较大的那个
        if(right< n && a[left] < a[right])
        {
            tmp = right;
        }
        else
        {
            tmp = left;
        }
        // 若双亲节点值小,则交换
        if(a[p] < a[tmp])
        {
            temp = a[p];
            a[p] = a[tmp];
            a[tmp] = temp;
        }
        p++;
    }
}

// 堆排序
// 2020年4月17日 17:55
void HeapSort(int* a, int n)
{
    int i, temp;
    for(i=0; i<n; i++)
    {
        temp = a[0];
        a[0] = a[n-1-i];
        a[n-i-1] = temp;
        HeapAdjust(a, 0, n-1-i);
    }
}

int main()
{
    int i, n=SIZE;
    int array[SIZE] = {2, 36, 1, 8, 0, 9, 7, 4, 6, 3, 5, 82};
    // 初始化一个堆
    for(i=(n/2-1); i>=0; i--)
    {
        HeapAdjust(array, i, n);
    }
    HeapSort(array, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}