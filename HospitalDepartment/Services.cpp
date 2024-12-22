//
// Created by lazab on 4/21/2024.
//

#include "Services.h"
#include <fstream>

void Services::addDepartment(HospitalDepartment *d) {
    this->dep.push_back(d);
}

std::vector<HospitalDepartment *> Services::getAllDepartments() {
    return this->dep;
}

std::vector<HospitalDepartment *> Services::getAllEfficientDepartments() {
    auto all=this->getAllDepartments();
    std::vector<HospitalDepartment*> d;
    for(auto i:all){
        if(i->isEfficient())
            d.push_back(i);
    }
    return d;
}

void Services::writeToFile() {
    std::ofstream file("departments.txt", std::ios::trunc);
    for(auto a:getAllDepartments()) {
        if(a->isEfficient())
            file << a->toString()+" Efficient" << '\n';
        else
            file << a->toString()+" Not efficient" << '\n';
    }
}
