#include "stdio.h"
#include "string.h"

void get_next(int* next, char* t){
    int i=1, j=0;   // i表示后缀, j表示前缀
    next[1] = 0;
    while(i < t[0])
    {
        printf("i=%d, j=%d\n", i, j);
        if (j == 0 || t[i] == t[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];       // 前缀是固定的,后缀是相对的
        }
    }
}

int main()
{
    char* t = "9ababaaaba";
    int i;
    int next[10];
    get_next(next, t);
    for(i=0; i<10; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
}