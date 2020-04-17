#include "stdio.h"

// 将2个有序数组合并为1个大的有序数组
// 需要解决问题: 函数内部使用了临时数组tmp, 归并结束后需要将tmp中的数据copy到原数组中
void MergeArray(int* first, int first_size, int* second, int second_size)
{
    int tmp[50];
    int i, j, k, m;
    i = j = k = 0;
    while (i<first_size && j<second_size)
    {
        if(first[i] < second[j])
        {
            tmp[k++] = first[i++];
        }
        else
        {
            tmp[k++] = second[j++];
        }
    }
    // j已经空i尚未结束
    while (i < first_size)
    {
        tmp[k++] = first[i++];
    }
    // i已经空j尚未结束
    while (j < second_size)
    {
        tmp[k++] = second[j++];
    }
    // 将tmp中的数据copy到原数组中
    for(m=0; m<(first_size + second_size); m++)
    {
        first[m] = tmp[m];
    }
}

// 归并排序
void MergeSort(int* a, int n)
{
    if (n > 1)
    {
        int* first = a;
        int first_size = n/2;
        int* second = a + n/2;
        int second_size = n - first_size;
        MergeSort(first, first_size);
        MergeSort(second, second_size);
        MergeArray(first, first_size, second, second_size);
    }
}

int main()
{
    int a[11] = {2, 9, 7, 3, 88, 4, 6, 8, 0, 1, 5};
    int i, n = 11;
    MergeSort(a, n);
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}