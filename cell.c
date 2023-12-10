//
// Created by cassie on 28/10/2023.
//

#include "cell.h"

void displayEmptyCell();

Cell *createCell(int value, int level) {
    Cell *newCell = (Cell *) malloc(sizeof(Cell));
    newCell->value = value;
    newCell->level = level;
    newCell->arrayNexts = (Cell **) malloc(sizeof(Cell *) * level);
    for (int i = 0; i < level; ++i) {
        newCell->arrayNexts[i] = NULL;
    }
    return newCell;
}

void deleteCell(Cell *cell) {
    free(cell->arrayNexts);
    free(cell);
}

void displayCell(Cell *cell) {
    printf("[ %4d|@ ]", cell->value);
}

void displayCellByLevel(Cell *cell, int level) {
    if (level < cell->level) {
        displayCell(cell);
    } else {
        displayEmptyCell();
    }
}

void displayEmptyCell() {
    printf("----------");
}
