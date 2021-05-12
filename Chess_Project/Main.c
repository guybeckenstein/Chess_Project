#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALLOCATION_FAILURE -1
#include "ChessPos_Lists.h"
#include "TreeList.h"

#define debug_q1
#define debug_q2
//#define debug_q3
//#define debug_q4



int main()
{
    /*Q1*/
#ifdef debug_q1
    chessPosArray*** valid_moves = validKnightMoves();
    Print_valid_moves(valid_moves);
    Free_valid_moves(valid_moves);
#endif // debug_q1

    /*Q2*/
#ifdef debug_q2
    chessPosCell node9 = { { 'E','1' }, NULL };
    chessPosCell node8 = { {'E', '1'}, &node9 };
    chessPosCell node7 = { {'E', '1'}, &node8 };
    chessPosCell node6 = { {'E', '1'}, &node7 };
    chessPosCell node5 = { {'A', '4'}, &node6 };
    chessPosCell node4 = { {'H', '5'}, &node5 };
    chessPosCell node3 = { {'D', '8'}, &node4 };
    chessPosCell node2 = { {'H', '5'}, &node3 };
    chessPosCell node1 = { {'A', '4'}, &node2 };

    chessPosList newList = { &node1, &node9 };
    display(&newList);
    //freeList(&newList); problem
#endif // debug_q2

    /*Q3*/
#ifdef debug_q3
    chessPos y;
    findAllpossibleKnightPaths(&y);
#endif // debug_q3

    
    return 0;
}




