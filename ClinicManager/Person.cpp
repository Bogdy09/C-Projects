//
// Created by lazab on 4/20/2024.
//

#include <fstream>
#include "Person.h"
#include <iostream>
using namespace std;
void Person::addAnalysis(MedicalAnalysis *a) {
    this->analyses.push_back(a);
}

std::vector<MedicalAnalysis*> Person::getAllAnalyses() {
    return this->analyses;
}

void Person::writeToFile(std::vector<MedicalAnalysis*> all) {
    std::ofstream file("date.txt", std::ios::trunc);
    for(auto a:all)
        file<<a->toString()<<'\n';
}

std::vector<MedicalAnalysis *> Person::getAnalysesByMonth(std::string& month) {
    std::vector<MedicalAnalysis*> final;
    for(auto a : this->getAllAnalyses())
        if(a->getDate().substr(5, 2)==month) {
            final.push_back(a);
        }
    return final;
}

bool Person::isIll(std::string &month) {
    auto final= getAnalysesByMonth(month);
    for(auto a:final){
        if(a->isResultOK()==0)
            return true;
    }
    return false;
}








