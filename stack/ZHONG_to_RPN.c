#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define OK 1
#define ERROR 0
#define STACK_SIZE 20
#define BUFFER_SIZE 10

typedef char ElemType;

typedef struct {
    ElemType* top;
    ElemType* base;
    int stackSize;
} Stack;

int InitStack(Stack* s){
    s->base = (ElemType*)malloc(STACK_SIZE * sizeof(ElemType));
    if (! s->base){
        return -1;
    }
    s->top = s->base;
    s->stackSize = STACK_SIZE;
    return OK;
}

int Push(Stack* s, ElemType e){
    if(s->top - s->base >= s->stackSize){
        return -1;
    }
    *s->top = e;
    s->top++;

    return OK;
}

int Pop(Stack* s, ElemType* e){
    if(s->top == s->base){
        return -1;
    }
    *e = *--(s->top);
    return OK;
}

int StackLen(Stack* s){
    return (s->top - s->base);
}

/*
目标：将中缀表达式转换为后缀表达式(逆波兰表达式)输出, 如中缀表达式4+(5-2) ---> 后缀表达式452-+
难点:
1.如何确定和比较运算符的优先级?
*/
int main(){
    Stack a;
    int i=0, j, len;
    double p;
    char c, e;
    char str[BUFFER_SIZE];

    InitStack(&a);
    printf("请输入合法的中缀表达式,以#结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        while (isdigit(c))
        {
            str[i] = c;
            i++;
            str[i] = '\0';
            if (i >= BUFFER_SIZE){
                printf("输入的数字长度超限");
                return -1;
            }
            scanf("%c", &c);

            if(c == ' '){
                p = atof(str);
                printf("%f ", p);
                i = 0;
                break;
            }
        }
        switch(c){
            case '+':
                Push(&a, c);
                break;
            case '-':
                Push(&a, c);
                break;
            case '*':
                Push(&a, c);
                break;
            case '/':
                Push(&a, c);
                break;
            case '(':
                break;
            case ')':
                break;
            default:
                break;
        }
        scanf("%c", &c);
    }

    len = StackLen(&a);
    for(j=0; j<len; j++){
        Pop(&a, &e);
        printf("%c", e);
    }
    printf("\n");
}