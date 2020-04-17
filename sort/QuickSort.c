#include "stdio.h"
#define SIZE 12

// 快速排序
void QuickSort(int* a, int left, int right)
{
    int i, j, temp, tmp;
    i = left;
    j = right;
    temp = a[i];
    if(i > j)
    {
        return;
    }
    while (i != j)
    {
        while (a[j] > temp && i < j)
        {
            j--;
        }
        while (a[i] <= temp && i < j)
        {
            i++;
        }
        // 交换元素
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    // 当i=j时本轮循环结束, 将哨兵放到合适的位置
    a[left] = a[i];
    a[i] = temp;
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
}

int main()
{
    int i;
    int array[SIZE] = {2, 36, 1, 8, 0, 9, 7, 4, 6, 3, 5, 82};
    QuickSort(array, 0, SIZE - 1);
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}