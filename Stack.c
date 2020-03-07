#include "stdio.h"

#define MAXSIZE 50

typedef struct stack{
    int* base;
    int* top;
    int stackSize;
} Stack;


typedef struct {
    int data[MAXSIZE];
    int top;
    int stackSize;
} SeqStack;