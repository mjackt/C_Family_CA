#include "quality.h"

/**
 * main will produce the avergae quality of up to 15 shuffles and write the output to terminal
 */
int main(){

    int i;
    for(i=1;i<=15;i++){
        float avgQual = average_quality(50, i, 30);
        printf("\n%d Shuffles -- Average Quality: %.6f",i,avgQual);
    }
}