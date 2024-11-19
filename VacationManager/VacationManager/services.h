//
// Created by lazab on 3/16/2024.
//

#ifndef A2_3_BOGDY09_SERVICES_H
#define A2_3_BOGDY09_SERVICES_H
#pragma once
#include "repository.h"
#include "OperationsStack.h"

typedef struct
{
    VacationRepo * repo;
    OperationsStack* undoStack;
} Service;

Service* createService(VacationRepo * r, OperationsStack* undoS);
void destroyService(Service* s);

/// <summary>
/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "type">A string, the planet's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the planet to Earth, in light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same symbol already exists.</returns>
int addPlanetServ(Service* s, char* name, char* type, double distanceFromEarth);

VacationRepo * getRepo(Service* s);

/// <summary>
/// Undoes the last performed operation.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <returns>1, if the undo operation could be done, 0 otherwise.</returns>

void free_vector(VacationVector *vector);
int check_date_and_destination(VacationVector *vector, char destination[], int day, int month, int year);
int find_and_sort(VacationVector *vector, char string[], int* k, VacationVector *list);
VacationVector find_by_type(VacationVector *vector, char type[]);
VacationVector after_date(VacationVector *vector, int day, int month, int year);
void test_find_by_type(VacationVector *vector, const char *type);
void test_after_date(VacationVector *vector, int day, int month, int year);
#endif //A2_3_BOGDY09_SERVICES_H
