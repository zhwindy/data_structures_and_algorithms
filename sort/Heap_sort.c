#include "stdio.h"
#include "math.h"

// 元素交换
void swap(int *a, int i, int j)
{
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// 堆的调整
void HeapAdjust(int* a, int p, int n)
{
    int i, temp;
    temp = a[p];
    for(i=2*p; i<=n; i=i*2)
    {
        if(i<n && a[i] < a[i+1])
        {
            i++;
        }
        if(temp >= a[i])
        {
            break;
        }
        a[p] = a[i];
        p = i;
    }
    a[p] = temp;
}

// 堆排序-利用堆这种数据结构进行的排序
void HeapSort(int *a, int n)
{
    int i;
    // 初始化堆
    for(i=n/2; i>0; i--)
    {
        HeapAdjust(a, i, n);
    }
    printf("初始化完成后:");
    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    // 堆排序
    for(i=n; i>1; i--)
    {
        swap(a, 1, i);
        HeapAdjust(a, 1, i-1);
    }
}

int main()
{
    int i, a[12] = {-1, 2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int n = 11;
    HeapSort(a, n);
    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}