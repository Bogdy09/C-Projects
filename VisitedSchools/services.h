//
// Created by lazab on 3/31/2024.
//

#ifndef SCHOOL_TEST1_SERVICES_H
#define SCHOOL_TEST1_SERVICES_H
#include "repository.h"

class services {
    repository *repo;
public:
    explicit services(class repository *repo);
    int remove_services(std::string &name, std::string &coordinates);
    int get_size();
    domain::school* get_all();
    domain::school* sort_by_name();
    static bool isDateLess(const domain::date& date1, const domain::date& date2);
    void change_visit(int index);
};


#endif //SCHOOL_TEST1_SERVICES_H
