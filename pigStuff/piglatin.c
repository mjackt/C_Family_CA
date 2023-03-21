#include "piglatin.h"

/**
 * Main will continuously ask for an input and output the corresponding piglatin translation until a blank line is entered
 */
int main(void)
{
    //char sentence[200];
    char buffer[200];
    int loop=0;

    while (loop==0){
        printf("\nEnter sentence: ");
        fgets(buffer, sizeof(buffer), stdin);

        //Checks if buffer's first symbol is a \n. If it is then a blank line has been entered
        //Therefore time to end the program
        if (strcmp(buffer,"\n")==0){
            printf("termiated");
            loop=1;
            return 0;
        }

        int i;
        //Converts buffer string to lowercase
        for(i = 0; buffer[i]; i++){
            buffer[i] = tolower(buffer[i]);
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
            free(pigged);
            word = strtok(NULL, " ");
        }
    }
    return 0;
}