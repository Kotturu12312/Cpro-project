#include<stdio.h>
#include "board.h"
char board[18][21]={{"  1 2 3 4 5 6 7 8 9\n"},
                    {"a . . . . . . . . .\n"},{"                   \n"},
                    {"b . . . . . . . . .\n"},{"                   \n"},
                    {"c . . . . . . . . .\n"},{"                   \n"},
                    {"d . . . . . . . . .\n"},{"                   \n"},
                    {"e . . . . . . . . .\n"},{"                   \n"},
                    {"f . . . . . . . . .\n"},{"                   \n"},
                    {"g . . . . . . . . .\n"},{"                   \n"},
                    {"h . . . . . . . . .\n"},{"                   \n"},
                    {"i . . . . . . . . .\n"}};
void printboard(void){
    for (int i=0;i<18;i++){
        printf("%s",board[i]);
        // printf("\n");
    }
    return ;
}
void initplayers(struct game player[]){
    player[0].row=0;
    player[0].col=4;
    player[0].wallsleft=10;
    player[0].goalrow=8;
    player[0].symbol='1';
    player[1].row=8;
    player[1].col=4;
    player[1].wallsleft=10;
    player[1].goalrow=0;
    player[1].symbol='2';
    board[player[0].row*2+1][player[0].col*2+2]=player[0].symbol;
    board[player[1].row*2+1][player[1].col*2+2]=player[1].symbol;
}
