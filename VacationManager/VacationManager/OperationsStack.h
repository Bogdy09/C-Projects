//
// Created by lazab on 3/18/2024.
//

#ifndef A2_3_BOGDY09_OPERATIONSSTACK_H
#define A2_3_BOGDY09_OPERATIONSSTACK_H
#pragma once
#include "domain.h"
#include "dynamic_array.h"

#include <string.h>


typedef struct {
    VacationVector *vector;
    Vacation deleted_vacation; // vacation after update
    Vacation updated_vacation;
    Vacation old_vacation; // vacation before update
    int index;
    int is_add_operation; // for addition and deletion
    int is_update_operation; // for update
} Operation;





typedef struct {
    Operation *stack;
    int size;
    int cap;
    Operation *redo_stack; // New redo stack
    int redo_size;
    int redo_cap;
    Vacation updated_vacation;
} OperationsStack;

void push(Operation *stack, VacationVector *vector, Vacation *vacation, int operation_type);
void undo(Operation *stack, Vacation *updated_destination);
void init_stack(OperationsStack *stack);
void resize_stack(OperationsStack *stack, int new_cap);
void push_stack(OperationsStack *stack, Operation *operation);
Operation pop_stack(OperationsStack *stack);
int find_destination_index(VacationVector *vector, const char *destination);
void push_redo_stack(OperationsStack *stack, Operation *operation);
void redo(OperationsStack *stack);
void free_stack(OperationsStack *stack);

#endif //A2_3_BOGDY09_OPERATIONSSTACK_H
