//
// Created by lazab on 4/22/2024.
//

#include "real_estate_agency.h"
#include <iostream>
using namespace std;
#include <fstream>

void real_estate_agency::addDwelling(double price, bool profitable) {
    auto dwelling=new Dwelling(price, profitable);
    this->d.push_back(dwelling);
}

void real_estate_agency::removeClient(std::string name) {
    int k=0;
    for(auto i:getAllClients()){
        if(i->getName()==name)
            this->c.erase(this->c.begin()+k);
        k++;
    }
}

std::vector<client *> real_estate_agency::getInterestedClients(Dwelling d) {
    std::vector<client*> all;
    for(auto i:getAllClients()){
        if(i->isInterested(d))
            all.push_back(i);
    }
    return all;
}

void real_estate_agency::writeToFile(std::string filename) {
    std::ofstream file(filename, std::ios::trunc);
    for(auto i:getAllClients())
        file<<i->toString()<<'\n';
}

std::vector<client *> real_estate_agency::getAllClients() {
    return this->c;
}

void real_estate_agency::add_client() {
    this->c.push_back((new Person("James", 1200.0)));
    this->c.push_back((new Person("Mike", 2345.0)));
    this->c.push_back((new Company("Marta", 1200.0, 2345.0)));
    this->c.push_back((new Company("Sofia", 3400.0, 21275.0)));
}

std::vector<Dwelling *> real_estate_agency::getAllDwellings() {
    return this->d;
}
