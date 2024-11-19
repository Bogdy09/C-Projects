//
// Created by lazab on 3/18/2024.
//

#include "OperationsStack.h"
#include "domain.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


void push(Operation *stack, VacationVector *vector, Vacation *vacation, int operation_type) {
    stack->vector = vector;
    stack->index = -1;
    if (operation_type == 0) { // If it's a deletion operation
        stack->deleted_vacation = *vacation;
        stack->is_add_operation = 0;
        stack->is_update_operation = 0;
    } else if (operation_type == 1) { // If it's an addition operation
        stack->is_add_operation = 1;
        stack->is_update_operation = 0;
    } else if (operation_type == 2) { // If it's an update operation
        stack->old_vacation = *vacation;

        stack->is_add_operation = 0;
        stack->is_update_operation = 1;
    }
}



int find_destination_index(VacationVector *vector, const char *destination) {
    for (int i = 0; i < vector->size; i++) {
        if (strcmp(vector->data[i].destination, destination) == 0) {
            return i;
        }
    }
    return -1; // Return -1 if destination is not found
}
void undo(Operation *stack, Vacation *updated_destination) {
    if (stack->vector->size == 0) {
        printf("No operations to undo.\n");
        return;
    }

    if (stack->is_add_operation) {
        stack->vector->size = stack->vector->size - 1; // Restore the previous size of the vector
        printf("Undo successful.\n");
    } else if (stack->is_update_operation) {
        int found = find_destination_index(stack->vector, updated_destination);
        if (found != -1) {
            stack->vector->data[found] = stack->old_vacation; // Restore the original vacation
            printf("Undo update successful.\n");
        } else {
            printf("Destination not found.\n");
        }
    } else {
        add_vacation(stack->vector, &(stack->deleted_vacation)); // Add the deleted vacation back
        printf("Undo deletion successful.\n");
    }

}





void init_stack(OperationsStack *stack) {
    stack->size = 0;
    stack->cap = 1;
    stack->stack = malloc(sizeof(Operation) * stack->cap);
    stack->redo_stack = malloc(sizeof(Operation) * stack->redo_cap);;
}

void resize_stack(OperationsStack *stack, int new_cap) {
    stack->stack = realloc(stack->stack, new_cap * sizeof(Operation));
    stack->cap = new_cap;
}

void push_stack(OperationsStack *stack, Operation *operation) {
    if (stack->size >= stack->cap) {
        int new_cap = stack->cap * 2;
        resize_stack(stack, new_cap);
    }
    stack->stack[stack->size++] = *operation;
}

void redo(OperationsStack *stack) {
    if (stack->redo_size == 0) {
        printf("No operations to redo.\n");
        return;
    }

    Operation redo_operation = stack->redo_stack[--stack->redo_size];
    stack->stack[stack->size++] = redo_operation;

    if (redo_operation.is_add_operation) {
        add_vacation(redo_operation.vector, &(redo_operation.deleted_vacation));
        printf("Redo successful.\n");
    } else if (redo_operation.is_update_operation) {
        int found = find_destination_index(redo_operation.vector, redo_operation.updated_vacation.destination);
        if (found != -1) {
            redo_operation.vector->data[found] = redo_operation.updated_vacation;
            printf("Redo update successful.\n");
        } else {
            printf("Destination not found.\n");
        }
    } else {
        int found = find_destination_index(redo_operation.vector, redo_operation.deleted_vacation.destination);
        if (found != -1) {
            for (int i = found; i < redo_operation.vector->size - 1; i++) {
                redo_operation.vector->data[i] = redo_operation.vector->data[i + 1];
            }
            redo_operation.vector->size--;
            printf("Redo deletion successful.\n");
        }
    }
}





Operation pop_stack(OperationsStack *stack) {
    Operation operation = stack->stack[--stack->size];
    return operation;
}
void free_stack(OperationsStack *stack) {
    free(stack->stack);
}