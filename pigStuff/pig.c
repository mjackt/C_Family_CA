#include "pig.h"

/**
 * Function checks if a char is the letter y
 * @param c -- char to test
 * @return 0 if c is 'y'. 1 if not
 */
int isY(char c){
    int Y = (c=='y' || c=='Y');
    return Y;
}

/**
 * Function checks if a letter is a vowel
 * @param c -- char to test
 * @return 0 if c is a vowel. 1 if not
 */
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

/**
 * Function that pigs a singular word
 * @param word -- a string to pig
 * @return The pigged string
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
