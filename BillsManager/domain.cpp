//
// Created by lazab on 5/24/2024.
//

#include "domain.h"

domain::bill::bill() {
    this->name="";
    this->number="";
    this->sum=0;
    this->paid=false;
}

domain::bill::bill(std::string &name, std::string &number, double sum, bool paid):name{name}, number{number}, sum{sum}, paid{paid} {
    this->name=name;
    this->number=number;
    this->sum=sum;
    this->paid=paid;
}

domain::bill &domain::bill::operator=(const domain::bill &bill)
{
    if (this == &bill)
        return *this;

    this->name = bill.name;
    this->number=bill.number;
    this->sum=bill.sum;
    this->paid=bill.paid;

    return *this;
}

std::string domain::bill::get_name() {
    return this->name;
}

std::string domain::bill::get_number() {
    return this->number;
}

double domain::bill::get_sum() const {
    return this->sum;
}

bool domain::bill::get_paid() const {
    return this->paid;
}
