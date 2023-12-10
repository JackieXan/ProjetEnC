//
// Created by cassie on 01/12/2023.
//

#ifndef PROJETENC_AGENDA_H
#define PROJETENC_AGENDA_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Contact {
    char *nom;
    char *prenom;
} Contact;

typedef struct Date {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct Time {
    int heure;
    int minute;
} Time;

typedef struct Rdv {
    char *name;
    Date *date;
    Time time;
    Time duration;
    struct Rdv *next;
} Rdv;

typedef struct RdvList {
    Rdv *first;
} RdvList;

typedef struct AgendaEntry {
    Contact *contact;
    RdvList *rdvList;
    int level;
    struct AgendaEntry **arrayNexts;
} AgendaEntry;


typedef struct Agenda {
    int nbLevels;
    AgendaEntry **arrayHeads;
} Agenda;

char *scanString();

void lowercase(char *str);

Contact *createNewContact();

Contact *createContact(char *nom, char *prenom);

void printContact(Contact *contact);

Date *createDate();

void printDate(Date date);

Time *createTime();

void printTime(Time time);

int checkTime(Time *time);

Rdv *createRdv();

void printRdv(Rdv rdv);

int checkDate(Date *date);

Agenda *initAgenda(int nbLevels);

AgendaEntry *createAgendaEntry(Contact *contact, RdvList *rdvList);

void printRdvContact(Agenda *agenda, char *nom, char *prenom);

AgendaEntry *searchAgendaEntry(Agenda *agenda, char *nom, char *prenom);

void linkNewCellInAgenda(Agenda *agenda, AgendaEntry *cell);

#endif //PROJETENC_AGENDA_H
