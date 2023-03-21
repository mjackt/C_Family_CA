#include <stdio.h>
#include "queue.c"
#include "stack.c"
#include "../riffleStuff/riffle.c"

int beggar(int,int*,int);
int finished(Queue**,int);
void talk(Queue**,Stack*,int,int,int,int);
int* take_turn(Queue*, Stack*);