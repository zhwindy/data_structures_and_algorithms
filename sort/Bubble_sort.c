#include "stdio.h"

// 冒泡排序
void BubbleSort(int *a, int n)
{
    int i, j, tmp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

// 冒泡排序02
void BubbleSort_02(int *a, int n)
{
    int i, j, tmp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int a[10] = {2, 9, 7, 3, 4, 6, 8, 0, 1, 5};
    int n = 10, i;
    BubbleSort_02(a, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}