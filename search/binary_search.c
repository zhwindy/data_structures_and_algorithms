#include "stdio.h"

#define MAXSIZE 20

// 查找算法-折半查找(二分查找)
int search(int* a, int n, int key)
{
    int low=0, mid, high=n-1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int key, pos;
    int a[MAXSIZE] = {1, 3, 5, 7, 9, 13, 15, 17, 19, 21, 111, 121, 122, 123, 234, 345, 456, 567, 678, 789};
    printf("请输入要查找的值:");
    scanf("%d", &key);
    pos = search(a, MAXSIZE, key);
    printf("查找结果:%d\n", pos);
}