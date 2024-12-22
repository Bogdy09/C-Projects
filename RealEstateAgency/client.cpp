//
// Created by lazab on 4/22/2024.
//

#include "client.h"

double client::totalIncome() {
    return this->income;
}

std::string client::toString() {
    return "Name: "+this->name+" Income: "+std::to_string(this->income);
}

std::string client::getName() {
    return this->name;
}

bool Person::isInterested(Dwelling d) {
    return d.getPrice()/1000<=this->income;
}

std::string Person::getName() {
    return this->name;
}

std::string Person::toString() {
    return client::toString()+"Name: "+this->name+" Income: "+std::to_string(this->income);
}

double Company::totalIncome() {
    return this->income+this->money;
}

std::string Company::toString() {
    return "Name: "+this->name+" Income: "+std::to_string(totalIncome());
}

bool Company::isInterested(Dwelling d) {
    return d.getPrice()/100<=totalIncome() && d.isProfitable();
}

std::string Company::getName() {
    return this->name;
}
