#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void riffle_once(void*, int, int, void*);
void riffle(void*, int, int, int);
int cmp_int(void*, void*);
int cmp_str(void*, void*);
int check_shuffle(void*, int, int, int (*cmp)(void*, void*));
float quality(int*, int);
float average_quality(int, int, int);