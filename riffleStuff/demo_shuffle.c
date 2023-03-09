#include <stdio.h>

#include "riffle.c"

int main(){
    int i;
    int greekLen = 12;
    //Need to make all strings uniform size
    int size = sizeof(char*);
    char * greek [] = {"atlas","bee","charlie","denver","echo","fry","ghana","hoist","iguana","jam","kite","lemon"};


    riffle(greek, greekLen, size, 10);

    for(i=0;i<greekLen;i++){
        printf(" %s ",greek[i]);
    }

    printf("\n");

    int charLen = 11;
    size = sizeof(char);
    char list[] = {'a','b','c','d','e','f','g','h','i','j','k'};

    riffle(list, charLen, size, 4);
    
    for(i=0;i<charLen;i++){
        printf(" %c ",list[i]);
    }
    return 0;
}