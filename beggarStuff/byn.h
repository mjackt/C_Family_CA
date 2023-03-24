#include "beggar.c"

/**
 * Struct just contains 3 ints
 * The shortest, longest and average length of n games
 */
typedef struct gameStatStruct{
    int shortest;
    int longest;
    int average;
}STATS;

STATS statistics(int,int);