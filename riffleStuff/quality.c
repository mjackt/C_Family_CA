#include "riffle.c"

/**
 * main will produce the avergae quality of up to 15 shuffles and write the output to terminal and quality.txt
 */
int main(){
    FILE *f = fopen("quality.txt", "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    int i;
    for(i=1;i<=15;i++){
        float avgQual = average_quality(50, i, 30);
        //terminal
        printf("\n%d Shuffles -- Average Quality: %.6f",i,avgQual);
        //file
        fprintf(f,"\n%d Shuffles -- Average Quality: %.6f",i,avgQual);
    }
    fprintf(f,"\n\nBased on these results I would say that 6 shuffles is probably the best number as this is the point where the shuffle quality normally reaches 0.5.\nIf you want to be extra sure the list is shuffled then you could go to 7 or even 8 shuffles but I believe 6 is sufficient.");
    fclose(f);
}