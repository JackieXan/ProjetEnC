//
// Created by cassie on 26/10/2023.
//

#include "list.h"

List *createEmptyList(int nbLevel) {
    List *emptyList = (List *) malloc(sizeof(List));
    emptyList->nbLevels = nbLevel;
    emptyList->arrayHeads = (Cell **) malloc(sizeof(Cell *) * nbLevel);
    for (int i = 0; i < nbLevel; ++i) {
        emptyList->arrayHeads[i] = NULL;
    }
    return emptyList;
}


void addHeadToList(List *list, int value, int nbLevel) {
    Cell *newCell = createCell(value, nbLevel);
    for (int i = 0; i < nbLevel; ++i) {
        newCell->arrayNexts[i] = list->arrayHeads[i];
    }
    for (int i = 0; i < nbLevel; ++i) {
        list->arrayHeads[i] = newCell;
    }
}

void displayLevel(List *list, int nbLevel) {
    if (nbLevel <= list->nbLevels - 1) { // pour pas planter si ex list 10 etages si envoie liste 11 etages plante pas
        printf("[list head_%d @-]", nbLevel);
        Cell *temp = list->arrayHeads[nbLevel];
        while (temp != NULL) {
            printf("-->");
            displayCell(temp);
            temp = temp->arrayNexts[nbLevel];
        }
        printf("-->NULL\n");
    }
}

void displayPrettyLevel(List *list, int nbLevel) {
    printf("[list head_%d @-]", nbLevel);
    Cell *temp = list->arrayHeads[0];//boucle sur toutes les cellules avant de checker si on laffiche ou non
    while (temp != NULL) {
        printf("-->");
        displayCellByLevel(temp, nbLevel);
        temp = temp->arrayNexts[0];
    }
    printf("-->NULL\n");
}

void displayList(List *list) {
    for (int i = 0; i < list->nbLevels; ++i) {
        displayLevel(list, i);
    }
    printf("\n");
}


void displayPrettyList(List *list) {
    for (int i = 0; i < list->nbLevels; ++i) {
        displayPrettyLevel(list, i);
    }
    printf("\n");
}

void addValueInList(List *list, Cell *cell, int level) {
    Cell *temp = list->arrayHeads[level];
    Cell *prev = NULL; //prev cell avant temp

    while (temp != NULL && temp->value <= cell->value) {
        prev = temp;
        temp = temp->arrayNexts[level];
    }
    if (prev == NULL) {
        cell->arrayNexts[level] = list->arrayHeads[level];
        list->arrayHeads[level] = cell;
    } else {
        prev->arrayNexts[level] = cell;
        cell->arrayNexts[level] = temp;
    }
}


Cell *searchForOneLevel(List *list, int value) {
    Cell *current = list->arrayHeads[0]; // current check la valeur qu'on veut (i)
    while (current != NULL) {
        if (current->value == value) {
            return current;
        } else {
            current = current->arrayNexts[0];
        }
    }
    return NULL;
}


Cell *searchValue(List *list, int value) {
    int lvl = list->nbLevels - 1;//
    Cell *previous = NULL;
    Cell *current;
    while (lvl >= 0) {// permet lorsqu'on descend d'un niveau reprenne là où on s'est arreté
        if (previous != NULL) {
            current = previous->arrayNexts[lvl];
        } else {
            current = list->arrayHeads[lvl];
        }
        while (current != NULL) {
            if (current->value > value) {// on à dépasser la valeur qu'on recherche
                current = NULL;
            } else if (current->value == value) {
                return current;
            } else {  // current->value < value
                previous = current;
                current = current->arrayNexts[lvl];
            }
        }
        lvl -= 1;
    }
    return NULL;
}
