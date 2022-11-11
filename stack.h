#ifndef STACK
#define STACK
//******************************************************
typedef int typeS;
//******************************************************
typedef struct nodeS
{
    typeS info;
    struct nodeS *pNext;
}NodeS;

typedef struct stack
{
    NodeS *top;
    int size;
}Stack;
//******************************************************
//******************************************************
//prototypes
//******************************************************
void createStack(Stack *s);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
int stackSize(Stack s);
int push(Stack *s,typeS el);
int pop(Stack *s,typeS *el);
int peek(Stack s,typeS *el);
void traverseStack(Stack *s,void(*operation)(typeS *));
//******************************************************
#endif // STACK
