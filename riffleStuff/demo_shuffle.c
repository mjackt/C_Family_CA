#include <stdio.h>
#include "demo_shuffle.h"

/**
 * Main will print the result of shuffling the two preset arrays
 */
int main(){
    int i;
    
    //Printing int section
    int len = 20;
    int size = sizeof(int);
    int intList[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    printf("\nBefore: ");

    for(i=0;i<len;i++){
        printf(" %d ",intList[i]);
    }

    printf("\nAfter : ");

    int result = check_shuffle(intList, len, size, &cmp_int);
    
    for(i=0;i<len;i++){
        printf(" %d ",intList[i]);
    }
    printf("\nResult: %d",result);

    printf("\n\n");

    //Printing greek section
    int greekLen = 12;
    size = sizeof(char*);
    char * greek [] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta","iota","kappa","lambda","mu"};

    printf("\nBefore: ");

    for(i=0;i<greekLen;i++){
        printf(" %s ",greek[i]);
    }

    printf("\nAfter : ");

    result = check_shuffle(greek, greekLen, size, &cmp_str);

    for(i=0;i<greekLen;i++){
        printf(" %s ",greek[i]);
    }
    printf("\nResult: %d\n",result);

    return 0;
}