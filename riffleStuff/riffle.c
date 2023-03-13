#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void riffle_once(void*, int, int, void*);
void riffle(void*, int, int, int);
int cmp_int(void*, void*);
int cmp_str(void*, void*);
int check_shuffle(void*, int, int, int (*cmp)(void*, void*));

/**
 * Function calls a riffle shuffle. Then checks whether the items after the shuffle match the items at the start of the shuffle.
 * @param L -- Pointer to array to shuffle
 * @param len -- Length of L
 * @param size -- Size of type stored by L in bytes
 * @param cmp -- Compare function that returns 0 if equal. Anything else if not.
 * @return 0 if shuffle is invalid. 1 if shuffle is valid.
 */
int check_shuffle(void *L, int len,int size, int (*cmp)(void *, void *)){
    //Array storing state of L before shuffling. Used later to compare
    void* preCopy = malloc(size*len);
    memmove(preCopy,L,size*len);

    riffle(L,len,size,1);

    void* preCopyIncrement = preCopy;

    //When uncommented should produce 0 return
    //void* not = malloc(size*len);
    //memmove(preCopy,not,size*len);

    void* LIncrement = L;
    int i;
    int j;
    int found = 1;
    //Takes an item in preCopy and looks for it in L. Does this for every item in preCopy.
    //If an item cannot be found it means the shuffle is invalid so 0 is returned.
    for(i=0;i<len;i++){
        found = 1;
        LIncrement = L;
        for (j=0;j<len;j++){
            if (cmp(preCopyIncrement,LIncrement) == 0){
                found = 0;
                j=len;
            }
            LIncrement = LIncrement + size;
        }
        if (found==1){
            free(preCopy);
            return 0;
        }
        preCopyIncrement = preCopyIncrement + size;
    }

    free(preCopy);
    return 1;
}

/**
 * Function compares two integers
 * @param first -- An integer
 * @param second -- An integer
 * @return 0 if equal. 1 if first>second. -1 if first<second
 */
int cmp_int(void* first, void* second){
    int a = *(int*)first;
    int b = *(int*)second;
    if(a<b){
        return -1;
    }
    if(a>b){
        return 1;
    }
    if (a==b){
        return 0;
    }
}

/**
 * Function compares two strings
 * @param first -- A string
 * @param second -- A string
 * @return 0 if equal. 1 if first>second. -1 if first<second
 */
int cmp_str(void* first, void* second){
    char* str1 =  (char *)first;
    char* str2 =  (char *)second;
    int result = strcmp(str1,str2);

    return result;
}

void riffle(void *L, int len, int size, int N){
    int i;
    void* work = malloc(size * len);

    for(i=0;i<N;i++){
        riffle_once(L,len,size,work);
    }
    free(work);
}

void riffle_once(void *L, int len, int size, void *work){
    //Increment void pointer with size of thing
    //L will always remain pointer to start of main list
    //work will always remain pointer to start of workspace

    //A and B represent pointers to the front of each half of the split list. (i.e top of each half of the pack)
    //B is second half
    //half ensures that an integer value is used to index halfway
    int intHalf = (len/2);
    float floatHalf = ((float)len/2.0);
    void* A = L;
    void* B = L + (size*intHalf);

    //AAdds and BAdds keep track of progress through the pack. As soon as either is more than or equal to (len/2) it means the corresponding half has been cleared.
    int AAdds = 0;
    int BAdds = 0;
    if (len % 2==1){
       AAdds=1;
    }

    //workIterate tracks next space to add to in workspace
    void* workIterate = work;
    
    int i;
    int loop=0;

    //While loop continues randomly adding from each pile until one pile is empty
    srand(time(NULL));
    while(AAdds < floatHalf && BAdds < floatHalf){
        int choice = rand() % 2;
        if (choice==0){
            memmove(workIterate,A,size);
            workIterate = workIterate + size;
            A = A + size;
            AAdds++;
        }
        else{
            memmove(workIterate,B,size);
            workIterate = workIterate + size;
            B = B + size;
            BAdds++;
        }
    }

    //Next two while loops will fill up remaining space in shuffle list with whichever half of the pack is still remaining
    while(AAdds < floatHalf){
        memmove(workIterate,A,size);
        workIterate = workIterate + size;
        A = A + size;
        AAdds++;
    }

    while(BAdds < floatHalf){
    memmove(workIterate,B,size);
    workIterate = workIterate + size;
    B = B + size;
    BAdds++;
    }

    //Copy workspace list into main list
    memmove(L,work,(size*len));

}