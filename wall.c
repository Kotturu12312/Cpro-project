#include<stdio.h>
#include "wall.h"

int placewall(struct game player[], int current, char buf[]){
    int row=buf[0]-'a';
    int col=buf[1]-'1';
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
                        return 1;
                        
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
                        return 1;
                    }
                }
            }
    return 0;
}