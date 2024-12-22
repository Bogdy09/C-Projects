//
// Created by lazab on 5/25/2024.
//

#ifndef TEST3_SEARCH_ENGINE_REPOSITORY_H
#define TEST3_SEARCH_ENGINE_REPOSITORY_H
#include "domain.h"

class repository {
private:
    std::vector<search> searches{};

public:
    repository();

    void read();

    std::vector<search> get_all();

};


#endif //TEST3_SEARCH_ENGINE_REPOSITORY_H
