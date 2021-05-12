#pragma once
#include "ChessPos_Lists.h"
#define ALLOCATION_FAILURE -1
typedef struct treeNode treeNode;
typedef struct treeNodeListCell treeNodeListCell;
typedef struct _pathTree
{
    treeNode* root;
}PathTree;
PathTree findAllPossibleKnightPaths(chessPos* startingPosition);
treeNode* Rec(chessPos* currentPosition, chessPosList lst);
int deleteRepeatableCells(chessPos* positions, int positionsSize, chessPosList lst); /*Returns the new size of the positions dynamic array*/
void Swap(chessPos*** first, chessPos*** second);