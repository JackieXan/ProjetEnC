//
// Created by cassie on 28/10/2023.
//

#ifndef PROJETENC_CELL_H
#define PROJETENC_CELL_H

#include<stdlib.h>
#include<stdio.h>

typedef struct Cell {
    int value;
    int level;
    struct Cell **arrayNexts; //tableau dynamique

} Cell;

Cell *createCell(int value, int level);

void deleteCell(Cell *cell);

void displayCell(Cell *cell);

void displayCellByLevel(Cell *cell, int level);

void displayEmptyCell();


#endif //PROJETENC_CELL_H
