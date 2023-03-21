#include "single.h"

int main( int argc, char *argv[] )  {

    if( argc == 2 ) {
        //Create deck
        int deck[52];
        int i;
        int card = 2;
        for(i=0;i<52;i++){
            deck[i]=card;
            if(card==14){
                card=2;
            }
            else{
                card++;
            }
        }
        beggar(atoi(argv[1]),deck,1);
    }
    else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
    }
    else {
      printf("One argument expected.\n");
    }
    return 0;
}