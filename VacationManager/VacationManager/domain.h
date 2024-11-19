//
// Created by lazab on 3/15/2024.
//

#ifndef A2_3_BOGDY09_DOMAIN_H
#define A2_3_BOGDY09_DOMAIN_H


typedef struct{
    int year;
    int month;
    int day;
}time;

typedef struct {
    char type[50];
    char destination[50];
    time dep_date;
    int price;
}Vacation;

Vacation * createVacation(char* type, char* destination, int day, int month, int year, int price);
Vacation * copyVacation(Vacation * v);
void destroyVacation(Vacation * v);
#endif