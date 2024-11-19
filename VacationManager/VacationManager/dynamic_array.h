//
// Created by lazab on 3/16/2024.
//

#ifndef A2_3_BOGDY09_DYNAMIC_ARRAY_H
#define A2_3_BOGDY09_DYNAMIC_ARRAY_H
#pragma once
#include "domain.h"


typedef struct {
    Vacation *data;
    int size;
    int cap;
} VacationVector;


void init_vector(VacationVector *vector);
void resize(VacationVector *vector, int new_cap);
void add_vacation(VacationVector *vector, Vacation *vacation);
void delete_vacation( VacationVector *vector, char destination[]);
void free_vector(VacationVector *vector);
void test_add_vacation();
void test_delete_vacation();

#endif //A2_3_BOGDY09_DYNAMIC_ARRAY_H