//
// Created by lazab on 5/26/2024.
//

#ifndef TEST3_SHOPPINGLIST_REPOSITORY_H
#define TEST3_SHOPPINGLIST_REPOSITORY_H
#include "domain.h"
#include <vector>

class repository {
private:
    std::vector<item> items;

public:
    repository();

    std::vector<item> get_all();

    void read();
};


#endif //TEST3_SHOPPINGLIST_REPOSITORY_H
