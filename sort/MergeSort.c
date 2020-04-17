#include "stdio.h"
#define SIZE 12

// 归并排序
void MergeArray(int* a, int a_size, int* b, int b_size)
{
    int i, j, k, m;
    int tmp[a_size+b_size];
    i = j = k = 0;
    while (i < a_size && j < b_size)
    {
        if(a[i] < b[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = b[j++];
        }
    }
    // a数组还有剩余
    while (i < a_size)
    {
        tmp[k++] = a[i++];
    }
    // b数组还有剩余
    while (j < b_size)
    {
        tmp[k++] = b[j++];
    }
    for (m = 0; m < (a_size + b_size); m++)
    {
        a[m] = tmp[m];
    }
}

// 归并排序
void MergeSort(int* a, int n)
{
    if (n > 1)
    {
        int* left = a;
        int left_size = n/2;
        int* right = left + left_size;
        int right_size = n - left_size;
        MergeSort(left, left_size);
        MergeSort(right, right_size);
        // 合并有序表--->治
        MergeArray(left, left_size, right, right_size);
    }
}


int main()
{
    int i;
    int array[SIZE] = {2, 36, 1, 8, 0, 9, 7, 4, 6, 3, 5, 82};
    MergeSort(array, SIZE);
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}