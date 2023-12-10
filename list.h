//
// Created by cassie on 26/10/2023.
//


#ifndef PROJETENC_LIST_H
#define PROJETENC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

typedef struct List {
    int nbLevels;
    Cell **arrayHeads;
} List;

//on a pas stocké le max de level -> a calculer
List *createEmptyList(int nbLevel);

void addHeadToList(List *list, int value, int nbLevel);

void displayLevel(List *list, int nbLevel);

void displayList(List *list);

void displayPrettyList(List *list);

void displayPrettyLevel(List *list, int nbLevel);

void addValueInList(List *list, Cell *cell, int level);

Cell *searchForOneLevel(List *list, int value);

Cell *searchValue(List *list, int value);

#endif //PROJETENC_LIST_H
