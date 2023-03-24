#include "stack.h"

/**
 * Function creates a new stack struct
 * @param maxElements -- The max size of the stack to be created
 * @return Pointer to created stack
 */
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

/**
 * Function takes the top element from the stack and returns it
 * @return Int from top of the stack
 */
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

/**
 * Function returns top int without popping it
 * @return int from top of the stack
 */
int peekStack(Stack* s){
    if(s->size==0){
        return -1;
    }
    /* Return the element which is at the top*/
    return s->elements[s->top];
}

/**
 * Function pushes an element to the top of the stack
 * @param int to push
 */
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

/**
 * Frees a stacks malloced elements
 * @param pointer to stack
 */
void clearStack(Stack* s){
    free(s->elements);
}

int getStackSize(Stack* q){
    return q->size;
}

/**
 * Procedure prints a full stack to terminal
 * @param pointer to stack
 */
void printStack(Stack* s){
    int i;
    for (i=0;i<s->size;i++){
        printf(" %d ",s->elements[i]);
    }
}