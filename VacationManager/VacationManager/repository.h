//
// Created by lazab on 3/16/2024.
//
#include "dynamic_array.h"
#define MAX_UNDO_REDO_STACK_SIZE 100
#ifndef A2_3_BOGDY09_REPOSITORY_H
#define A2_3_BOGDY09_REPOSITORY_H

#pragma once
#include "domain.h"
#include "dynamic_array.h"

typedef struct
{
    VacationVector * vacations;
} VacationRepo;

/// <summary>
/// Creates a PlanetRepo.
/// </summary>
VacationRepo * createRepo();

/// <summary>
/// Destroys a given planet repository. The memory is freed.
/// </summary>
void destroyRepo(VacationRepo * v);

/// <summary>
/// Finds the planet with the given name.
/// </summary>
/// <param name="v">Pointer to the PlanetRepo.</param>
/// <param name = "symbols">A string, the name to search for.</param>
/// <returns>The pointer to the planet with the given name, or null, if such a planet does not exist.</returns>
Vacation * find(VacationRepo * v, char* name);


/*
	Adds a vacation to the repository of vacations.
	Input:	- v - pointer to the VacationRepo
			- vac - vacation
	Output: 1 - if the vacation was sucessfully added
			0 - if the vacation could not be added
*/
void addVacation(VacationVector * v, Vacation * vac);

/*
	Deletes the vacation with the given destination from the repository.
	Input:  - v - pointer to the VacationRepo
			- destination - a string, the destination which identifies the vacation to be deleted.
	Output: If a vacation with the given destination exists in the repository, it is deleted.
*/
void deleteVacation(VacationVector * v, char* destination);
void add_initial_vacations(VacationVector *vector);




        void testsPlanetRepo();
#endif //A2_3_BOGDY09_REPOSITORY_H
