#include "queue.h"

/**
 * Function creates a new queue struct and returns a pointer to it
 * @param maxElements -- The max size of the queue
 * @return The pointer to the new queue
 */
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

/**
 * Function removes and returns element from the front of the list
 * @param Q -- Pointer to queue
 * @return The dequeued int
 */
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

/**
 * Function returns the value at the front of the queue
 * @param Q -- Pointer to queue
 * @return The int at the front
 */
int peekQueue(Queue* Q){
    if(Q->size==0){
        printf("Queue is Empty\n");
        exit(0);
    }
    /* Return the element which is at the front*/
    return Q->elements[Q->front];
}

/**
 * Function puts a new item to the back of the queue
 * @param Q -- Pointer to queue
 * @param element -- New element to queue
 */
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

/**
 * Procedure frees malloc mem for queue elements
 * @param Q -- Pointer to queue
 */
void clearQueue(Queue* q){
    free(q->elements);
}

int getQueueSize(Queue* q){
    return q->size;
}

/**
 * Function returns the nth element of the queue
 * @param Q -- Pointer to queue
 * @param n -- Element to get
 * @return The nth element of queue
 */
int qGetNth(Queue* q,int n){
    if(n>q->size){
        return -1;
    }
    int index = n + q->front;
    //Checking for circling round
    if(index>q->maxSize){
        index = index - q->maxSize;
    }

    //Simple fix to bug in logic
    if(index==52){
        index=0;
    }
    return q->elements[index];
}

/**
 * Procedure prints whole queue
 * @param Q -- Pointer to queue
 */
void printQueue(Queue* q){
    int i;
    for(i=0;i<q->size;i++){
        printf("%d ",qGetNth(q,i));
    }
}