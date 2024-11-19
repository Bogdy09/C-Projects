//
// Created by lazab on 3/15/2024.
//
#include "domain.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Vacation * createVacation(char* type, char* destination, int day, int month, int year, int price)
{

    Vacation * v = malloc(sizeof(Vacation));
    if (v == NULL)
        return NULL;

    strcpy(v->type, type);
    strcpy(v->destination, destination);
    v->dep_date.day = day;
    v->dep_date.month = month;
    v->dep_date.year = year;
    v->price = price;

    return v;
}

Vacation *copyVacation(Vacation *v) {
    Vacation *copy = malloc(sizeof(Vacation));
    if (copy == NULL) {
        return NULL;
    }
    memcpy(copy, v, sizeof(Vacation));
    return copy;
}

void destroyVacation(Vacation *v) {
    free(v);
}

char* getType(Vacation * v)
{
    if (v == NULL)
        return NULL;
    return v->type;
}

char* getDestination(Vacation * v)
{
    if (v == NULL)
        return NULL;
    return v->destination;
}

time getDepDate(Vacation * v)
{
    return v->dep_date;
}

int getPrice(Vacation* v){
    if (v == NULL)
        return -1;
    return v->price;
}
