#include <stdio.h>

#include "riffle.c"

int main(){
    int i;
    int greekLen = 7;
    int size = sizeof(int);
    int greek[] = {1,2,3,4,5,6,7};

    riffle(greek, greekLen, size, 4);


    int charLen = 12;
    size = sizeof(char);
    char list[] = {'a','b','c','d','e','f','g','h','i','j','k','l'};

    riffle(list, charLen, size, 4);
    
    for(i=0;i<greekLen;i++){
        printf(" %d ",greek[i]);
    }

    
    for(i=0;i<charLen;i++){
        printf(" %c ",list[i]);
    }
    
    return 0;
}