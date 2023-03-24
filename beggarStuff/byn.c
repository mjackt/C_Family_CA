#include "byn.h"

/**
 * Function returns statistics for a number of games from 2..N players
 * @param Nplayers -- Max number of players in a game. (i.e it will do 2..Nplayers)
 * @param games -- Number of games to trial each number of players
 * @return A STATS struct containing the shortest,longest and average game length
 */
STATS statistics(int Nplayers,int games){
    //Creating deck
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

    //Inialising struct
    STATS gameStats;
    gameStats.longest=0;
    gameStats.shortest=2147483647;//largest c int just to be sure :)

    int sum = 0;
    srand(time(NULL));

    for(i=0;i<games;i++){
        riffle(deck,52,sizeof(int),7);
        int turns = beggar(Nplayers,deck,0);
        sum = sum + turns;

        if(turns>gameStats.longest){
            gameStats.longest=turns;
        }
        else if(turns<gameStats.shortest){
            gameStats.shortest=turns;
        }
    }
    gameStats.average = sum/games;
    return gameStats;
}

/**
 * Main takes two command line arguments. The number of players, and the number of game trials.
 * Then it will run the trials and output the results to the terminal
 */
int main( int argc, char *argv[] )  {

    if( argc == 3 ) {
        int maxPlayers = atoi(argv[1]);
        int numTrials = atoi(argv[2]);

        int i;
        for(i=2;i<=maxPlayers;i++){
            STATS stats = statistics(i,numTrials);
            printf("### %d players ###\n",i);
            printf("Shortest -- %d turns\n",stats.shortest);
            printf("Longest  -- %d turns\n",stats.longest);
            printf("Average  -- %d turns\n\n\n",stats.average);
        }
    }
    else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
    }
    else {
      printf("Two arguments expected.\n");
    }
    return 0;
}