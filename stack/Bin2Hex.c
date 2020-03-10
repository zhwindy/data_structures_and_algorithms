#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define STACK_SIZE 50
#define STACK_INCREASE_SIZE 10
#define ERROR 0
#define OK 1

typedef struct stack{
    char* top;
    char* base;
    int stackSize;
} Stack;

int CreateStack(Stack* s){
    s->base = (char*)malloc(STACK_SIZE * sizeof(char));
    if (!s){
        return ERROR;
    }
    s->top = s->base;
    s->stackSize = STACK_SIZE;
    return OK;
}

int Push(Stack* s, char e){
    if (s->top - s->base >= s->stackSize){
        return ERROR;
    }
    *(s->top) = e;
    s->top++;
    return OK;
}

int Pop(Stack* s, char* t){
    if (s->top == s->base){
        return ERROR;
    }
    *t = *--(s->top);
    return OK;
}

int StackLen(Stack s){
    return (s.top - s.base);
}

// 二进制数转换为十六进制数
int main(){
    Stack a;
    char c;
    int i, len, sum=0;

    CreateStack(&a);

    printf("请输入二进制串,输入#表示结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        Push(&a, c);
        scanf("%c", &c);
    }

    getchar();
    len = StackLen(a);
    printf("栈的当前容量为:%d\n", len);

    for(i=0; i<len; i++){
        Pop(&a, &c);
        sum += (c - 48) * pow(2, i);
    }

    printf("转换为十进制数为:%d\n", sum);
}