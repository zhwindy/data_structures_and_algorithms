#include "stdio.h"
#include "math.h"

// 希尔排序-缩小增量排序
void ShellSort(int *a, int n)
{
    int gap, i, current;
    for(gap = (n/2); gap>0; gap=(gap/2))
    {
        for(i=gap; i<n; i=i+gap)
        {
            current = a[i];
            while ((i-gap >=0) && a[i] < a[i-gap])
            {
                a[i] = a[i-gap];
                a[i-gap] = current;
                i = i - gap;
            }
        }
    }
}

int main()
{
    int a[11] = {2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int n = 11, i;
    ShellSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}