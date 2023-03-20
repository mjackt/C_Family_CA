#include <stdio.h>
#include "queue.c"
#include "stack.c"
#include "../riffleStuff/riffle.c"

int beggar(int,int*,int);
int finished(Queue**,int);
void talk(Queue**,Stack*,int,int,int,int);
int* take_turn(Queue*, Stack*);

void talk(Queue** players,Stack* pile, int Nplayers, int turn, int nextPlayer, int rewardee){
    printf("Turn %d:\n",turn);
    printf("Pile");
    printStack(pile);
    printf("  <-- Top\n");

    int k;
    for(k=0;k<Nplayers;k++){
        if(k==nextPlayer){
            printf("*   %d: ",k);
        }
        else{
            printf("    %d: ",k);
        }
        printQueue(players[k]);
        printf("\n");
    }
    
    if(peekStack(pile)<11){
        printf("\t Player %d playing: %d\n",nextPlayer,peekQueue(players[nextPlayer]));
        if(getQueueSize(players[nextPlayer])==1){
            printf("##### Player %d out of cards #####\n",nextPlayer);
        }
    }
    else{
        int escape = 0;
        int penCount = peekStack(pile)-10;
        printf("\t%d penatly cards:\n",penCount);
        int i;
        int newCard = peekQueue(players[nextPlayer]);
        for (i=0;i<penCount;i++){
            printf("\tPlayer %d playing: %d\n",nextPlayer,newCard);
            
            //If they are out of cards then break
            if(i == players[nextPlayer]->size - 1){
                printf("##### Player %d out of cards #####\n",nextPlayer);
                break;
            }
            if(newCard>10){
                printf("\t--penalty escaped --\n");
                escape = 1;
                break;
            }

            newCard = qGetNth(players[nextPlayer],i+1);
        }
    if(escape==0){
        printf("Pile going to player %d\n",rewardee);
    }
    }
    printf("\n");
}
//If -1 returned player is out
int* take_turn(Queue* player,Stack* pile){
    if (getQueueSize(player)==0){
        return NULL;
    }
    int newCard = peekQueue(player);
    dequeue(player);

    //For no reward an array with just 0 in it is returned as 0 can never be a card
    if (pile->size==0){
        //printf("\tPlayer playing: %d\n",newCard);
        push(pile,newCard);
        int* reward = malloc(sizeof(int));
        reward[0]=0;
        return reward;
    }

    if (peekStack(pile)<11){
        //printf("\tPlayer playing: %d\n",newCard);
        push(pile,newCard);
        int* reward = malloc(sizeof(int));
        reward[0]=0;
        return reward;
    }

    else{
        int penCount = peekStack(pile)-10;
        //printf("Player now paying %d penatly cards\n",penCount);
        int i;
        for (i=0;i<penCount;i++){
            //printf("\t Player playing: %d\n",newCard);
            push(pile,newCard);
            if(newCard>10){
                //printf("--penalty escaped --\n");
                int* reward = malloc(sizeof(int));
                reward[0]=0;
                return reward;
            }
            //If a player runs out of cards paying a penalty then they've paid all they can and are out
            if(getQueueSize(player)==0){
                break;
            }
            if(i==penCount-1){
                break;
            }
            //Only needed if theres another pencard to pay
            newCard = peekQueue(player);
            dequeue(player);

        }
        //this point means all pens have been paid and time to give reward to previous player
        int pileSize = getStackSize(pile);
        int* reward = malloc(sizeof(int)*pileSize+1);
        //0 acts like a null terminator to signify end of reward
        reward[pileSize]=0;
        for (i=pileSize-1;i>-1;i--){
            reward[i]=pop(pile);
        }
        return reward;
    }
}

int finished(Queue** players,int Nplayers){
    int i;
    int nonEmpty = 0;
    for(i=0;i<Nplayers;i++){
        int handSize = getQueueSize(players[i]);
        if (handSize != 0){
            nonEmpty = nonEmpty+1;
            if (nonEmpty>1){
                return 0;
            }
        }
    }
    return 1;
}

int beggar(int Nplayers, int *deck, int talkative){
    srand(time(NULL));
    riffle(deck,52,sizeof(int),7);
    Queue* players[Nplayers];
    int i;

    int cardAdd;
    //Will loop thorugh each player and:
        //Create queue for hand
        //Fill hand from deck by:
            //Will give every nth card to player
            //i.e if there are 5 players then player 1 needs card 2,7,12 etc..
            //this is done with cardAdd
    for (i=0;i<Nplayers;i++){
        players[i] = createQueue(52);
        cardAdd = i;
        while(cardAdd<52){
            enqueue(players[i],deck[51-cardAdd]);//Adding from end of deck first so top of deck ends up being top of hands like a real-life deal
            cardAdd = cardAdd+Nplayers;
        }
    }

    Stack* pile = createStack(52);

    int turn = 0;
    int game=1;
    while(game==1){
        int i;
        for(i=0;i<Nplayers;i++){
            turn++;
            int nextPlayer = i+1;

            if(nextPlayer==Nplayers){
                nextPlayer=0;
            }

            //looping to find next player still with cards
            while(players[nextPlayer]->size==0){
                nextPlayer++;
                if(nextPlayer==Nplayers){
                    nextPlayer=0;
                }
            }

            if (talkative!=0){
                talk(players,pile,Nplayers,turn,nextPlayer,i);
            }

            int* reward = take_turn(players[nextPlayer],pile);

            int j=0;
            //0 acts as null terminator. therefore while loops until a 0 is found while adding all of the cards to the hand
            while(reward[j]!=0){
                enqueue(players[i],reward[j]);
                j++;
            }

            free(reward);

            if(finished(players,Nplayers)==1){
                game = 0;
                break;
            }
            //i needs to be assinged because at this point we know what the next person with cards is
            //this could defo be done without a for loop but i started like that and taking it out breaks everything :] and i cant figure it out.
            i=nextPlayer-1;
        }
    }
    if(talkative!=0){
        printf("\nGame over\n");
        printf("Final game state:\n");
        printf("Turn %d:\n",turn);
        printf("Pile");
        printStack(pile);
        printf("  <-- Top\n");

        int k;
        for(k=0;k<Nplayers;k++){
            printf("    %d: ",k);
            printQueue(players[k]);
            printf("\n");
        }
    }
    return turn;
}
