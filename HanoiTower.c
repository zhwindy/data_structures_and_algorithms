#include "stdio.h"

//汉诺塔问题的移动步骤
void Hanoi(int n, char x, char y, char z, int* p){
    if(n == 1){
        printf("%c -> %c\n", x, z);
        (*p)++;
    }
    else{
        Hanoi(n-1, x, z, y, p);
        // Hanoi(1, x, y, z); 这步可以去掉,直接用printf替代
        printf("%c -> %c\n", x, z);
        (*p)++;
        Hanoi(n-1, y, x, z, p);
    }
}

int main(){
    int count, n=0;
    printf("请输入汉诺塔的层数:");
    scanf("%d", &count);
    Hanoi(count, 'x', 'y', 'z', &n);
    printf("移动的总步数: %d\n", n);
    return 1;
}