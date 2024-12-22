//
// Created by lazab on 5/26/2024.
//

#include "repository.h"
#include <fstream>
#include <iostream>
using namespace std;

repository::repository() {
    this->items=std::vector<item>();
}

std::vector<item> repository::get_all() {
    return this->items;
}

void repository::read() {
    std::ifstream file("read.txt");
    if(!file){
        std::ofstream outfile;
        outfile.close();
        file.open("read.txt");
    }
    item i;
    this->items.clear();
    while(file>>i)
        this->items.push_back(i);
}

