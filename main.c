//
// Created by cassie on 30/10/2023.
//
#include "list.h"
#include "timer.h"
#include "stdlib.h"

int main() {

    List *myList = createEmptyList(5);
    addHeadToList(myList, 91, 3);
    addHeadToList(myList, 59, 1);
    addHeadToList(myList, 59, 5);
    addHeadToList(myList, 56, 3);
    addHeadToList(myList, 32, 5);
    addHeadToList(myList, 31, 2);
    addHeadToList(myList, 25, 1);
    addHeadToList(myList, 18, 4);

    displayPrettyList(myList);


    int listLevelCount = 3;
    List *newList = createEmptyList(listLevelCount);
    int level;
    int n = 6;
    for (int i = n - 1; i >= 0; i--) {
        int temp = i;
        level = 1;
        while (temp % 2 == 0 && level < listLevelCount) {
            level = level + 1;
            temp = temp / 2;
        }
        addHeadToList(newList, i, level);
    }


    displayPrettyList(newList);

    printf("%d \n", searchValue(newList, 1)->level);

    startTimer();
    for (int i = 0; i < 10000000; i++) {
        int value = rand() % ((1 << n) - 1) + 1;
        searchValue(myList, value);
    }
    stopTimer();
    printf("Temps de recherche : ");
    displayTime();


    return 0;
}