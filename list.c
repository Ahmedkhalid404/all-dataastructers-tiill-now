#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//create
void createList(List *l)
{
    l->top = NULL;
    l->size = 0;
}
//*******************************************************
//is empty
int isListEmpty(List l)
{
        return l.size == 0;
//or    return l.top == NULL;
}
//*******************************************************
//is full
int isListFull(List l)
{
    return 0;
}
//*******************************************************
//is full
int listSize(List l)
{
    return l.size;
}
//*******************************************************
//insert
int insert(List *l,typeL el,int position)
{
    if( position >= 0 && position <= l->size )
    {
        NodeL *pNewNode = (NodeL *) malloc( sizeof(NodeL) );
        pNewNode->info = el;
        if(position == 0)
        {
            pNewNode->pNext = l->top;
            l->top          = pNewNode;
        }
        else
        {
            NodeL *temp     = l->top;
            for(int i=0;i < (position-1) ;i++ )
            {
                temp = temp->pNext;
            }
            pNewNode->pNext = temp->pNext;
            temp->pNext = pNewNode;
        }

        l->size++;
        return 1;
    }
    else
    {
        return 0;
    }
}
//*******************************************************
//erase
int erase(List *l,typeL *el,int position)
{
    if(position >= 0 && position <= l->size - 1)
    {
        if(!isListEmpty(*l))
        {
            NodeL *temp = l->top;

            for(int i=0;i< ( position - 1 ) ;i++)
            {
                temp = temp->pNext;
            }
            if(position == 0)
            {
                l->top = temp->pNext;
            }
            else
            {
                temp->pNext = temp->pNext->pNext;
                temp = temp->pNext;
            }
            *el = temp->info;
            temp->pNext = NULL;
            free(temp);
            l->size--;
            return 1;

        }
        else
        {
            return 0;//list is empty
        }
    }
    else
    {
        return 0;//position is out of boundry
    }
}
//*******************************************************
//get element
int ListAt(List l,typeL *el,int position)
{
    if(position >= 0 && position <= l.size-1)
    {
        if(!isListEmpty(l))
        {
            NodeL *temp = l.top;
            for(int i=0;i<position;i++)
            {
                temp = temp->pNext;
            }
            *el = temp->info;
            return 1;
        }
        else
        {
            return 0;//list is empty
        }
    }
    else
    {
        return 0;//position is out of boundry
    }
}
//*******************************************************
//traverse
void traverseList(List *l,void(*operation)(typeL *))
{
    NodeL *temp = l->top;
    while(temp)
    {
        (*operation)(&temp->info);
        temp = temp->pNext;
    }
}
//*******************************************************
//edit at
int listEditEl(List *l,typeL el,int position)
{
    if( position >= 0 && position <= l->size-1 )
    {
        if(!isListEmpty(*l))
        {
            NodeL *temp = l->top;
            for(int i=0;i<position;i++)
            {
                temp = temp->pNext;
            }
            temp->info = el;
            return 1;
        }
        else
        {
            return 0;//list empty
        }
    }
    else
    {
        return 0;//position is out of boundry
    }
}
//*******************************************************


