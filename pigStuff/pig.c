#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* pig(char*);
int isVowel(char);
int isY(char);
char** sentenceToWords(char*);

//returns boolen value for if character is a Y
//used when in times when Y is classed as a vowel
int isY(char c){
    int Y = (c=='y' || c=='Y');
    return Y;
}

int isVowel(char c){
    //true if variable c is a lowercase vowel
    int lowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    //true if variable c is a uppercase vowel
    int uppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercaseVowel || uppercaseVowel == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/*
//returns array of words extracted from sentence
char** sentenceToWords(char* sentence){
    //mallocs enough space for all initial characters in sentence
    char** words = malloc(sizeof(char)*(strlen(sentence)));
    //take first word
    char* word = strtok(sentence, " ");
    int count = 0;

    while(word != NULL){
        words[count] = word;
        word = strtok(NULL, " ");
    }
    return words;
}
*/

char* pig(char* word){
    //Starting in vowel
    if (isVowel(*word)==1){
        //mallocs space for the word + 4 characters
        //4 characters needed for 'way' plus a null terminator
        char* pigged = malloc(sizeof(char) * (strlen(word)+4));

        int i;
        int j;
        char* toAdd = "way";

        //adding normal word to start of pigged
        for (i=0;i<strlen(word);i++){
            pigged[i]=word[i];
        }

        //starts at index of pigged where i finished by using i+j
        //adds 'way' to end of word
        for(j=0;j<3;j++){
            pigged[i+j]=toAdd[j];
        }

        //adding null terminator to end
        pigged[i+j] = '\0';

        return pigged;
    }

    //Starting with consonant
    else{
        //mallocs space for the word + 3 characters
        //3 characters needed for 'ay' plus a null terminator
        char* pigged = malloc(sizeof(char) * (strlen(word)+3));

        //starts at one cause we only get here if 1st char isn't a vowel
        int leadConsCount = 1;
        //loops counting the leading consonants until a vowel or \0 is found
        while(isVowel(word[leadConsCount])==0 && word[leadConsCount] != '\0' && isY(word[leadConsCount])==0){
            leadConsCount ++;
        }

        int i;
        int j;
        int k;

        //loop fills pigged starting after leading consonants in initial word
        for(i=0;i<(strlen(word)-leadConsCount);i++){
            pigged[i]=word[i+leadConsCount];
        }

        //loop now adds leading consonants onto the end
        for(j=0;j<leadConsCount;j++){
            pigged[i+j]=word[j];
        }
        //at this point if the word was 'bread'.  Then pigged is looking like 'eadbr'

        char* toAdd = "ay";
        for(k=0;k<2;k++){
            pigged[i+j+k]=toAdd[k];
        }
        pigged[i+j+k]='\0';

        return pigged;
    }
}
