#include <stdio.h>
#include <stdlib.h>

typedef struct StackStruct{
        int maxSize;
        int size;
        int* elements;
        int top;
}Stack;

int pop(Stack*);
int peekStack(Stack*);
void push(Stack*,int);
void clearStack(Stack*);
int getStackSize(Stack*);
void printStack(Stack*);
Stack* createStack(int);