//phase 1 code
//om sri sadguru sai nadh maharaj ki jay;
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include "board.h"
int main(){
    struct game player[2];
    //intialize the position of players
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
    //ask the user
    char buf[16];
    int current=0;
    while(1){
        printboard();
        printf("player %d turn:\nwalls left %d:",current+1,player[current].wallsleft);
        if(fgets(buf,sizeof(buf),stdin)==NULL)break;
        //remove \n from the input;
        for (int i=0;buf[i]!='\0';i++){
            buf[i]=tolower(buf[i]);
            if (buf[i]=='\n')buf[i]='\0';
        }
        //if user give quit
    
        if(strcmp(buf,"quit")==0)break;
        //conver it into normal numbers
        int row=buf[0]-'a';
        int col=buf[1]-'1';
        // printf("%d",row);
        // printf("%d",col);
        // printf("you typed[%s]\n",buf);
        if (strlen(buf)==2){
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
                    break;
                    }
                    current=1-current;
                }
            }
       
        }
        else if(strlen(buf)==3){
            if(buf[0]<'a' || buf[0]>'h' || buf[1]<'1' || buf[1]>'8' || (buf[2]!='v' && buf[2]!='h'))printf("Invalid Input!\n");
            else if(player[current].wallsleft==0)printf("All walls are finished!!\n");
            else{
                if (buf[2]=='h'){
                    //checking for intersection
                    if (board[row*2+2][col*2+2]!=' ' || board[row*2+2][col*2+3]!=' ' || board[row*2+2][col*2+4]!=' ')printf("Wall Overlaps!\n");
                    else{
                        //placing horizontal wall
                        board[row*2+2][col*2+2]='-';
                        board[row*2+2][col*2+3]='-';
                        board[row*2+2][col*2+4]='-';
                        player[current].wallsleft--;
                        current=1-current;
                        
                    } 
                }
                else{
                    //checking for intersection
                    if (board[row*2+1][col*2+3]!=' ' || board[row*2+2][col*2+3]!=' ' || board[row*2+3][col*2+3]!=' ')printf("Wall Overlaps!\n");
                    else{
                        //placing vertical wall
                        board[row*2+1][col*2+3]='|';
                        board[row*2+2][col*2+3]='|';
                        board[row*2+3][col*2+3]='|';
                        player[current].wallsleft--;
                        current=1-current;
                    }
                }
            }
        }
        else{
            printf("Invalid!!\n");
        }
    }
    return 0;
}

