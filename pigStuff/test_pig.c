#include "test_pig.h"

/**
 * Main will translate and output the preset words
 */
int main(){
    //array of all examples to translate
    char toPig[7][8]={"happy","duck","glove","evil","eight","yowler","crystal"};
    int i;
    //just loops through examples printing transalation as required
    for(i=0;i<7;i++){
        char* pigged = pig(toPig[i]);
        printf("%s => %s\n",toPig[i],pigged);
        free(pigged);
    }
    return 0;
}