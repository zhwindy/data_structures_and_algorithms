#include "stdio.h"
#include "stdlib.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    returnSize = (int*)malloc(2 * sizeof(int));
    for(i=0; i<numsSize; i++)
    {
        for(j=i; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                // *returnSize = i;
                // returnSize++;
                // *returnSize = j;
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }
    }
    return returnSize;
}

void twoSum1(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    for(i=0; i<numsSize; i++)
    {
        for(j=i; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                // returnSize[0] = i;
                // returnSize[1] = j;
                *returnSize = i;
                returnSize++;
                *returnSize = j;
                return;
            }
        }
    }
}

int main()
{
    int nums[7] = {1, 2, 33, 4, 7, 8, 61};
    int target = 9;
    int size[2] = {-1, -1};
    // twoSum1(nums, 6, target, size);
    int* rt;
    rt = twoSum(nums, 6, target, rt);
    for(int i=0; i<2; i++)
    {
        printf("%d ", rt[i]);
    }
    printf("\n");
}
