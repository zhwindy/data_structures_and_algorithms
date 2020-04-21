#include "stdio.h"

#define DATA_SIZE 14

int iCompareCount = 0;

void swap(int data[], int i, int j)
{
        int iTemp = data[i];
        data[i] = data[j];
        data[j] = iTemp;
}

void heapAdjust(int data[], int s, int iDataSize)
{
        int iTemp = data[s];

        for ( int i = 2 * s; i <= iDataSize; i *= 2)
        {
                iCompareCount++;
                if ( i < iDataSize && data[i] < data[i + 1] )
                {
                        i++;
                }

                if ( iTemp >= data[i] )
                {
                        break;
                }

                data[s] = data[i];
                s = i;
        }

        data[s] = iTemp;
}

// 堆排序
void heapSort(int data[], int iDataSize)
{
        int i = 0;
        for ( i = iDataSize / 2; i > 0; i-- )
        {
                heapAdjust(data, i, iDataSize);
        }

        for ( i = iDataSize; i > 1; i-- )
        {
                swap(data, 1, i);
                heapAdjust(data, 1, i - 1);
        }
}

void printResult(int data[], int iDataSize)
{
        printf("排序后的结果是：");
        for ( int i = 0; i < iDataSize; i++)
        {
                printf("%d ", data[i]);
        }
        printf("\n");
}

int main()
{
        int data[DATA_SIZE] = {3,6,1,4,2,5,9,33,8,1,22,32,11,18};
        heapSort(data, DATA_SIZE - 1);
        printResult(data, DATA_SIZE);
}