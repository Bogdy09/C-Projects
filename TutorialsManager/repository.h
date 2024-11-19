//
// Created by lazab on 3/22/2024.
//

#ifndef OOP_A4_5_BOGDY09_REPOSITORY_H
#define OOP_A4_5_BOGDY09_REPOSITORY_H
#include "domain.h"
#include "Dynamicvector.h"
#include <vector>

class repository {
private:
    std::vector<domain::Tutorial> tutorials{};
    std::vector<domain::Tutorial> watch_list{};


public:
    explicit repository();
    void writeToFile();
    void readFromFile();
    void add_repo(domain::Tutorial &t);
    std::vector<domain::Tutorial> get_all_repo();
    int get_size_repo();
    int get_cap_repo();
    void initialize_repo();
    void delete_repo(int index);
    void update_repo(int index, domain::Tutorial &t);
    void add_repo1(domain::Tutorial &t);
    int get_size_repo1();
    std::vector<domain::Tutorial> get_all_repo1();
    void delete_repo1(int index);
};


#endif //OOP_A4_5_BOGDY09_REPOSITORY_H
