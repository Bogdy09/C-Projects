//
// Created by lazab on 5/27/2024.
//

#include "repository.h"
#include <fstream>

repository::repository() {
    this->tasks=std::vector<task>();
}

std::vector<task> repository::get_all() {
    return this->tasks;
}

void repository::read() {
    std::ifstream file("read.txt");
    if(!file){
        std::ofstream outfile;
        outfile.close();
        file.open("read.txt");
    }
    task t;
    this->tasks.clear();
    while(file>>t) {
        this->tasks.push_back(t);
    }
}

