#include <stdio.h>
#include <stdlib.h>

/**
 * maxSize -- Max size of queue
 * size -- Current size of queue
 * elemenets -- Pointer to array of elements
 * tail -- Index of the tail element
 * front -- Index of the front element
 */
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