//phase 1 code
//om sri sadguru sai nadh maharaj ki jay;
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "board.h"
#include "input.h"
#include "move.h"
#include "wall.h"
int main(){    
    struct game player[2];
    //intialize the position of players
    initplayers(player);
    //ask the user
    char buf[16];
    int current=0;
    while(1){
        printboard();
        printf("player %d turn:\nwalls left %d:",current+1,player[current].wallsleft);
        if (readinput(buf)==0)break;
        //if user give quit
        if(strcmp(buf,"quit")==0)break;        // printf("%d",row);
        // printf("%d",col);
        // printf("you typed[%s]\n",buf);
        if (strlen(buf)==2){
            int result=makemove(player,current,buf);
            if(result==2)break;
            if(result==1)current=1-current;
        }
        else if(strlen(buf)==3){
            if(placewall(player,current,buf)==1)current=1-current;
        }
        else{
            printf("Invalid!!\n");
        }
    }
    return 0;
}

