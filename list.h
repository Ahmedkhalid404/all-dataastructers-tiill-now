#ifndef LIST
#define LIST
typedef int typeL;
//******************************************************
typedef struct nodeL
{
    typeL info;
    struct nodeL *pNext;
}NodeL;
//**********************
typedef struct list
{
    NodeL *top;
    int size;
}List;
//*******************************************************
//prototypes
//*******************************************************
//create
void createList(List *l);
//*******************************************************
//is empty
int isListEmpty(List l);
//*******************************************************
//is full
int isListFull(List l);
//*******************************************************
//size
int listSize(List l);
//*******************************************************
//insert
int insert(List *l,typeL el,int position);
//*******************************************************
//erase
int erase(List *l,typeL *el,int position);
//*******************************************************
//top element
int ListAt(List l,typeL *el,int position);
//*******************************************************
//traverse
void traverseList(List *l,void(*operation)(typeL *));
//*******************************************************
//edit at
int listEditEl(List *l,typeL el,int position);
//*******************************************************
#endif // LIST
