//
// Created by lazab on 3/15/2024.
//
#include "dynamic_array.h"
#include "repository.h"
//#include "services.h"
void addVacation(VacationVector * v, Vacation * vac){
    add_vacation(v, vac);
}

void deleteVacation(VacationVector * v, char* destination){
    delete_vacation(v, destination);
}

void add_initial_vacations(VacationVector *vector) {
    Vacation vacation1 = {"Beach", "Sunset Beach", {2025, 1, 1}, 500};
    Vacation vacation2 = {"Mountain", "Rocky Mountains", {2025, 2, 15}, 800};
    Vacation vacation3 = {"City", "New York City", {2024, 3, 10}, 1000};
    Vacation vacation4 = {"Beach", "Palm Beach", {2020, 4, 26}, 600};
    Vacation vacation5 = {"Mountain", "Alps", {2021, 10, 25}, 900};

    add_vacation(vector, &vacation1);
    add_vacation(vector, &vacation2);
    add_vacation(vector, &vacation3);
    add_vacation(vector, &vacation4);
    add_vacation(vector, &vacation5);
}

