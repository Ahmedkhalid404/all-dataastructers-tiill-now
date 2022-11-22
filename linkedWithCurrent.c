#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "linkedWithCurrent.h"

//create
void createListCurrent(Linked_Current *l)
{
    l->head             = NULL;
    l->current          = NULL;
    l->currentPosition  =  0;
    l->size             =  0;
}
//*********************************************************************
//is empty
int isLinkedCurrentEmpty(Linked_Current l)
{
    return !l.size;
}
//*********************************************************************
//is full
int isLinkedCurrentFull(Linked_Current l)
{
    return 0;
}
//*********************************************************************
int linkedCurrentSize(Linked_Current l)
{
    return l.size;
}
//*********************************************************************
int insertLinkedCurrent(Linked_Current *l,Type el,int position)
{
    if( position >= 0 && position <= l->size )
    {
        NodeLC *pNewNode = (NodeLC*) malloc( sizeof(NodeLC) );
        pNewNode->el = el;
        if(position <= l->currentPosition || position == 0 )
        {
            l->currentPosition = 0;
            l->current         = l->head;
        }
        for(; l->currentPosition < position-1 ; l->currentPosition++)
        {
            l->current = l->current->pNext;
        }
        if(position == 0)
        {
            pNewNode->pNext     = l->head;
            l->head             = pNewNode;
            l->current          = l->head;//hmmm
            l->currentPosition  = 0;//hmmm
        }
        else
        {
            pNewNode->pNext = l->current->pNext;
            l->current->pNext = pNewNode;
        }
        l->size++;
        return 1;
    }
    else
        return 0;//position out of boundry
}
//*********************************************************************
int deleteLinkedCurrent(Linked_Current *l,Type *el,int position)
{
    if(!isLinkedCurrentEmpty(*l))
    {
        if( position >= 0 && position < l->size )
        {
            if( position <= l->currentPosition || position == 0 )
            {
                l->current          = l->head;
                l->currentPosition  =   0;
            }
            for(;l->currentPosition < position-1 ;l->currentPosition++)
            {
                l->current = l->current->pNext;
            }
            if(position == 0)
            {
                *el = l->current->el;
                l->head = l->current->pNext;
                l->current->pNext = NULL;
                free(l->current);
                l->current          = l->head;
                l->currentPosition  =   0;
            }
            else
            {
                NodeLC *temp2 = l->current->pNext;
                *el = temp2->el;
                l->current->pNext = temp2->pNext;
                free(temp2);
            }
            l->size--;
            return 1;
        }
        else
        {
            return 0;//out of boundry
        }
    }
    else
    {
        return 0;//list is empty
    }
}
//*********************************************************************
void traverseLinkedCurrent(Linked_Current *l,void(*operation)(Type*))
{
    NodeLC *temp = l->head;
    for(int i=0;i<linkedCurrentSize(*l);i++)
    {
        (*operation)(&temp->el);
        temp = temp->pNext;
    }
}
//*********************************************************************
int linkedCurrentAt(Linked_Current *l,Type *el,int position)
{
    if( position >= 0 && position < l->size )
    {
        if( position < l->currentPosition || position == 0 )
        {
            l->currentPosition = 0;
            l->current         = l->head;
        }
        for(;l->currentPosition < position ;l->currentPosition++)
        {
            l->current = l->current->pNext;
        }
        *el = l->current->el;
        return 1;
    }
    else
        return 0;
}
//*********************************************************************





