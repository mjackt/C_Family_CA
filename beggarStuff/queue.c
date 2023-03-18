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

Queue* createQueue(int maxElements){
    Queue* Q;
    Q = (Queue *)malloc(sizeof(Queue));

    Q->elements = (int*)malloc(sizeof(int)*maxElements);
    Q->size = 0;
    Q->maxSize = maxElements;
    Q->front = 0;
    Q->tail = -1;
    /* Return pointer */
    return Q;
}

void dequeue(Queue* Q){
    if(Q->size==0){
        printf("Empty queue\n");
        return;
    }
    /* Removing an element means increasing index of head by one */
    else{
        Q->size--;
        Q->front++;

        if(Q->front==Q->maxSize){
            Q->front=0;
        }
    }
    return;
}

int peekQueue(Queue* Q){
    if(Q->size==0){
        printf("Queue is Empty\n");
        exit(0);
    }
    /* Return the element which is at the front*/
    return Q->elements[Q->front];
}

void enqueue(Queue *Q,int element){
    if(Q->size == Q->maxSize){
            printf("Queue is Full\n");
    }
    else{
        Q->tail = Q->tail + 1;
        Q->size++;
        //Checking if circled round
        if(Q->tail == Q->maxSize)
        {
            Q->tail = 0;
        }
        Q->elements[Q->tail] = element;
    }
}

void clearQueue(Queue* q){
    free(q->elements);
}

int getQueueSize(Queue* q){
    return q->size;
}

void printQueue(Queue* q){
    Queue* copyQueue = createQueue(52);
    copyQueue->elements=q->elements;
    copyQueue->front=q->front;
    copyQueue->maxSize=q->maxSize;
    copyQueue->size=q->size;
    copyQueue->tail=q->tail;

    if(copyQueue->size>0){
        printf("%d ",peekQueue(copyQueue));
        dequeue(copyQueue);
        printQueue(copyQueue);
    }
}
/*
int main()
{
        Queue *Q = createQueue(5);
        enqueue(Q,1);
        enqueue(Q,2);
        enqueue(Q,3);
        enqueue(Q,4);
        printf("Front element is %d\n",peek(Q));
        enqueue(Q,5);
        dequeue(Q);
        enqueue(Q,6);
        printf("Front element is %d\n",peek(Q));
}
*/