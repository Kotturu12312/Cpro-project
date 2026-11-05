#include<stdio.h>
#include<stdlib.h>
#include "move.h"
int makemove(struct game player[], int current, char buf[]){
    int row=buf[0]-'a';
    int col=buf[1]-'1';
    //checking for the valid input or not
    if(buf[0]<'a' || buf[0]>'i')printf("Invalid Input!\n");
    else if(buf[1]<'1' || buf[1]>'9')printf("Invalid Input!\n");
    else{
        //checking for the valid position or not
        int rowdiff=abs(row-player[current].row);
        int coldiff=abs(col-player[current].col);
        if (rowdiff+coldiff!=1)printf("Invalid Input!\n");
        else if(board[row*2+1][col*2+2]!='.')printf("Already Occupied!\n");
        else if(board[player[current].row+row+1][player[current].col+col+2]!=' ')printf("Wall Present!!\n");
        else{
            //move the paw to user given position
            board[player[current].row*2+1][player[current].col*2+2]='.';
            player[current].row=row;
            player[current].col=col;                    
            board[player[current].row*2+1][player[current].col*2+2]=player[current].symbol;
            //switch the player
            if (row==player[current].goalrow){
                printboard();
                printf("HURRAY!,Player %d WIN!!\n",current+1);
                return 2;
                }
                return 1;
            }
        }
    return 0;
}