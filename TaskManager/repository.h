//
// Created by lazab on 5/27/2024.
//

#ifndef TEST3_TASK_MANAGER_REPOSITORY_H
#define TEST3_TASK_MANAGER_REPOSITORY_H
#include "domain.h"
#include <vector>

class repository {
private:
    std::vector<task> tasks;

public:
    repository();

    std::vector<task> get_all();

    void read();
};


#endif //TEST3_TASK_MANAGER_REPOSITORY_H
