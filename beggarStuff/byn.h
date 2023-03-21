#include "beggar.c"

typedef struct gameStatStruct{
    int shortest;
    int longest;
    int average;
}STATS;

STATS statistics(int,int);