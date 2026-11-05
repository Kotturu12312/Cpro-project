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