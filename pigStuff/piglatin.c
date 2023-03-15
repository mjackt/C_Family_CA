//IS THIS FILE MEANT TO HAVE A CAPITAL L. I CANT TELL. ASKKKKKKK

#include "pig.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>    

int main(void)
{
    //char sentence[200];
    char buffer[200];
    int loop=0;

    while (loop==0){
        printf("\nEnter sentence: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer,"\n")==0){
            printf("termiated");
            loop=1;
            return 0;
        }

        int len = strlen(buffer);
        if( buffer[len-1] == '\n' ){
        buffer[len-1] = '\0';
        }

        //take first word
        char* word = strtok(buffer, " ");

        while(word != NULL){
            char* pigged = pig(word);
            printf("%s ",pigged);
            word = strtok(NULL, " ");
        }
    }
    return 0;
}