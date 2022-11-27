#include <stdio.h>
#include <stdlib.h>
#include "Telephone_Service.h"
int main()
{
    int Choose;
    MobileCall l;
    createMobile(&l);
    printf("Menu:-\n");
    printf("1. Data Call coming.\n2. Voice Call coming.\n3. Emergency Call coming.\n4. Serve a call.\n5. Dismiss calls with least priority.\n6. Exit.\n");
    do{
        printf("choose = ");
        scanf("%d",&Choose);
        if( Choose == 1 )
        {
            char number[11];
            printf("number = ");
            scanf("%s",number);
            insertCall(&l,1,number);
        }
        else if( Choose == 2 )
        {
            char number[11];
            printf("number = ");
            scanf("%s",number);
            insertCall(&l,2,number);
        }
        else if( Choose == 3 )
        {
            char number[11];
            printf("number = ");
            scanf("%s",number);
            insertCall(&l,3,number);
        }
        else if( Choose == 4 )
        {
            char number[11];
            int flag = serveCall(&l,number);
            if(flag)
                printf("number is : %s\n",number);
            else
                printf("no calls in queue\n");
        }
        else if( Choose == 5 )
        {
            disMissLeastPriority(&l);
        }
        else if( Choose == 6 )
        {
            printf("thank's for using my progrem\nbye :)");
        }
        else
        {
            printf("wrong Choose please Choose a valid number :)\n");
            printf("Menu:-\n");
            printf("1. Data Call coming.\n2. Voice Call coming.\n3. Emergency Call coming.\n4. Serve a call.\n5. Dismiss calls with least priority.\n6. Exit.\n");
        }
    }while(Choose != 6);
    return 0;
}
