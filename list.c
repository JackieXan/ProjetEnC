//
// Created by cassie on 26/10/2023.
//

#include "list.h"
List* createEmptyList(int nbLevel){
    List* emptyList = (List*) malloc(sizeof(List));
    emptyList->nbLevel = nbLevel;
    emptyList->arrayHeads = (Cell**) malloc(sizeof(Cell*)*nbLevel);
    for (int i = 0; i < nbLevel; ++i) {
        emptyList->arrayHeads[i] = NULL;
    }
    return emptyList;
}


void addHeadToList(List* list,int value, int nbLevel){
    Cell* newCell = createCell(value, nbLevel);
    for (int i = 0; i < nbLevel; ++i) {
        newCell->arrayNext[i] = list->arrayHeads[i];
    }
    for (int i = 0; i < nbLevel; ++i) {
        list->arrayHeads[i] = newCell;

    }
}

void displayLevel(List* list, int nbLevel){
    if(nbLevel <= list->nbLevel-1){ // pour pas planter si ex list 10 etages si envoit liste 11 etages plante pas (merci val)
        printf("[list head_%d @-]", nbLevel);
        Cell* temp = list->arrayHeads[nbLevel];
        while(temp != NULL){
            printf("-->");
            displayCell(temp);
            temp = temp->arrayNext[nbLevel];
        }
        printf("NULL\n");
    }
}

void displayList(List* list){
    for (int i = 0; i < list->nbLevel; ++i) {
        displayLevel(list,i);

    }
}