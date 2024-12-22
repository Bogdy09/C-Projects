//
// Created by lazab on 3/31/2024.
//

#ifndef SCHOOL_TEST1_REPOSITORY_H
#define SCHOOL_TEST1_REPOSITORY_H
#include "dynamic_array.h"
#include "domain.h"

class repository {
    dynamic_array<domain::school> *schools;
public:
    explicit repository(dynamic_array<domain::school> *repo);
    int get_size();
    domain::school * get_vector();
    void remove_repo(int index);
    void input();
    void add_repo(domain::school &s);
};


#endif //SCHOOL_TEST1_REPOSITORY_H
