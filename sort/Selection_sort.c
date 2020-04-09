#include "stdio.h"

void SelectSort(int *a, int n)
{
    int i, j, min, tmp;
    for(i=0; i<n; i++)
    {
        min = i;
        for(j=i; j<n; j++)
        {
            // if(a[j] < a[j+1])  这里不能两两比较,有问题
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        // printf("i=%d, min=%d\n", i, min);
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main()
{
    int a[11] = {2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int n = 11, i;
    SelectSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}