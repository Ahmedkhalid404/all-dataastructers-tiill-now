#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "doubly.h"
//create
void createDoubleList(DoubleList *dl)
{
    dl->top     = NULL;
    dl->size    =   0 ;
}
//**********************************************************************
//is empty
int isDoubleListEmpty(DoubleList dl)
{
    return dl.size==0;
}
//**********************************************************************
//is full
int isDoubleListFull(DoubleList dl)
{
    return 0;
}
//**********************************************************************
//size
int DoubleListSize(DoubleList dl)
{
     return dl.size;
}
//**********************************************************************
//insert
int insertDoubleList(DoubleList *dl,typeDouble el,int key)
{
    NodeD *pNewNode = (NodeD *) malloc( sizeof(NodeD) );
    pNewNode->key  = key;
    pNewNode->info = el;
    if(dl->size == 0)
    {
        pNewNode->info          = el;
        pNewNode->key           = key;
        pNewNode->pNext         = NULL;
        pNewNode->pPrevious     = NULL;
        dl->top                 = pNewNode;
    }
    else
    {
        NodeD *temp = dl->top;
        if(key <= temp->key)
        {
            pNewNode->pNext     = temp;
            pNewNode->pPrevious = NULL;
            dl->top             = pNewNode;
            temp->pPrevious     = pNewNode;
        }
        else
        {
            while(-404)
                {
                     if(temp->pNext == NULL)
                        {
                            pNewNode->pNext = NULL;
                            temp->pNext = pNewNode;
                            pNewNode->pPrevious  = temp;
                            break;

                        }
                    else
                    {
                        if( key >= temp->key && key <= temp->pNext->key )
                            {
                                pNewNode->pNext = temp->pNext;
                                pNewNode->pPrevious = temp;
                                temp->pNext->pPrevious = pNewNode;
                                temp->pNext = pNewNode;
                                break;
                            }
                    }
                    temp = temp->pNext;

                }


            }
        }

    dl->size++;
}
//**********************************************************************
//erase from position
int eraseDoubleList(DoubleList *dl,typeDouble *el,int key)
{
    if(!isDoubleListEmpty(*dl))
    {
        NodeD *temp = dl->top;
        while(temp)
        {
            if(key == temp->key)
            {
                *el = temp->info;
                if(temp->pNext == NULL)
                {
                    temp->pPrevious->pNext = NULL;
                    temp->pPrevious=NULL;
                    free(temp);
                }
                else if(temp->pPrevious == NULL)
                {
                    dl->top = temp->pNext;
                    if(dl->size > 1)
                    {
                        temp->pNext->pPrevious = NULL;
                    }
                    temp->pNext = NULL;
                    free(temp);

                }
                else
                {
                    *el = temp->info;
                    temp->pNext->pPrevious = temp->pPrevious;
                    temp->pPrevious->pNext = temp->pNext;
                    temp->pNext = NULL;
                    temp->pPrevious = NULL;
                    free(temp);
                }
                dl->size--;
                return 1;
            }
            temp = temp->pNext;
        }
        *el = -404;
        return 1;
    }
    else
        return 0;
}
//**********************************************************************
//traverse
void traverseDoubleList(DoubleList *dl,void(*operation)(typeDouble *))
{
    NodeD *temp = dl->top;
    while(temp)
    {
        (*operation)(&temp->info);
        temp = temp->pNext;
    }
}
//**********************************************************************




