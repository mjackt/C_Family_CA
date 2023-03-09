#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void riffle_once(void*, int, int, void*);
void riffle(void*, int, int, int);


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