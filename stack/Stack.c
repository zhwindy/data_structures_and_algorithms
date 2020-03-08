#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAXSIZE 50
#define ERROR 0
#define OK 1
#define STACK_SIZE 100

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
status Push(Stack* s, int n){
    if (!s){
        return ERROR;
    }
    if (s->top - s->base >= s->stackSize){
        return ERROR;
    }
    *(s->top) = n;
    s->top++;
}

// 出栈:空栈不能出栈
status Pop(Stack* s, int* e){
}

// 清空一个栈
status Clear(Stack* s){
    s->top = s->base;
}

// 销毁一个栈
status Delete(Stack* s){
}

// 计算栈的当前容量
status CurrentSize(Stack* s){
    return (s->top - s->base);
}


// 栈的应用进制转换问题: 二进制数转换为十进制数
int Transfer_2_to_10(Stack* s){
}