#include <stdio.h>
#include <stdlib.h>

typedef struct QueueStruct
{
    int maxSize;
    int size;
    int* elements;
    int tail;
    int front;
}Queue;

Queue* createQueue(int);
void dequeue(Queue*);
int peekQueue(Queue*);
void enqueue(Queue*,int);
void clearQueue(Queue*);
int getQueueSize(Queue*);
int qGetNth(Queue*,int);
void printQueue(Queue*);