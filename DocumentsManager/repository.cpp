//
// Created by lazab on 5/25/2024.
//

#include "repository.h"
#include <iostream>
#include <fstream>

repository::repository() {
    this->searches=std::vector<search>();
}

void repository::read() {
    std::ifstream file("read.txt");
    if (!file) {
        std::ofstream outfile("read.txt");
        outfile.close();
        file.open("read.txt");
    }
    search s;
    this->searches.clear();
    while(file>>s)
        this->searches.push_back(s);
}

std::vector<search> repository::get_all() {
    return this->searches;
}




