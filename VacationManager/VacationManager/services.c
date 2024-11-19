//
// Created by lazab on 3/15/2024.
//
#include "domain.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int check_date_and_destination(VacationVector *vector, char destination[], int day, int month, int year) {
    int k = 0;
    for (int j = 0; j < vector->size; j++) {
        if ((strcmp(destination, vector->data[j].destination) == 0) ||
            ((day == vector->data[j].dep_date.day) &&
             (month == vector->data[j].dep_date.month) &&
             (year == vector->data[j].dep_date.year))) {
            k++;

        }
    }
    return k;
}




int is_substring(const char *haystack, const char *needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if (nlen > hlen) return 0;
    for (int i = 0; i <= hlen - nlen; i++) {
        int j;
        for (j = 0; j < nlen; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == nlen) return 1; // found substring
    }
    return 0; // substring not found
}


int find_and_sort(VacationVector *vector, char string[], int* k, VacationVector *list) {
    for (int i = 0; i < vector->size; i++) {
        char destination[50];
        strcpy(destination, vector->data[i].destination);
        int day, month, year, price;
        day = vector->data[i].dep_date.day;
        month = vector->data[i].dep_date.month;
        year = vector->data[i].dep_date.year;
        price = vector->data[i].price;

        if (is_substring(destination, string)) {
            if (list->size >= list->cap) {
                resize(list, list->cap * 2);
            }
            strcpy(list->data[*k].type, vector->data[i].type);
            strcpy(list->data[*k].destination, vector->data[i].destination);
            list->data[*k].dep_date.day = day;
            list->data[*k].dep_date.month = month;
            list->data[*k].dep_date.year = year;
            list->data[*k].price = price;
            (*k)++;
        }
    }

    if (*k == 0) {
        return 0;
    } else {
        // Sorting the list based on price
        for (int i = 0; i < *k - 1; i++) {
            for (int j = i + 1; j < *k; j++) {
                if (list->data[i].price > list->data[j].price) {
                    Vacation temp = list->data[i];
                    list->data[i] = list->data[j];
                    list->data[j] = temp;
                }
            }
        }
    }

    return 1;
}

VacationVector find_by_type(VacationVector *vector, char type[]){
    VacationVector list;
    init_vector(&list);
    for(int i=0;i<vector->size;i++){
        if(strcmp(vector->data[i].type,type)==0){
            if (list.size >= list.cap) {
                resize(&list, list.cap * 2);
            }
            list.data[list.size++]=vector->data[i];
        }
    }
    return list;
}

VacationVector after_date(VacationVector *vector, int day, int month, int year){
    VacationVector list;
    init_vector(&list);
    for(int i=0;i<vector->size;i++){
        if(vector->data[i].dep_date.year>year) {
            list.data[list.size++] = vector->data[i];
        }
        else {
            if (vector->data[i].dep_date.year == year) {
                if (vector->data[i].dep_date.month > month) {
                    list.data[list.size++] = vector->data[i];
                } else {
                    if (vector->data[i].dep_date.day >= day)
                        list.data[list.size++] = vector->data[i];
                }
            }
        }
    }
    return list;
}





void test_find_by_type(VacationVector *vector, const char *type) {
    VacationVector type_vacations = find_by_type(vector, type);
    for (int i = 0; i < type_vacations.size; i++) {
        assert(strcmp(type_vacations.data[i].type, type) == 0);
    }
    free_vector(&type_vacations);
}
void test_after_date(VacationVector *vector, int day, int month, int year) {
    VacationVector after_date_vacations = after_date(vector, day, month, year);
    for (int i = 0; i < after_date_vacations.size; i++) {
        Vacation *vacation = &after_date_vacations.data[i];
        assert(vacation->dep_date.year > year ||
               (vacation->dep_date.year == year && vacation->dep_date.month > month) ||
               (vacation->dep_date.year == year && vacation->dep_date.month == month && vacation->dep_date.day >= day));
    }
    free_vector(&after_date_vacations);
}