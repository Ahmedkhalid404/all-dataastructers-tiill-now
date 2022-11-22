#ifndef LINKED_CURRENT
#define LINKED_CURRENT
//*********************************************************************
typedef int Type;
//*********************************************************************
typedef struct NodeLCurrent
{
    struct NodeLCurrent *pNext;
    Type el;
}NodeLC;
typedef struct linked_current
{
    NodeLC *head,*current;
    int currentPosition,size;
}Linked_Current;
//*********************************************************************
//protoTypes
//create
void createListCurrent(Linked_Current *l);
//*********************************************************************
//is empty
int isLinkedCurrentEmpty(Linked_Current l);
//*********************************************************************
//is full
int isLinkedCurrentFull(Linked_Current l);
//*********************************************************************
int linkedCurrentSize(Linked_Current l);
//*********************************************************************
int insertLinkedCurrent(Linked_Current *l,Type el,int position);
//*********************************************************************
int deleteLinkedCurrent(Linked_Current *l,Type *el,int position);
//*********************************************************************
void traverseLinkedCurrent(Linked_Current *l,void(*operation)(Type*));
//*********************************************************************
int linkedCurrentAt(Linked_Current *l,Type *el,int position);
//*********************************************************************

#endif // LINKED_CURRENT
