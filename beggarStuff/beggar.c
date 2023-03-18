#include <stdio.h>
#include "queue.c"
#include "stack.c"

int beggar(int,int*,int);
int finished(Queue**,int);

//If -1 returned player is out
int* take_turn(Queue* player,Stack* pile){
    if (getQueueSize(player)==0){
        return NULL;
    }
    int newCard = peekQueue(player);
    dequeue(player);

    //For no reward an array with just 0 in it is returned as 0 can never be a card
    if (pile->size==0){
        printf("\tPlayer playing: %d\n",newCard);
        push(pile,newCard);
        int* reward = malloc(sizeof(int));
        reward[0]=0;
        return reward;
    }

    if (peekStack(pile)<11){
        printf("\tPlayer playing: %d\n",newCard);
        push(pile,newCard);
        int* reward = malloc(sizeof(int));
        reward[0]=0;
        return reward;
    }

    else{
        int penCount = peekStack(pile)-10;
        printf("Player now paying %d penatly cards\n",penCount);
        int i;
        for (i=0;i<penCount;i++){
            printf("\t Player playing: %d\n",newCard);
            push(pile,newCard);
            if(newCard>10){
                printf("--penalty escaped --\n");
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

    int game=1;
    while(game==1){
        int i;
        for(i=0;i<Nplayers;i++){
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
            printf("%d's Turn: ",nextPlayer);

            int* reward = take_turn(players[nextPlayer],pile);

            int j=0;
            //0 acts as null terminator. therefore while loops until a 0 is found while adding all of the cards to the hand
            while(reward[j]!=0){
                enqueue(players[i],reward[j]);
                j++;
            }
            printf("Pile");
            printStack(pile);
            printf("\n");

            printf("%d: ",0);
            printQueue(players[0]);
            printf("\n");

            printf("%d: ",1);
            printQueue(players[1]);
            printf("\n");

            printf("%d: ",2);
            printQueue(players[2]);
            printf("\n");

            //printf("%d: ",3);
            //printQueue(players[3]);
            //printf("\n");

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
    printf("won");
    return 888;
}

int main(){
    int deck[52];
    int i;
    int card = 2;
    for(i=0;i<52;i++){
        deck[i]=card;
        if(card==14){
            card=2;
        }
        else{
            card++;
        }
    }
    printf("\n%d",beggar(3,deck,0));
    return 0;
}