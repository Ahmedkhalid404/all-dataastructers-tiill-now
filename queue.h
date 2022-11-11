#ifndef QUEUE
#define QUEUE
typedef int typeQ;
//******************************************************
typedef struct nodeQ
{
    typeQ info;
    struct nodeQ *pNext;
}NodeQ;
//*********************
typedef struct queue
{
   NodeQ *front;
   NodeQ *rear;
   int size;
}Queue;
//******************************************************
//prototypes
void createQueue(Queue *q);
int isQueueEmpty(Queue q);
int isQueueFull(Queue q);
int queueSize(Queue q);
int enQueue(Queue *q,typeQ el);
int deQueue(Queue *q,typeQ *el);
int frontElment(Queue q,typeQ *el);
void traverseQueue(Queue *q,void(*operation)(typeQ *));


#endif // QUEUE
