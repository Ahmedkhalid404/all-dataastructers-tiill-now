#ifndef PHONE
#define PHONE
//*************************
typedef struct moblieCall
{
    char phoneNumber[11];
    int periority;
    struct moblieCall *pNext;
    struct moblieCall *pPrev;
}MobileNode;
typedef struct mobileQueue
{
    MobileNode *head;
    int sizeP1;
    int sizeP2;
    int sizeP3;
}MobileCall;
//prototypes
//create
void createMobile(MobileCall *pm);
//******************************************************
//is empty
int isMobileEmpty(MobileCall *pm );
//******************************************************
//total size
int sizeMobile(MobileCall *pm);
//******************************************************
//is Emergency empty
int isEmergencyEmpty(MobileCall *pm );
//******************************************************
//size emergency call
int sizeEmergency(MobileCall *pm );
//******************************************************
//is Voice Call empty
int isVoiceCall(MobileCall *pm );
//******************************************************
//size VoiceCall call
int sizeVoiceCall(MobileCall *pm );
//******************************************************
//is Data Call empty
int isDataCallEmpty(MobileCall *pm );
//******************************************************
//size DataCall call
int sizeDataCall(MobileCall *pm );
//******************************************************
//serve a call
int serveCall(MobileCall *pm,char el[11]);
//******************************************************
void disMissLeastPriority(MobileCall *pm);
//******************************************************
//insert call
void insertCall(MobileCall *pm,int periority,char el[11]);
//******************************************************

#endif // PHONE
