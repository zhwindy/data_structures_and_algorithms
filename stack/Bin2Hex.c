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

// 初始化栈
int CreateStack(Stack* s){
    s->base = (char*)malloc(STACK_SIZE * sizeof(char));
    if (!s){
        return ERROR;
    }
    s->top = s->base;
    s->stackSize = STACK_SIZE;
    return OK;
}

// 入栈
int Push(Stack* s, char e){
    if (s->top - s->base >= s->stackSize){
        s->base = (char*)realloc(s->base, s->stackSize + STACK_INCREASE_SIZE * sizeof(char));
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INCREASE_SIZE;
    }
    *(s->top) = e;
    s->top++;
    return OK;
}

// 出栈
int Pop(Stack* s, char* e){
    if (s->top == s->base){
        return ERROR;
    }
    *e = *--(s->top);
    return OK;
}

int StackLen(Stack s){
    return (s.top - s.base);
}

// 二进制数转换为十六进制数
int main(){
    Stack a, b;
    char c;
    int i, j, k, len, sum=0;

    CreateStack(&a);
    CreateStack(&b);

    printf("请输入二进制串,以#结尾:");
    scanf("%c", &c);
    while (c != '#')
    {
        Push(&a, c);
        scanf("%c", &c);
    }

    getchar();
    len = StackLen(a);

    printf("栈A的当前容量为:%d\n", len);

    for(i=0; i<len; i+=4){
        if(a.top - a.base >= 4){
            for(j=0; j<4; j++){
                Pop(&a, &c);
                sum += (c - 48) * pow(2, j);
            }
            if(sum > 9){
                Push(&b, sum + 87);
            }
            else{
                Push(&b, sum + 48);
            }
            sum = 0;
        }
        else{
            k = a.top - a.base;
            for(j=0; j<k; j++){
                Pop(&a, &c);
                sum += (c - 48) * pow(2, j);
            }
            if(sum > 9){
                Push(&b, sum + 87);
            }
            else{
                Push(&b, sum + 48);
            }
            sum = 0;
        }
    }

    len = StackLen(b);
    printf("栈B的当前容量为:%d\n", len);

    printf("转换为十六进制数为:");
    for(i=0; i<len; i++){
        Pop(&b, &c);
        printf("%c", c);
    }
    printf("\n");
}