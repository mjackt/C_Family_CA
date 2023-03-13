#include <stdio.h>

#include "riffle.c"

int main(){
    int i;
    int greekLen = 12;
    //Need to make all strings uniform size
    int size = sizeof(char*);
    char * greek [] = {"atlas","bee","charlie","denver","echo","fry","ghana","hoist","iguana","jam","kite","lemon"};


    int result = check_shuffle(greek, greekLen, size, &cmp_str);

    for(i=0;i<greekLen;i++){
        printf(" %s ",greek[i]);
    }
    printf("\nResult: %d",result);

    printf("\n");

    int len = 7;
    size = sizeof(int);
    int intList[] = {1,2,3,4,5,6,7};

    result = check_shuffle(intList, len, size, &cmp_int);
    
    for(i=0;i<len;i++){
        printf(" %d ",intList[i]);
    }
    printf("\nResult: %d",result);
    return 0;
}