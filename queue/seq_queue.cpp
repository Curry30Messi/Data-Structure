#include<stdio.h>
#include<malloc.h>
#define MaxSize 8

typedef struct{
    int data[MaxSize];
    int front;
    int rear;
}Queue;

void InitSeQueue(Queue *queue){
    queue->front=0;
    queue->rear=0;
}
int GetLength(Queue *queue){
    return (queue->rear-queue->front + MaxSize)%MaxSize;
}
bool isEmpty(Queue *queue){
    return queue->front==queue->rear;
}
bool isFull(Queue *queue){
    return (queue->rear+1)%MaxSize==queue->front;
}
void EnterQueue(Queue *queue,int e){
    if (isFull(queue))
    {
        printf("队列满了\n");
        return ;
    }
    else{
        queue->data[queue->rear]=e;
        queue->rear=(queue->rear+1)%MaxSize;
    }
}
void ExitQueue(Queue *queue,int *e){
    if(isEmpty(queue)){
        printf("已经是空队列了\n");
        return;
    }
    else{
        *e=queue->data[queue->front];
        queue->front=(queue->front+1)%MaxSize;
    }
}
