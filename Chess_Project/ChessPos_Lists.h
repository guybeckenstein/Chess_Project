#pragma once
#include <stdbool.h>
typedef char chessPos[2];
typedef struct _chessPosCell
{
    chessPos position;
    struct _chessPosCell* next;
} chessPosCell;
typedef struct _chessPosArray
{
    unsigned int size;
    chessPos* positions;
}chessPosArray;
typedef struct __chessPosList
{
    chessPosCell* head;
    chessPosCell* tail;
}chessPosList;
bool isEmptyList(chessPosList* lst);
void freeList(chessPosList* lst);
chessPosArray*** validKnightMoves();
void printList(chessPosList* lst);
void check_allocation(void* res);
void display(chessPosList* lst);
void makeEmptyPosList(chessPosList* lst);
int isPosAppear(chessPosList* lst, char posFirstChar, char posSecondChar);
chessPosCell* createNewListNode(chessPos position, chessPosCell* nextNode);
void insertPosCellToEndList(chessPosList* lst, chessPosCell* node);
void Print_valid_moves(chessPosArray*** valid_moves);
void Free_valid_moves(chessPosArray*** valid_moves);
void insertDataToEndList(chessPosList* res, int num);