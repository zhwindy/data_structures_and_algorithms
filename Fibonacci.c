#include "stdio.h"

// 斐波那契数列迭代实现
int main_iter(int size){
    int a[size];
    int i;
    a[0] = 0;
    a[1] = 1;
    for(i=2; i<size; i++){
        a[i] = a[i-1] + a[i-2];
    }
    printf("斐波那契数列迭代实现结果:");
    for(i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 1;
}

// 斐波那契数列递归实现
int fib(int n){
    if(n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int i, n;
    printf("请出入需要计算的斐波那契数列个数:");
    scanf("%d", &n);
    printf("斐波那契数列递归实现结果:");
    for(i=0; i<=n; i++){
        printf("%d ", fib(i));
    }
    printf("\n");

    main_iter(n);

    return 1;
}