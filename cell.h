//
// Created by cassie on 28/10/2023.
//

#ifndef PROJETENC_CELL_H
#define PROJETENC_CELL_H
#include<stdlib.h>
#include<stdio.h>

typedef struct Cell{
    int value;
    int nbLevel;
    struct Cell** arrayNext; //tableau dynamique

}Cell;

Cell* createCell(int value, int nbLevel);
void deleteCell(Cell* cell);
void displayCell(Cell* cell);

#endif //PROJETENC_CELL_H
