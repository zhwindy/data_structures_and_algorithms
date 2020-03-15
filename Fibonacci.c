#include "stdio.h"

// 斐波那契数列迭代实现
int main_iter(){
    int a[40];
    int i;
    a[0] = 0;
    a[1] = 1;
    for(i=2; i<40; i++){
        a[i] = a[i-1] + a[i-2];
    }
    for(i=0; i<40; i++){
        printf("%d ", a[i]);
    }
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
    int n=10;
    printf("%d", fib(n));
    return 1;
}