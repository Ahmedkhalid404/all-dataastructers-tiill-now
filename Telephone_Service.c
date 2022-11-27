#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "Telephone_Service.h"
//create
void createMobile(MobileCall *pm){
    pm->head = NULL;
    pm->sizeP1 = 0;
    pm->sizeP2 = 0;
    pm->sizeP3 = 0;
}
//******************************************************
//is empty
int isMobileEmpty(MobileCall *pm )
{
    return !(pm->sizeP1 + pm->sizeP2 + pm->sizeP3);
}
//******************************************************
//size
int sizeMobile(MobileCall *pm)
{
    return pm->sizeP1 + pm->sizeP2 + pm->sizeP3;
}
//******************************************************
//is Emergency empty
int isEmergencyEmpty(MobileCall *pm )
{
    return !pm->sizeP3;
}
//******************************************************
//size Emergency
int sizeEmergency(MobileCall *pm )
{
    return pm->sizeP3;
}
//******************************************************
//is Voice Call empty
int isVoiceCall(MobileCall *pm )
{
    return !pm->sizeP2;
}
//******************************************************
//size Voice Call
int sizeVoiceCall(MobileCall *pm )
{
    return pm->sizeP2;
}
//******************************************************
//is Data Call empty
int isDataCallEmpty(MobileCall *pm )
{
    return !pm->sizeP1;
}
//******************************************************
//size Data Call
int sizeDataCall(MobileCall *pm )
{
    return pm->sizeP1;
}
//******************************************************
//serve a call
int serveCall(MobileCall *pm,char el[11])
{
    if(!isMobileEmpty(pm))
    {
        if(pm->head->periority == 1)
            pm->sizeP1--;
        if(pm->head->periority == 2)
            pm->sizeP2--;
        if(pm->head->periority == 3)
            pm->sizeP3--;
        strcpy(el,pm->head->phoneNumber);
        MobileNode *temp = pm->head;
        if(pm->head->pNext == NULL)
        {
            pm->head = NULL;
        }
        else
        {
            pm->head = pm->head->pNext;
            pm->head->pPrev = NULL;
        }
        free(temp);
        return 1;
    }
    el = "-404";
    return 0;
}
//******************************************************
//disMiss Least Priority
void disMissLeastPriority(MobileCall *pm)
{
    if(sizeDataCall(pm)>0)
    {
        MobileNode *temp1,*temp2;
        temp1 = pm->head;
        temp2 = pm->head;
        while(temp1->periority != 1)
        {
            temp1 = temp1->pNext;
            temp2 = temp2->pNext;
        }
        temp1->pPrev->pNext = NULL;
        while(temp1)
        {
            temp1 = temp1->pNext;
            free(temp2);
            temp2 = temp1;
        }
        pm->sizeP1 = 0;

    }
    else if(sizeVoiceCall(pm) > 0)
    {
        MobileNode *temp1,*temp2;
        temp1 = pm->head;
        temp2 = pm->head;
        while(temp1->periority != 2)
        {
            temp1 = temp1->pNext;
            temp2 = temp2->pNext;
        }
        temp1->pPrev->pNext = NULL;
        while(temp1)
        {
            temp1 = temp1->pNext;
            free(temp2);
            temp2 = temp1;
        }
        pm->sizeP2 = 0;
    }
    else
    {
        printf("all call are Emergency!!!!\n");
    }
}
//******************************************************
//insert call
void insertCall(MobileCall *pm,int periority,char el[11])
{
    if(periority == 1)
        pm->sizeP1++;
    if(periority == 2)
        pm->sizeP2++;
    if(periority == 3)
        pm->sizeP3++;
    MobileNode *pNewNode = (MobileNode*) malloc( sizeof(MobileNode) );
    pNewNode->periority = periority;
    strcpy(pNewNode->phoneNumber,el);
    MobileNode *temp = pm->head;
    if(pm->head == NULL)
    {
        pm->head = pNewNode;
        pNewNode->pNext = NULL;
        pNewNode->pPrev = NULL;
    }
    else if((pm->head->periority) < (periority))
    {
        pm->head->pPrev = pNewNode;
        pNewNode->pNext = pm->head;
        pNewNode->pPrev = NULL;
        pm->head = pNewNode;
    }

    else{
        while(temp->periority >= periority && temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        if(temp->pNext == NULL && temp->periority >= periority)
        {
            pNewNode->pNext = NULL;
            pNewNode->pPrev = temp;
            temp->pNext = pNewNode;
        }
        else
        {
            pNewNode->pNext = temp;
            pNewNode->pPrev = temp->pPrev;
            temp->pPrev->pNext = pNewNode;
            temp->pPrev = pNewNode;
        }
    }

}
//******************************************************
