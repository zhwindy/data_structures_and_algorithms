#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define OK 1
#define ERROR 0

typedef int ELemType;

struct SeqList{
    ELemType data[MAXSIZE];
    int length;
};

// 创建具有n个元素的顺序表
int CreateSeqList(struct SeqList *L, int n){
    int i;
    L->length = 0;
    for (i=0; i<n; i++){
        L->data[i] = i + 1;
        L->length++;
    }
    return OK;
}

// 打印顺序表的内容
void PrintSeqList(struct SeqList *L){
    int i;
    printf("数组的长度是: %d\n", L->length);
    for(i=0; i<L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 与单链表的动态申请空间不同,顺序表需要预先申请数组空间
int main(){
    struct SeqList L;
    int n;
    printf("请输入数组的长度: ");
    scanf("%d", &n);
    while(n <0 || n > MAXSIZE){
        printf("请输入正确的数值: ");
        scanf("%d", &n);
    }
    CreateSeqList(&L, n);
    PrintSeqList(&L);
    return OK;
}