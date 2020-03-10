#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 50
#define ERROR 0
#define OK 1
#define STACK_SIZE 100
#define STACK_INCREASE_SIZE 20

typedef int status;
typedef int Elemtype;

typedef struct stack{
    int* base;
    int* top;
    int stackSize;
} Stack;

// 初始化一个栈
status InitStack(Stack* s){
    s->base = (Elemtype*)malloc(STACK_SIZE* sizeof(Elemtype));
    if (!s->base){
        return ERROR;
    }
    s->top = s->base;
    s->stackSize = STACK_SIZE;
    return OK;
}

// 入栈: 满栈不能入栈
// 难点在于realloc(*ptr, refine_size)函数的使用
status Push(Stack* s, int e){
    if (s->top - s->base >= s->stackSize){
        s->base = (int*)realloc(s->base, s->stackSize + STACK_INCREASE_SIZE * sizeof(int));
        if (!s->base){
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
    return OK;
}

// 出栈:空栈不能出栈
status Pop(Stack* s, int* e){
    if (s->base == s->top){
        return ERROR;
    }
    *e = *--(s->top);
    return OK;
}

// 清空一个栈
status Clear(Stack* s){
    s->top = s->base;
}

// 销毁一个栈
status Delete(Stack* s){
    int i;
    for (i=0; i<=s->stackSize; i++){
        free(--(s->top));
    }
    s->top = s->base = NULL;
    s->stackSize = 0;
}

// 计算栈的当前容量
status CurrentSize(Stack* s){
    return (s->top - s->base);
}
