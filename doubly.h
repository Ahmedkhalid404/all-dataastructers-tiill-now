#ifndef DUBLEY
#define DUBLEY
//**********************************************************************
typedef int typeDouble;
//**********************************************************************
typedef struct nodeD
{
    struct nodeD *pNext;
    struct nodeD *pPrevious;
    int key;
    typeDouble info;
}NodeD;
//************************
typedef struct doubleList
{
    NodeD *top;
    int size;
}DoubleList;
//**********************************************************************
//prototypes
//**********************************************************************
//create
void createDoubleList(DoubleList *dl);
//**********************************************************************
//is empty
int isDoubleListEmpty(DoubleList dl);
//**********************************************************************
//is full
int isDoubleListFull(DoubleList dl);
//**********************************************************************
//size
int DoubleListSize(DoubleList dl);
//**********************************************************************
//insert
int insertDoubleList(DoubleList *dl,typeDouble el,int key);
//**********************************************************************
//erase from position
int eraseDoubleList(DoubleList *dl,typeDouble *el,int key);
//**********************************************************************
//traverse
void traverseDoubleList(DoubleList *dl,void(*operation)(typeDouble *));
//**********************************************************************
#endif // DUBLEY
