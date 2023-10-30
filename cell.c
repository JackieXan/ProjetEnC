//
// Created by cassie on 28/10/2023.
//

#include "cell.h"
Cell* createCell(int value, int nbLevel){
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->value = value;
    newCell->nbLevel = nbLevel;
    newCell->arrayNext = (Cell**) malloc(sizeof(Cell*)*nbLevel);
    for (int i = 0; i < nbLevel; ++i) {
        newCell->arrayNext[i] = NULL;
    }
    return newCell
}