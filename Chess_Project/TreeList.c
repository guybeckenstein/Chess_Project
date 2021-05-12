#define _CRT_SECURE_NO_WARNINGS
#include "TreeList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct treeNode
{
    chessPos position;
    treeNodeListCell* next_possible_positions;
}treeNode;
typedef struct treeNodeListCell
{
    treeNode* node;
    struct _treeNodeListCell* next;
}treeNodeListCell;
PathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
    PathTree t;

    chessPosList lst; /*a list of all the positions that have been played*/
    makeEmptyPosList(&lst);
    t.root = startingPosition[0]; // maybe that is wrong
    t.root = Rec(startingPosition, lst);

    return t;
}
treeNode* Rec(chessPos* currentPosition, chessPosList lst)
{
    chessPosCell* node = createNewListNode(*currentPosition, NULL);
    insertPosCellToEndList(&lst, node);

    chessPosArray*** res = validKnightMoves();
    char firstLetter = *(currentPosition[0]), secondLetter = *(currentPosition[1]);
    int newSize = deleteRepeatableCells(res[firstLetter - 'A'][secondLetter - '0']->positions, res[firstLetter - 'A'][secondLetter - '0']->size, lst);
    res[firstLetter - 'A'][secondLetter - '0']->positions, res[firstLetter - 'A'][secondLetter - '0']->size = newSize; // maybe this line is dummy

    if (newSize == 0)
    {
        return NULL;
    }
    else
    {
        chessPos* newPosition = res[firstLetter - 'A'][secondLetter - '0']->positions;
        int i;
        for (i = 0; i < newSize; i++) /*Recursion call*/
        {
            Rec(res[firstLetter - 'A'][secondLetter - '0']->positions[i], lst);
        }
    }
}
int deleteRepeatableCells(chessPos* positions, int positionsSize, chessPosList lst)
{
    if (isEmptyList(&lst))
    {
        return positionsSize;
    }
    else
    {
        int equivalentPositions = 0;
        chessPosCell* myNode = lst.head;
        while (myNode != NULL)
        {
            int i;
            for (i = 0; i < positionsSize; i++)
            {
                if (positions[i][0] == myNode->position[0] && positions[i][1] == myNode->position[1])
                {
                    Swap(&positions[i], &positions[i - equivalentPositions - 1]);
                    equivalentPositions++;
                }
            }
            myNode = myNode->next;
        }

        return positionsSize - equivalentPositions;
    }
}

void Swap(chessPos** first, chessPos** second)
{
    chessPos* tmp = *first;
    *first = *second;
    *second = tmp;
}