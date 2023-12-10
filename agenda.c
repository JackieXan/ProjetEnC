//
// Created by cassie on 01/12/2023.
//

#include "agenda.h"
#include <ctype.h>

char *scanString(void) {
    char *input = (char *) malloc(100 * sizeof(char));// Alloue de la mémoire pour stocker la chaîne
    scanf("%s", input);

    int len = (int) strlen(input); // Calcule la taille de la string

    char *string = (char *) malloc(
            (len) * sizeof(char)); // Alloue de la mémoire pour stocker la taille exacte de la chaîne
    strcpy(string, input);
    free(input); // Supprime l'ancien input pour libérer l'espace
    input = NULL;

    return string;
}

void lowercase(char *str) {
    // for (int i = 0; i < strlen(str); ++i) {
    //     str[i] = (char) ((str[i]) | (char) 0x20);
    // }
    // des bisous, pol (oui il m'a aidé merci à lui)
    // using the real lowercase function
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = (char) tolower(str[i]);
    }
}

Contact *createNewContact(void) {
    Contact *contact;
    printf("Saisissez le nom :\n> ");
    char *prenom = scanString();
    lowercase(prenom);
    printf("\n");
    printf("Saisissez le prenom :\n> ");
    char *nom = scanString();
    lowercase(nom);
    contact = createContact(nom, prenom);
    return contact;
}

Contact *createContact(char *nom, char *prenom) {
    Contact *contact = malloc(sizeof(Contact));
    contact->nom = nom;
    contact->prenom = prenom;
    return contact;
}

void printContact(Contact *contact) {
    printf("Contact: %s %s\n", contact->nom, contact->prenom);
}

Date *createDate() {
    Date *date = (Date *) malloc(sizeof(Date));
    do {
        printf("Saisissez le jour :\n> ");
        scanf("%d", &date->jour);
        printf("\n");
        printf("Saisissez le mois :\n> ");
        scanf("%d", &date->mois);
        printf("\n");
        printf("Saisissez l'annee :\n> ");
        scanf("%d", &date->annee);
        printf("\n");
    } while (!checkDate(date));
    return date;
}

void printDate(Date date) {
    printf("Date: %d/%d/%d\n", date.jour, date.mois, date.annee);
}

Time *createTime() {
    Time *time = (Time *) malloc(sizeof(Time));
    do {
        printf("Saisissez l'heure :\n> ");
        scanf("%d", &time->heure);
        printf("\n");
        printf("Saisissez les minutes :\n> ");
        scanf("%d", &time->minute);
        printf("\n");
    } while (!checkTime(time));
    return time;
}

void printTime(Time time) {
    printf("Time: %d:%d\n", time.heure, time.minute);
}

Rdv *createRdv(void) {
    Rdv *rdv = (Rdv *) malloc(sizeof(Rdv));
    printf("Saisissez le nom du rendez-vous :\n> ");
    rdv->name = scanString();
    printf("\n");
    printf("Saisissez la date du rendez-vous :\n> ");
    rdv->date = createDate();
    printf("\n");
    printf("Saisissez l'heure du rendez-vous :\n> ");
    rdv->time = *createTime();
    printf("\n");
    printf("Saisissez la durée du rendez-vous :\n> ");
    rdv->duration = *createTime();
    printf("\n");
    return rdv;
}

void printRdv(Rdv rdv) {
    printf("Rendez-vous: %s\n", rdv.name);
    printDate(*rdv.date);
    printTime(rdv.time);
    printTime(rdv.duration);
}

int checkDate(Date *date) {
    if ((date->jour >= 29) && (date->mois == 02)) {
        if ((date->annee % 4 != 0) || ((date->annee % 4 == 0) && (date->annee % 100 == 0))) {
            return 0;
        }
    }
    if ((date->jour == 31) &&
        ((date->mois == 2) || (date->mois == 4) || (date->mois == 6) || (date->mois == 9) || (date->mois == 11))) {
        return 0;
    }
    if ((date->jour > 31) || (date->mois > 12) || (date->annee < 2023) || (date->jour < 0) || (date->mois < 0) ||
        (date->annee < 0)) {
        return 0;
    }
    return 1;
}

int checkTime(Time *time) {
    if ((time->heure > 23) || (time->heure < 0) || (time->minute > 59) || (time->minute < 0)) {
        return 0;
    }
    return 1;
}

AgendaEntry *createAgendaEntry(Contact *contact, RdvList *rdvList) {
    AgendaEntry *agendaEntry = (AgendaEntry *) malloc(sizeof(AgendaEntry));
    agendaEntry->contact = contact;
    agendaEntry->rdvList = rdvList;
    agendaEntry->arrayNexts = (AgendaEntry **) malloc(sizeof(AgendaEntry *) * 4);
    for (int i = 0; i < 4; ++i) {
        agendaEntry->arrayNexts[i] = NULL;
    }
    return agendaEntry;
}

//void linkNewCellInAgenda(Agenda * agenda, AgendaEntry * agendaEntry) {
//    // on pas réussi a la faire fonctionner
//    // en gros a la fin ca se link pas comme il faut
//    /* Works the following way:
//    * On level 4, we link cells if first letter of contact's name is different
//    * On level 3, we link cells if second letter of contact's name is different
//    * On level 2, we link cells if third letter of contact's name is different
//    * On level 1, every cell are linked
//    * */
//    // if list null
//    if (agenda->arrayHeads[0] == NULL) {
//        agendaEntry->level = 4;
//        agenda->arrayHeads[0] = agendaEntry;
//        agenda->arrayHeads[1] = agendaEntry;
//        agenda->arrayHeads[2] = agendaEntry;
//        agenda->arrayHeads[3] = agendaEntry;
//        return;
//    }
//    char * nameB = agendaEntry->contact->nom;
//    AgendaEntry *current;
//    AgendaEntry * FOUND[3] = {NULL, NULL, NULL};
//    AgendaEntry * FOUNDprev[3] = {NULL, NULL, NULL};
//    int done = 0;
//    for (int lvl = 0; lvl < 3; ++lvl) {
//        if (lvl == 0 || FOUND[lvl - 1] == NULL) {
//            current = agenda->arrayHeads[lvl];
//        } else {
//            current = FOUND[lvl - 1];
//        }
//        done = 0;
//        while (current != NULL && !done) {
//            char * nameA = current->contact->nom;
//            if (strncmp(nameA, nameB, lvl + 1) < 0) {
//                FOUNDprev[lvl] = current;
//                current = current->arrayNexts[lvl] != NULL ? current->arrayNexts[lvl] : NULL;
//            } else if (strncmp(nameA, nameB, lvl + 1) == 0) {
//                FOUND[lvl] = current;
//                done = 1;
//            } else {
//                done = 1;
//                lvl = 2;
//            }
//        }
//    }
//
//    int foundCount = 0;
//    for (int i = 0; i < 3; ++i) {
//        if (FOUND[i] != NULL) {
//            foundCount++;
//        } else {
//            break;
//        }
//    }
//
//    if (foundCount == 3) {
//        if (strcmp(FOUND[2]->contact->nom, nameB) < 0) {
//            // no switch
//            agendaEntry->level = 1;
//            // link
//            agendaEntry->arrayNexts[0] = FOUND[2]->arrayNexts[0];
//            FOUND[2]->arrayNexts[0] = agendaEntry;
//        } else {
//            // switch
//            agendaEntry->level = 1;
//            // switch contact
//            Contact * tempContact = FOUND[2]->contact;
//            FOUND[2]->contact = agendaEntry->contact;
//            agendaEntry->contact = tempContact;
//            // switch rdvList
//            RdvList * tempRdvList = FOUND[2]->rdvList;
//            FOUND[2]->rdvList = agendaEntry->rdvList;
//            agendaEntry->rdvList = tempRdvList;
//            // link
//            agendaEntry->arrayNexts[0] = FOUND[2]->arrayNexts[0];
//            FOUND[2]->arrayNexts[0] = agendaEntry;
//        }
//    } else {
//        if (FOUNDprev[foundCount] == NULL) {
//            // list head
//            AgendaEntry ** tempNextCell = malloc(sizeof(AgendaEntry *) * 4);
//            for (int i = 0; i < 4; ++i) {
//                tempNextCell[i] = agenda->arrayHeads[i];
//            }
//            agendaEntry->level = 4;
//            // link list head & next
//            for (int i = 0; i < 4; ++i) {
//                agenda->arrayHeads[i] = agendaEntry;
//                agendaEntry->arrayNexts[i] = tempNextCell[i];
//            }
//            // resize the old head
//            /*
//            for (int i = 3 - foundCount; i < 4; ++i) {
//                tempNextCell[i]->arrayNexts[i] = NULL;
//            }*/
//
//        } else {
//            // dupe
//            AgendaEntry  ** tempNextCell = malloc(sizeof(AgendaEntry *) * 4);
//            for (int i = 0; i < FOUNDprev[foundCount]->level; ++i) {
//                tempNextCell[i] = FOUNDprev[foundCount]->arrayNexts[i];
//            }
//            // link last cell and current
//            for (int i = 0; i < 4; i++) {
//                FOUNDprev[foundCount]->arrayNexts[i] = agendaEntry;
//                agendaEntry->arrayNexts[i] = tempNextCell[i];
//            }
//            // resize the old last and current
//            for (int i = FOUNDprev[foundCount]->level; i < 4; ++i) {
//                agendaEntry->arrayNexts[i] = NULL;
//            }
//            for (int i = foundCount; i < 4; ++i) {
//                tempNextCell[i]->arrayNexts[i] = NULL;
//            }
//        }
//    }
//}


AgendaEntry *searchAgendaEntry(Agenda *agenda, char *nom, char *prenom) {
    // based on Cell *searchValue
    lowercase(nom);
    lowercase(prenom);
    AgendaEntry *previous = NULL;
    AgendaEntry *current;
    int lvl = 4;
    char *nameB = malloc(strlen(nom) + strlen(prenom) + 2);
    // nameB = nom_prenom;
    strcpy(nameB, nom);
    strcat(nameB, "_");
    strcat(nameB, prenom);
    while (lvl >= 0) {
        if (previous != NULL) {
            current = previous->arrayNexts[lvl];
        } else {
            current = agenda->arrayHeads[lvl];
        }
        while (current != NULL) {
            char *nameA = malloc(strlen(current->contact->nom) + strlen(current->contact->prenom) + 2);
            strcpy(nameA, current->contact->nom);
            strcat(nameA, "_");
            strcat(nameA, current->contact->prenom);
            if (strcmp(nameA, nameB) > 0) {
                current = NULL;
            } else if (strcmp(nameA, nameB) == 0) {
                free(nameB);
                free(nameA);
                return current;
            } else {  // current->value < value
                previous = current;
                current = current->arrayNexts[lvl];
            }
            free(nameA);
        }
        lvl -= 1;
    }
    free(nameB);
    return NULL;
}


void printRdvContact(Agenda *agenda, char *nom, char *prenom) {
    lowercase(nom);
    lowercase(prenom);
    AgendaEntry *agendaEntry = searchAgendaEntry(agenda, nom, prenom);
    if (agendaEntry == NULL) {
        printf("Contact non trouvé\n");
        return;
    }
    RdvList *rdvList = agendaEntry->rdvList;
    Rdv *rdv = rdvList->first;
    while (rdv != NULL) {
        printRdv(*rdv);
        rdv = rdv->next;
    }
}


Agenda *initAgenda(int nbLevels) {
    Agenda *agenda = (Agenda *) malloc(sizeof(Agenda));
    agenda->nbLevels = nbLevels;
    agenda->arrayHeads = (AgendaEntry **) malloc(sizeof(AgendaEntry *) * nbLevels);
    for (int i = 0; i < nbLevels; ++i) {
        agenda->arrayHeads[i] = NULL;
    }
    Contact *contact;
    AgendaEntry *agendaEntry;
    FILE *file = fopen("../list1000.txt", "r");
    if (file == NULL) {
        printf("Erreur d'importation du dictionnaire\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, "\t");
        char *prenom = strtok(NULL, "\t");
        prenom[strlen(prenom) - 1] = '\0';
        // do copies
        name = strdup(name);
        prenom = strdup(prenom);
        lowercase(name);
        lowercase(prenom);
        contact = createContact(name, prenom);
        RdvList *rdvList = (RdvList *) malloc(sizeof(RdvList));
        rdvList->first = NULL;
        agendaEntry = createAgendaEntry(contact, rdvList);
        linkNewCellInAgenda(agenda, agendaEntry);  // todo: debug
        // not working
    }
    fclose(file);
    return agenda;
}