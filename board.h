#ifndef BOARD_H
#define BOARD_H

struct game{
    int row,col,wallsleft,goalrow;
    char symbol;
};

extern char board[18][21];
void printboard(void);

#endif