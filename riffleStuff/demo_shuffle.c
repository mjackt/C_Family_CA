#include <stdio.h>
#include "riffle.c"

int main(){
    int i;
    
    //Printing int section
    int len = 20;
    int size = sizeof(int);
    int intList[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

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

    result = check_shuffle(greek, greekLen, size, &cmp_str);

    for(i=0;i<greekLen;i++){
        printf(" %s ",greek[i]);
    }
    printf("\nResult: %d",result);

    return 0;
}