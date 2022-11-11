#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//******************************************************
//create
void createQueue(Queue *q)
{
    q->front = NULL;
    q->rear  = NULL;
    q->size  =  0  ;
}
//******************************************************
//is empty
int isQueueEmpty(Queue q)
{
        return q.front==NULL;
//or    return q.rear==NULL;
//or    return q.size == 0;
}
//******************************************************
//is full
int isQueueFull(Queue q)
{

    return 0;
}
//******************************************************
//size
int queueSize(Queue q)
{
    return q.size;
}
//******************************************************
int enQueue(Queue *q,typeQ el)
{
    NodeQ *pNewNode = (NodeQ *) malloc( sizeof( NodeQ ) );
    pNewNode->info = el;
    pNewNode->pNext = NULL;
    if(isQueueEmpty(*q))
    {
        q->front = pNewNode;
    }
    else
    {
        q->rear->pNext  = pNewNode;
    }
    q->rear         = pNewNode;
    q->size++;
    return 1;
}
//******************************************************
//dequeue
int deQueue(Queue *q,typeQ *el)
{
    if(!isQueueEmpty(*q))
    {
        NodeQ *temp = q->front;
        *el = temp->info;
        q->front = temp->pNext;
        //********************
        if(q->size == 1)
            q->rear = NULL;
        //********************
        free(temp);
        q->size--;
        return 1;
    }
    else
    {
        return 0;
    }
}
//******************************************************
//front element
int frontElment(Queue q,typeQ *el)
{
    if(!isQueueEmpty(q))
    {
        *el = q.front->info;
        return 1;
    }
    else
    {
        return 0;
    }
}
//******************************************************
//traverse
void traverseQueue(Queue *q,void(*operation)(typeQ *))
{
    NodeQ *temp = q->front;
    while(temp)
    {
        (*operation)(&temp->info);
        temp = temp->pNext;
    }
}
//******************************************************










