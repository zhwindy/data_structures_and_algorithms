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
目标：
将中缀表达式转换为后缀表达式(逆波兰表达式)输出

难点:
1.如何确定和比较运算符的优先级?

示例：
1. 4+(5-2) ---> 4 5 2 - +
2. 1+(2-3)*4+10/5   ---> 1 2 3 - 4 * + 10 5 / +
*/
int main(){
    Stack a;
    int i=0, j, len;
    char c, e;

    InitStack(&a);
    printf("请输入合法的中缀表达式,以#结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        while(c >= '0' && c <= '9'){
            printf("%c", c);
            scanf("%c", &c);
            if (c < '0' || c > '9'){
                printf(" ");
            }
        }
        if ( c == ')'){
            Pop(&a, &e);
            while (e != '(')
            {
                printf("%c ", e);
                Pop(&a, &e);
            }
            
        }
        else if (c == '+' || c == '-'){
            if(!StackLen(&a)){
                Push(&a, c);
            }
            else
            {
                do{
                    Pop(&a, &e);
                    if (e != '('){
                        printf("%c ", e);
                    }
                    else{
                        Push(&a, e);    //这里是将从栈里弹出的符号再入栈,而不是将接收的符号入栈Push(&a, c)
                    }
                }while (StackLen(&a) && e != '(');
                Push(&a, c);   // 上述判断完毕后,需将本符号入栈
            }
        }
        else if (c == '*' || c == '/' || c == '('){
            Push(&a, c);
        }
        else if (c == '#'){   // 上面有个while循环接收,所以这里需要对是否为#进行判断,否则会有输入错误. 如输入45#的话,会显示输入错误
            break;
        }
        else{
            printf("输入错误");
        }
        scanf("%c", &c);
    }

    len = StackLen(&a);
    for(j=0; j<len; j++){
        Pop(&a, &e);
        printf("%c ", e);
    }
    printf("\n");
}