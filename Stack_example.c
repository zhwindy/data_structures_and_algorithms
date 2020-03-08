#include "stdio.h"

#define MAXSIZE 50

typedef struct stack{
    int data[MAXSIZE];
    int top;
    int stackSize;
} Stack;