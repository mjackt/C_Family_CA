#include <stdio.h>
#include <stdlib.h>

typedef struct StackStruct{
        int maxSize;
        int size;
        int* elements;
        int top;
}Stack;

Stack* createStack(int maxElements){
    Stack* s;
    s = (Stack *)malloc(sizeof(Stack));

    s->elements = (int*)malloc(sizeof(int)*maxElements);
    s->size = 0;
    s->maxSize = maxElements;
    s->top=-1;
    /* Return pointer */
    return s;
}

int pop(Stack* s){
    if(s->size==0){
        printf("Empty stack\n");
        exit(-1);
    }
    else{
        int popped = s->elements[s->top];
        s->size--;
        s->top--;
        return popped;
    }
}

int peekStack(Stack* s){
    if(s->size==0){
        printf("Stack is Empty\n");
        exit(-1);
    }
    /* Return the element which is at the top*/
    return s->elements[s->top];
}

void push(Stack *s,int element){
    if(s->size == s->maxSize){
        printf("Stack is Full\n");
    }
    else{
        s->top++;
        s->size++;
        s->elements[s->top] = element;
    }
}

void clearStack(Stack* s){
    free(s->elements);
}

int getStackSize(Stack* q){
    return q->size;
}

void printStack(Stack* s){
    int i;
    for (i=0;i<s->size;i++){
        printf(" %d ",s->elements[i]);
    }
}