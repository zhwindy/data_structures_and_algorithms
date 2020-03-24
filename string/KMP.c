#include "stdio.h"
#include "string.h"

// 用模式串生成Next数组: https://www.zhihu.com/question/21923021
void get_next(int* next, char* t){
    int i=0, j=-1, t_len;   // i表示后缀, j表示前缀
    int k;
    next[0] = -1;
    t_len = strlen(t);
    while(i < t_len)
    {
        // printf("i=%d, j=%d\n", i, j);
        if (j == -1 || t[i] == t[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];       // 前缀是固定的,后缀是相对的
        }
    }
    printf("求得的next数组为:\n");
    for(k=0; k<t_len; k++)
    {
        printf("%d ", next[k]);
    }
    printf("\n");
}

// kmp算法
void kmp(char* s, char* t, int* next, int* pos)
{
    int i=0, j=0;
    int s_len, t_len;
    s_len = strlen(s);
    t_len = strlen(t);
    while (i < s_len && j < t_len)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= t_len)
    {
        *pos = i - j;
    }
}

// KMP算法的思想精髓在于:匹配的关键取在于模式串本身而不是主串.所以算法的关键在于用模式串计算出next数组,用于指导匹配时,模式串的回溯位置
int main()
{
    char* st = "Ilovezhaypqngfei.cababaaabaoldlar.cc we love bitcoin";
    char* rt = "ababaaaba";
    int pos;
    int next[10];
    get_next(next, rt);
    kmp(st, rt, next, &pos);
    printf("子串在主串中的位置为: %d\n", pos);
}