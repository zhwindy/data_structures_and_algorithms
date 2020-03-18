#include "stdio.h"
#include "string.h"

#define SIZE 100

//字符串的模式匹配
int bf(char* s, char* t, int* a){
    int i=0, j=0;
    int slen = strlen(s);
    int tlen = strlen(t);
    while (i< slen && j<tlen)
    {
        printf("i=%d, j=%d\n", i, j);
        if (s[i] == t[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    printf("i=%d, j=%d\n", i, j);
    if (j == tlen)
    {
        *a = (i - j);
        return 1;
    }
    return 0;
}

int main(){
    int pos=0;
    // char* st = "Ilovecold.cc";
    // char* rt = "vec";

    char* st = "Ilovezhaypqngfei.coldlar.cc we love bitcoin";
    char* rt = "coin";
    
    bf(st, rt, &pos);
    printf("子串的位置为: %d\n", pos);
}