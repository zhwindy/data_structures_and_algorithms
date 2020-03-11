#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"

#define ERROR 0
#define OK 1
#define STACK_SIZE 50
#define CACHE_SIZE 10

typedef double ElemType;

typedef struct stack{
    ElemType* top;
    ElemType* base;
    int stackSize;
} Stack;

int InitStack(Stack* s){
    s->base = (ElemType*)malloc(STACK_SIZE * sizeof(ElemType));
    s->top = s->base;
    s->stackSize = STACK_SIZE;
    return OK;
}

int Push(Stack* s, ElemType e){
    if (s->top - s->base >= s->stackSize){
        return ERROR;
    }
    *(s->top) = e;
    s->top++;
    return OK;
}

int Pop(Stack* s, ElemType* e){
    if (s->top == s->base){
        return ERROR;
    }
    *e = *--(s->top);
    return OK;
}

int StackLen(Stack s){
    return (s.top - s.base);
}

/*
计算逆波兰表达式的值,由用户通过键盘出入后缀表达式,要求
1.实现对逆波兰输入的表达书进行计算
2.支持带小数点的数据

难点:
1.怎么忽略数字和运算符间的的空格?  switch...case
2.怎么判断当前输入的是数字还是运算符?  isdigit()
3.输入的字符型数据怎么转换为数字入栈?  atof()
*/
int main(){
    Stack a;
    ElemType i, j, result;
    int len, k=0;
    char c;
    char str[CACHE_SIZE];
    InitStack(&a);
    printf("请输出合法的逆波兰表达式(后缀表达式), 数据和符号间以空格隔开,以#表示结束:");
    scanf("%c", &c);
    while (c != '#')
    {
        while (isdigit(c) || c == '.')  // 过滤数字,支持浮点型
        {
            str[k] = c;
            k++;
            str[k] = '\0';
            if (k >= CACHE_SIZE){
                printf("输入的数字太长");
                return -1;
            }

            scanf("%c", &c);

            if (c == ' '){
               Push(&a, atof(str));
               k = 0;
               break;
            }
        }
        
        switch (c)
        {
            case '+':
                Pop(&a, &i);
                Pop(&a, &j);
                Push(&a, i + j);
                break;
            case '-':
                Pop(&a, &i);
                Pop(&a, &j);
                Push(&a, j - i);
                break;
            case '*':
                Pop(&a, &i);
                Pop(&a, &j);
                Push(&a, i * j);
                break;
            case '/':
                Pop(&a, &i);
                Pop(&a, &j);
                Push(&a, j / i);
                break;
        }
        scanf("%c", &c);
    }
    len = StackLen(a);
    printf("栈的容量为:%d", len);
    printf("\n");

    Pop(&a, &result);
    printf("计算结果为:%f", result);
    printf("\n");

    return OK;
}