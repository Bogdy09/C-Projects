//
// Created by lazab on 3/16/2024.
//
#include "dynamic_array.h"
#include "services.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>



void init_vector(VacationVector *vector){
    vector->size=0;
    vector->cap=1;
    vector->data = malloc(sizeof(Vacation) * vector->cap);
}

void resize(VacationVector *vector, int new_cap) {
    // Allocate memory for the new array
    Vacation *new_data = malloc(new_cap * sizeof(Vacation));
    if (new_data == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < vector->size; i++) {
        new_data[i] = vector->data[i];
    }

    free(vector->data);

    vector->data = new_data;
    vector->cap = new_cap;
}

void add_vacation(VacationVector *vector, Vacation *vacation) {
    if (vector->size >= vector->cap) {
        int new_cap = vector->cap * 2;
        resize(vector, new_cap);
    }
    if(check_date_and_destination(vector, vacation->destination, vacation->dep_date.day, vacation->dep_date.month, vacation->dep_date.year)==0){
        vector->data[vector->size++] = *vacation;
    }
    else{
        printf("Invalid input!\n");
    }
}

void delete_vacation(VacationVector *vector, char destination[]) {
    if (vector->size >= vector->cap) {
        int new_cap = vector->cap * 2;
        resize(vector, new_cap);
    }
    for (int i = 0; i < vector->size; i++) {
        if (strcmp(vector->data[i].destination, destination) == 0) {
            for (int j = i; j < vector->size - 1; j++) {
                vector->data[j] = vector->data[j + 1];
            }
            vector->size--;
            break;
        }
    }
}

    void free_vector(VacationVector *vector) {
        free(vector->data);
        vector->data = NULL;
        vector->size = 0;
        vector->cap = 1;
    }



/*void test_add_vacation() {
    VacationVector vector;
    init_vector(&vector);

    // Add a new vacation
    Vacation *vacation1 = createVacation("Beach", "Maldives", 15, 7, 2024, 2000);
    add_vacation(&vector, vacation1);
    assert(vector.size == 1);

    // Add a vacation with an existing destination (should fail)
    Vacation *vacation2 = createVacation("Mountains", "Maldives", 20, 7, 2024, 2500);
    add_vacation(&vector, vacation2);
    assert(vector.size == 1); // Size should remain the same

    // Clean up
    free_vector(&vector);
}*/

void test_delete_vacation() {
    VacationVector vector;
    init_vector(&vector);

    Vacation *vacation1 = createVacation("Beach", "Maldives", 15, 7, 2024, 2000);
    Vacation *vacation2 = createVacation("Mountains", "Switzerland", 20, 7, 2024, 2500);
    add_vacation(&vector, vacation1);
    add_vacation(&vector, vacation2);

    delete_vacation(&vector, "Maldives");
    assert(vector.size == 1);

    delete_vacation(&vector, "Hawaii");
    assert(vector.size == 1); // Size should remain the same

    free_vector(&vector);
}
//crtcheckmemory