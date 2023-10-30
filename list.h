//
// Created by cassie on 26/10/2023.
//


#ifndef PROJETENC_LIST_H
#define PROJETENC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

typedef struct List{
    int nbLevel;
    Cell** arrayHeads;
}List;

List* createEmptyList(int nbLevel);
void addHeadToList(List* list,int value, int nbLevel);
void displayLevel(List* list, int nbLevel);


#endif //PROJETENC_LIST_H
