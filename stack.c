#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//******************************************************
//create
void createStack(Stack *s)
{
    s->top  =  NULL;
    s->size =   0  ;
}
//******************************************************
//is empty
int isStackEmpty(Stack s)
{
        return s.top == NULL ;
//or    return s.size == 0;
}
//******************************************************
//is full
int isStackFull(Stack s)
{
    return 0;
}
//******************************************************
//size
int stackSize(Stack s)
{
    return s.size;
}
//******************************************************
//push
int push(Stack *s,typeS el)
{
    NodeS *pNewNode = (NodeS *) malloc( sizeof(NodeS) );
    pNewNode->info  = el;
    pNewNode->pNext = s->top;
    s->top          = pNewNode;
    s->size++;
    return 1;//refer to success push
}
//******************************************************
//pop
int pop(Stack *s,typeS *el)
{
    if(!isStackEmpty(*s))
    {
        NodeS *temp;
        temp = s->top;
        *el = temp->info;
        s->top = temp->pNext;
//or    s->top = s->top->pNext;
        free(temp);
        s->size--;
        return 1;
    }
    else
    {
        *el = -404;
        return 0;
    }
}
//******************************************************
//peek
int peek(Stack s,typeS *el)
{
    if(!isStackEmpty(s))
    {
        *el = s.top->info;
    }
    else
    {
        *el = -404;
        return 0;
    }
}
//******************************************************
//traverse
void traverseStack(Stack *s,void(*operation)(typeS *))
{
    NodeS *visitor = s->top;
    while(visitor)
    {
        (*operation)(&visitor->info);
        visitor = visitor->pNext;
    }
}
//******************************************************
