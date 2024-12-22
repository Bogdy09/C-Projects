//
// Created by lazab on 5/24/2024.
//

#include "repository.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

repository::repository() {
    this->bills=std::vector<domain::bill>();
}

std::vector<domain::bill> repository::get_all() {
    return this->bills;
}

void repository::add(domain::bill &b) {
    this->bills.push_back(b);
}

void repository::read() {

    std::ifstream file("read.txt");
    if (!file) {
        std::ofstream outfile("read.txt");
        outfile.close();
        file.open("read.txt");
    }
    domain::bill b;
    this->bills.clear();
    while(file>>b) {
        cout<<"h";
        this->add(b);
    }
}


