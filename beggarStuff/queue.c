#include "queue.h"

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

void enqueue(Queue* Q,int element){
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

int qGetNth(Queue* q,int n){
    if(n>q->size){
        return -1;
    }
    int index = n + q->front;
    //Checking for circling round
    if(index>q->maxSize){
        index = index - q->maxSize;
    }
    return q->elements[index];
}

void printQueue(Queue* q){
    int i;
    for(i=0;i<q->size;i++){
        printf("%d ",qGetNth(q,i));
    }
}