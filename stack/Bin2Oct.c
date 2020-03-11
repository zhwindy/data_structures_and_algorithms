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

/*
卡住的点有以下几个:
1.如何正确的设置循环双重循环?
2.怎么处理不足3位时的循环以及后续的处理?
*/

// 二进制数转换为八进制数
int main(){
    Stack a, b;
    char c;
    int i, j, q, k=0, len;

    CreateStack(&a);
    CreateStack(&b);

    printf("请输入二进制串,以#结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        Push(&a, c);
        scanf("%c", &c);
    }

    getchar();

    len = StackLen(a);
    printf("栈A的当前容量为:%d\n", len);

    for(i=0; i<len; i+=3){
        if (a.top - a.base >= 3){
            for(j=0; j<3; j++){
                Pop(&a, &c);
                k += (c - 48) * pow(2, j);
            }
            Push(&b, k + 48);
            k = 0;
        }
        else{
            q = a.top - a.base;
            // 这里使用q作为循环结束的条件是正确的, 而直接使用j<(a.top - a.base)作为条件是错误的,因为a.top是动态变化的
            for(j=0; j<q; j++){
                Pop(&a, &c);
                k += (c - 48) * pow(2, j);
            }
            Push(&b, k + 48);
        }
    }
    len = StackLen(b);

    printf("栈B的当前容量为:%d\n", len);

    printf("转换成八进制数为:");
    for(i=0;i<len; i++){
        Pop(&b, &c);
        printf("%c", c);
    }
    printf("\n");
}