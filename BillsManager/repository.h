//
// Created by lazab on 5/24/2024.
//

#ifndef TEST3_BILLS_REPOSITORY_H
#define TEST3_BILLS_REPOSITORY_H
#include <vector>
#include "domain.h"

class repository {
private:
    std::vector<domain::bill> bills{};

public:
    repository();

    std::vector<domain::bill> get_all();

    void add(domain::bill &b);

    void read();
};


#endif //TEST3_BILLS_REPOSITORY_H
